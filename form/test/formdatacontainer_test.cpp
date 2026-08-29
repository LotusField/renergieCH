#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include <formdatacontainer.h>

TEST_CASE("FormDataContainer::isTransformation()", "[FormDataContainer]")
{
    FormDataContainer fdc;

    CHECK(!fdc.isTransformation()); // Checks that initial value is false

    for (int i=0;i<=1;i++)
    {
        fdc.setTransformation(i);
        CHECK(fdc.isTransformation()==i); // checks that modification is taken into account
        BENCHMARK("FormDataContainer::isTransformationT") {
            return fdc.setTransformation(i);
        };
    }
}
#endif
