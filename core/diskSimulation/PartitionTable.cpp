//
// Created by Leon on 15.07.2019.
//

#include "PartitionTable.h"
#include "Partition.h"


PartitionTable::PartitionTable() {
    partitionCount = 0;
    this->partitons = new Partition*[partitionCount];

}

Partition* PartitionTable::addPartiton(Block *startBlock, Block *endBlock, FileSystem* formate, bool active) {
    partitionCount++;
    Partition** tempPations = new Partition*[partitionCount];
    for(int i=0;i < partitionCount;i++){
        tempPations[i] = this->partitons[i];
    }
    Partition* buff = new Partition(startBlock, endBlock, formate ,active);
    tempPations[partitionCount] = buff;
    this->partitons = tempPations;
    return buff;

}

int PartitionTable::removePartiton(Partition * partion) {
    Partition** tempPations = new Partition*[partitionCount-1];
    for(int i=0;i < partitionCount;i++){
        if(partion != tempPations[i]) {
            tempPations[i] = this->partitons[i];
        }
    }
    this->partitons = tempPations;
    return 0;

}

PartitionTable::~PartitionTable() {

}
