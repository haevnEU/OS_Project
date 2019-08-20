#include "api.h"

API* API::instance = nullptr;

API::API()
{
   // do init stuff
}

API* API::GetInstance()
{
    if (instance == nullptr) {
        instance = new API();
    }
    return instance;
}

void API::setDisk(disk::Disk *disk)
{
    curentDisk = disk;
}
