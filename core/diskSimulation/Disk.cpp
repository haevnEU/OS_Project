//
// Created by Leon on 14.07.2019.
//

#include "Disk.h"
#include "Block.h"
#include "PartitionTable.h"
#include "FileSystem.h"

Disk::Disk(long diskSize, long blockSize) {
    this->diskSize = diskSize;
    this->blockSize = blockSize;
    this->blockCount = diskSize/blockSize;
    this->blocks = new Block*[blockCount];
    for(int i=0;i < this->blockCount;i++){
        this->blocks[i] =new Block(blockSize);
    }
    PartitionTable* patition = new PartitionTable;


}



Partition *Disk::addPartition(Block *startBlock, Block *endBlock, FileSystem* formate, bool active) {
    return this->partitions->addPartiton(startBlock,endBlock, formate, active);
}

int Disk::removePartition(Partition *partition) {
    return this->partitions->removePartiton(partition);
}

Disk::~Disk() {
    for(int i=0;i < this->blockCount;i++){
        delete this->blocks[i];
    }
}

int Disk::coppyBlockContent(long block1, long block2) {
    for(int i = 0; i < this->blockSize;i++){
        this->blocks[block2]->setBit(i,this->blocks[block1]->getBit(i));
    }
    return 0;
}

bool Disk::getBit(long blockNumm, long bitNumm) {
    return this->blocks[blockNumm]->getBit(bitNumm);
}

void Disk::setBit(long blockNumm, long bitNumm, bool value) {
    this->blocks[blockNumm]->setBit(bitNumm,value);
}
