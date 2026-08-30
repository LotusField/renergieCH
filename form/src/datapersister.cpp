#include "datapersister.h"
#include "gvar.h"

#include <fstream>
#include <iostream>

DataPersister::DataPersister(FormDataContainer& fdc)
    :fdc(fdc)
{}

void DataPersister::load(std::string const& path)
{
    std::ifstream file(path);

    if (!file.is_open())
    {
        return;
    }

    DataEntryList del;
    std::string line;

    while (std::getline(file, line))
    {
        std::size_t separator = line.find(csvDataSeparator);

        if (separator == std::string::npos)
        {
            continue;
        }

        std::string alias = line.substr(0, separator);
        std::string value = line.substr(separator + 1);

        del.addDataEntry(alias, value);
    }

    file.close();

    fdc.deserialise(del);
}

void DataPersister::save(std::string const& path) const
{
    DataEntryList del(fdc.serialise());
    std::ofstream file(path);

    if (!file.is_open())
    {
        std::cerr << "Could not open file for writing: " << path << std::endl;
        return;
    }

    for(const DataEntry& de : del.getList())
    {
        file << de.alias << csvDataSeparator << de.value << '\n';
    }

    file.close();
}
