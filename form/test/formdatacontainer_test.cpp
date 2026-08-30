#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include <formdatacontainer.h>
#include <dataentrylist.h>
#include <datapersister.h>
#include <iostream>
#include <filesystem>

TEST_CASE("FormDataContainer::isTransformation()", "[FormDataContainer]")
{
    FormDataContainer fdc;
    CHECK(!fdc.isTransformation()); // Checks that initial value is false

    for (int i=0;i<=1;i++)
    {
        fdc.setTransformation(i);
        CHECK(fdc.isTransformation()==i); // checks that modification is taken into account
        if(false)
        {
            BENCHMARK("FormDataContainer::isTransformationT") {
                return fdc.setTransformation(i);
            };
        }
    }
}

//! Test if FormDataContainer can serialise its attributes to a DataEntryList
TEST_CASE("FormDataContainer::DataEntryList serialise() const;", "[FormDataContainer]")
{
    FormDataContainer fdc;
    fdc.setTransformation(true);
    DataEntryList del(fdc.serialise());
    CHECK(del.getValue("transformation")=="1");
    CHECK(del.getIndex("transformation")==0);
    CHECK(del.aliasExists("transformation")==true);
    CHECK(del.aliasExists("random")==false);

    size_t s = del.getList().size();
    del.addDataEntry("transformation","0");
    CHECK(del.getValue("transformation")=="0");
    CHECK(del.getList().size()==s);

    std::string newEntryAlias = "newAlias";
    std::string newEntryValue = "newValue";
    del.addDataEntry(newEntryAlias,newEntryValue);
    CHECK(del.getValue(newEntryAlias)==newEntryValue);
    CHECK(del.getList().size()==s+1);

    DataPersister dp(fdc);
    dp.save("TEST_CASE_SAVE.csv");
    CHECK(std::filesystem::exists("TEST_CASE_SAVE.csv"));

    FormDataContainer fdc2;
    fdc2.setTransformation(false);
    DataPersister dp2(fdc2);
    CHECK(fdc2.isTransformation()==false);
    dp2.load("TEST_CASE_SAVE.csv");
    CHECK(fdc2.isTransformation());

    //Need to test loading a csv into a FormDataContainer
}

//! Test if FormDataContainer can deserialise from DataentryList to fill its atributes
TEST_CASE("FormDataContainer::void deserialise(DataEntryList const& del);", "[FormDataContainer]")
{
    DataEntryList del;
    FormDataContainer fdc;
    del.addDataEntry("transformation","1");
    fdc.deserialise(del);
    CHECK(fdc.isTransformation());
}
#endif
