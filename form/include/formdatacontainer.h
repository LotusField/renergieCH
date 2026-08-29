#ifndef FORMDATACONTAINER_H
#define FORMDATACONTAINER_H


class FormDataContainer
{
public:
    //! Default FormDataContainer constructor
    FormDataContainer();

    //! Gets transformation value
    bool isTransformation();

    //! Sets transformation value
    /*!
    Takes the new state as parameters.
        \param value whether the project is a transformation.
    */
    void setTransformation(bool value);

private:
    bool transformation;
};

#endif // FORMDATACONTAINER_H
