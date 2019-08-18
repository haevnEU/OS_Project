//
// Created by Leon Heindl on 17.08.2019.
//
#include <Disk.h>
using namespace os_project::Disk;


os_project::Disk::Disk::Disk(unsigned long int storageCapacity, char name) {
    this->storageCapacity = storageCapacity;
    this->diskName = name;

}

os_project::Disk::Disk::~Disk() {

}

unsigned long int os_project::Disk::Disk::getStorageCapacity() {
    return storageCapacity;
}

void os_project::Disk::Disk::setDiskName(char diskName) {
    this->diskName =diskName;
}

char os_project::Disk::Disk::getDiskName() {
    return diskName;
}

void os_project::Disk::Disk::setMbr(MBR *mbr) {
    this->mbr = mbr;
}

MBR *os_project::Disk::Disk::getMbr() {
    return mbr;
}
