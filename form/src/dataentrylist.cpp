#include "dataentrylist.h"
#include "gvar.h"

DataEntryList::DataEntryList(){}

std::vector<DataEntry> const& DataEntryList::getList() const
{
    return del;
}

std::string DataEntryList::getValue(std::string const& alias) const
{
    size_t index(getIndex(alias));
    if(index < getList().size())
    {
        return getList()[index].value;
    }
    else
    {
        return std::string(nastring);
    }
}

bool DataEntryList::aliasExists(std::string const& alias) const
{
    if(getIndex(alias)<getList().size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

size_t DataEntryList::getIndex(std::string const& alias) const
{
    for(size_t k=0;k<del.size();k++) //to be optimised because the search is costy. Rather Sort the aliases first and the search through them by dichotomy.
    {
        if(del[k].alias==alias)
        {
            return k;
        }
    }
    return del.size();

}

void DataEntryList::addDataEntry(std::string const& alias,std::string const& value)
{
    if(!aliasExists(alias))
    {
        DataEntry de;
        de.alias = alias;
        de.value = value;
        del.push_back(de);
    }
    else
    {
        del[getIndex(alias)].value = value;
    }
}
