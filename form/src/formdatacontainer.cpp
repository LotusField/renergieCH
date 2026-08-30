#include "formdatacontainer.h"

#include <iostream>
#include <sstream>

FormDataContainer::FormDataContainer()
    :transformation(false){}

bool FormDataContainer::isTransformation() const
{
    return transformation;
}

void FormDataContainer::setTransformation(bool value)
{
    transformation = value;
}

DataEntryList FormDataContainer::serialise() const
{
    DataEntryList del;
    del.addDataEntry("transformation",std::to_string(transformation));
    return del;
}

void FormDataContainer::deserialise(DataEntryList const& del)
{
    std::vector<DataEntry> de(del.getList());
    for(size_t i=0;i<de.size();i++)
    {
        std::string const& a = de[i].alias;
        std::string const& v(de[i].value);

        if (a == "transformation")
        {
            bool b;
            std::istringstream(v) >> b;
            setTransformation(b);
        }
        else
        {
            std::cout << "FormDataContainer::deserialise() did not recognise an alias" << std::endl;
        }
    }
}
