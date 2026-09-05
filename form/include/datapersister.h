#ifndef DATAPERSISTER_H
#define DATAPERSISTER_H

#include <formdatacontainer.h>

#include <string>

class DataPersister
{
public:
    //! DataPersister constructor. The DataPersister object will act on a specific FormatDataContainer object
    /*!
    Takes a FormatDataContainer as parameter.
        \param fdc is a reference to the FormDataContainer to act on.
    */
    DataPersister(FormDataContainer& fdc);

    //! Loads the data held in a save file to the FormaDataContainer.
    /*!
    Takes the path to the save file as paramter.
        \param path is a constant reference to the path of the save file.
    */
    void load(std::string const& path);

    //! Saves the of the FormDataContainer in a save file.
    /*!
    Takes the path to the save file as paramter.
        \param path is a constant reference to the path of the save file.
    */
    void save(std::string const& path) const;

private:

    //! Reference to the FormDataContainer this DataPersister acts on.
    FormDataContainer& fdc;
};

#endif // DATAPERSISTER_H
