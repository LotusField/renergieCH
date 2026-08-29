#ifndef FORMDATACONTAINER_H
#define FORMDATACONTAINER_H


class FormDataContainer
{
public:
    //! Default MainWindow constructor
    FormDataContainer();

    bool isTransformation();

    void setTransformation(bool value);

private:
    bool transformation;
};

#endif // FORMDATACONTAINER_H
