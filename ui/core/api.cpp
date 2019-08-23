#include "api.h"
#include "api.h"

API* API::instance = nullptr;

API::API() : QObject(){
   // do init stuff
}

API* API::GetInstance()
{
    if (instance == nullptr) {
        instance = new API();
    }
    return instance;
}

void API::setDisk(core::disk::Disk *disk){
    curentDisk = disk;
    emit diskChanged();
}

void API::clearDisk(){
    curentDisk = nullptr;
}

core::disk::Disk *API::currentDisk(){
    return curentDisk;
    emit diskChanged();
}

void API::setIndex(int index){
    currentIndex = index;
    emit indexChanged();
}

int API::currentPartitionIndex(){
    return currentIndex;
}

unsigned long long API::blockSize(int index){
    if(nullptr == curentDisk || index > curentDisk->MBR()->MAX_PARTITION){
        return -1UL;
    }
    return curentDisk->MBR()->getPartition(index)->blockSize();
}

unsigned long long API::blockCount(int index){
    if(nullptr == curentDisk || index > curentDisk->MBR()->MAX_PARTITION){
        return -1UL;
    }
    return curentDisk->MBR()->getPartition(index)->amountBlocks();
}

unsigned long long API::diskSize(){
    if(nullptr == curentDisk){
        return -1UL;
    }
    return curentDisk->capacity();
}

unsigned long long API::availableDiskSize(){
    if(nullptr == curentDisk){
        return -1UL;
    }
    return curentDisk->MBR()->availableSpace();
}



void API::defrag(int partitionIndex){
    if(nullptr == curentDisk || nullptr == curentDisk->MBR()->getPartition(partitionIndex)){
        return;
    }
}

double API::fragmentation(int partitionIndex){
    if(nullptr == curentDisk || nullptr == curentDisk->MBR()->getPartition(partitionIndex)){
        return -1;
    }
}

void API::format(int partitionIndex){
    if(nullptr == curentDisk || nullptr == curentDisk->MBR()->getPartition(partitionIndex)){
        return;
    }
}

void API::addPartition(core::logic::Partition *partition){
    if(nullptr == curentDisk){
        return;
    }
}

void API::addPartition(int partitionIndex, core::logic::Partition *partition){
    if(nullptr == curentDisk || nullptr == curentDisk->MBR()->getPartition(partitionIndex)){
        return;
    }
}

void API::resizePartition(int partitionIndex, unsigned long long newBlockCount){
    if(nullptr == curentDisk || nullptr == curentDisk->MBR()->getPartition(partitionIndex)){
        return;
    }
}


void API::createFile(int partitionIndex, std::string name, std::string ext, short uid, short gid, char permision, unsigned long long create, unsigned long long  access, unsigned long long  change){
    if(nullptr == curentDisk || nullptr == curentDisk->MBR()->getPartition(partitionIndex)){
        return;
    }
}
