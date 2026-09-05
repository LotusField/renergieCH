#ifndef DATAENTRYLIST_H
#define DATAENTRYLIST_H

#include <string>
#include <vector>

//! Stores data entry independently of their types as strings
/*!
    \param alias the alias of the entry.
    \param value the value of the entry.
*/
struct DataEntry
{
    std::string alias;
    std::string value;
};

class DataEntryList
{
public:
    //! Default DataentryList constructor.
    DataEntryList();

    //! Gets the value corresponding to a specific alias.
    /*!
    Takes the alias of the corresponding value as parameter.
        \param alias constant reference to the alias.
    */
    std::string getValue(std::string const& alias) const;

    //! Gets the full list of DataEntry.
    std::vector<DataEntry> const& getList() const;

    //! Adds a new entry to the DataEntryList.
    //! If the alias already exists in the list, the corresponding value is overwritten.
    /*!
    Takes the data of the corresponding entry as parameter.
        \param alias constant reference to the alias.
        \param value constant reference to the value.
    */
    void addDataEntry(std::string const& alias,std::string const& value);

    //! Checks whether an alias already exists in the list of data entry.
    //! If the alias already exists in the list, this method returns true, else false.
    /*!
    Takes the alias to check as parameter.
        \param alias constant reference to the alias.
    */
    bool aliasExists(std::string const& alias) const;

    //! Gets the index of a corresponding entry in the data entry list.
    /*!
    Takes the alias of the corresponding entry as parameter.
        \param alias constant reference to the alias.
    */
    size_t getIndex(std::string const& alias) const;

private:
    //! Full list of DataEntry.
    std::vector<DataEntry> del;
};

#endif // DATAENTRYLIST_H
