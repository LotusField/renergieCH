#ifndef DATAPERSISTER_H
#define DATAPERSISTER_H

#include <formdatacontainer.h>

#include <string>

class DataPersister
{
public:
    DataPersister(FormDataContainer& fdc);

    void load(std::string const& path);

    void save(std::string const& path) const;

private:
    FormDataContainer& fdc;
};

#endif // DATAPERSISTER_H
