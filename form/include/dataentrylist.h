#ifndef DATAENTRYLIST_H
#define DATAENTRYLIST_H

#include <string>
#include <vector>

//! Stores data entry independently of their types as strings
struct DataEntry
{
    std::string alias;
    std::string value;
};

class DataEntryList
{
public:
    DataEntryList();

    std::string getValue(std::string const& alias) const;

    std::vector<DataEntry> const& getList() const;

    void addDataEntry(std::string const& alias,std::string const& value);

    bool aliasExists(std::string const& alias) const;

    size_t getIndex(std::string const& alias) const;

private:
    std::vector<DataEntry> del;
};

#endif // DATAENTRYLIST_H
