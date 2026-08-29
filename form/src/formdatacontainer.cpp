#include "formdatacontainer.h"

FormDataContainer::FormDataContainer()
    :transformation(false){}

bool FormDataContainer::isTransformation()
{
    return transformation;
}

void FormDataContainer::setTransformation(bool value)
{
    transformation = value;
}
