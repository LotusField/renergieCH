#ifndef FORMDATACONTAINER_H
#define FORMDATACONTAINER_H

#include "dataentrylist.h"

class FormDataContainer
{
public:
    //! Default FormDataContainer constructor
    FormDataContainer();

    //! Gets transformation value
    bool isTransformation() const;

    //! Sets transformation value
    /*!
    Takes the new state as parameters.
        \param value whether the project is a transformation.
    */
    void setTransformation(bool value);

    //! Serialise the input data in the form to generic strings in preparation for the data persister to store them in a file
    DataEntryList serialise() const;

    //! Deserialise the loaded strings data by the data persister to the correct form data container class attribute
    void deserialise(DataEntryList const& del);

private:
    bool transformation;

};

#endif // FORMDATACONTAINER_H
