#include "masterbootrecord.h"

using namespace core::disk;
const static int MAX_PARTITION = 4;

MasterBootRecord::MasterBootRecord( unsigned long long diskCapacity){
    diskCapacity_m = diskCapacity;
    availableDiskCapacity_m = diskCapacity;
    for(int i = 0; i < MasterBootRecord::MAX_PARTITION; i++){
        partitions_m[i] = nullptr;
    }
}

core::logic::Partition* MasterBootRecord::getPartition(int index){
    if(index >= MasterBootRecord::MAX_PARTITION){
        throw std::runtime_error("Index out of range");
    }
    return partitions_m[index];
}

bool MasterBootRecord::addPartition(int index, logic::Partition* partition){
    if(index >= MasterBootRecord::MAX_PARTITION){
        return false;
    }
    if(nullptr != partitions_m[index]){
       return false;
    }
    partitions_m[index] = partition;
}
bool MasterBootRecord::addPartition(logic::Partition* partition){
    if((availableDiskCapacity_m - (partition->blockSize() * partition->amountBlocks())) <= 0){
        return false;
    }

    for(int i = 0; i < this->MAX_PARTITION; i++){
        std::cout << i << std::endl;
        if(this->partitions_m[i] == nullptr){
            partitions_m[i] = partition;
            availableDiskCapacity_m -= (partition->blockSize() * partition->amountBlocks());
            return true;
        }
    }
    return false;

}

bool MasterBootRecord::addPartition(long blockSize, long amountBlocks, FileSystem::fileSystemType fileSystem){
    if((availableDiskCapacity_m - (blockSize * amountBlocks)) <= 0){
        return false;
    }

    for(int i = 0; i < this->MAX_PARTITION; i++){
        std::cout << i << std::endl;
        if(this->partitions_m[i] == nullptr){
            partitions_m[i] = new logic::Partition(blockSize, amountBlocks, fileSystem);
            availableDiskCapacity_m -= (blockSize * amountBlocks);
            return true;
        }
    }
    return false;
}

bool MasterBootRecord::addPartition(int index, long blockSize, long amountBlocks, FileSystem::fileSystemType fileSystem){
    if(index >= MasterBootRecord::MAX_PARTITION){
        return false;
    }

    if((availableDiskCapacity_m - (blockSize * amountBlocks)) < 0){
        return false;
    }

    if(partitions_m[index] == nullptr){
        partitions_m[index] = new logic::Partition(blockSize, amountBlocks, fileSystem);
        availableDiskCapacity_m -= (blockSize * amountBlocks);
        return true;
    }
    return false;
}

bool MasterBootRecord::removePartition(int index){
    if(index >= MasterBootRecord::MAX_PARTITION){
        throw std::runtime_error("Index out of range");
    }
    if(nullptr == partitions_m[index]){
        throw std::runtime_error("Nullpointer access");
    }
    delete(partitions_m[index]);
    partitions_m[index] = nullptr;
    return true;
}

unsigned long long MasterBootRecord::availableSpace()
{
    return availableDiskCapacity_m;
}

std::ostream& core::disk::operator<< (std::ostream& os, MasterBootRecord& mbr) {
    double percentage = 0;
    if(mbr.availableDiskCapacity_m > 0){
        percentage = (mbr.availableDiskCapacity_m * 100) / mbr.diskCapacity_m;
    }

    os << "Available space: " << mbr.availableDiskCapacity_m << " from " << mbr.diskCapacity_m << std::endl
       << "Used space: " << (mbr.diskCapacity_m - mbr.availableDiskCapacity_m) << "(" << percentage << "%)" << std::endl;
    for(int i = 0; i < mbr.MAX_PARTITION; i++){
        if(nullptr == mbr.partitions_m[i]){
            os << "Partition no.: " << i << " not assigned" << std::endl;
        }else{
            os << "Partition no.: " << i << ": " << *mbr.getPartition((i)) << std::endl;
        }
    }
return os;
}
