//
// Created by Leon Heindl on 17.08.2019.
//

#include "MBR.h"
#include "Partition.h"

os_project::mbr::MBR::MBR() {
partitionCount=0;
partitions = new Partition*[0];
}

Partition *os_project::mbr::MBR::getPartion(int partitionIndex) {
    if(partitionIndex >= partitionCount) {
        return nullptr;
    }else{
        return partitions[partitionIndex];
    }
}

int os_project::mbr::MBR::addPartition(Partition* partition) {
    Partition** partitionsTemp = new Partition*[partitionCount+1];
    for(int i=0;i < partitionCount;i++){
        partitionsTemp[i] = partitions[i];
    }
    partitionsTemp[partitionCount+1] = partition;
    partitions = partitionsTemp;
    partitionCount++;
    return partitionCount;
}

bool os_project::mbr::MBR::removePartition(int partitionIndex) {
    if(partitionIndex >= partitionCount) {
        return false;
    }else{
        Partition** partitionsTemp = new Partition*[partitionCount-1];
        for(int i=0;i < partitionCount;i++){
            if(partitionIndex != i) {
                partitionsTemp[i] = partitions[i];
            }
        }
        partitions = partitionsTemp;
        partitionCount--;
        return partitionCount;
    }
}

int os_project::mbr::MBR::listPartions(Partition **partitionArray) {
    partitionArray = partitions;
    return partitionCount;
}
