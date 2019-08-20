//
// Created by Leon Heindl on 18.08.2019.
//

#include <Partition.h>
#include <FileSystem.h>
#include <Block.h>

os_project::Partition::Partition::Partition(unsigned long int blockSize, unsigned long int blockCount,os_project::Filesystem::Filesystem* fileSystem) {
this->blockSize = blockSize;
this->blockCount = blockCount;
this->fileSystem = fileSystem;
this->startBlock = new os_project::hard_disk::Block*[blockCount];
for(int i=0; i < blockCount;i++){
    this->startBlock[i] = new os_project::hard_disk::Block(blockSize);
}
}

os_project::hard_disk::Block *os_project::Partition::Partition::getStartBlock() {
    return startBlock;
}

unsigned long int os_project::Partition::Partition::getBlockSize() {
    return blockSize;
}

void os_project::Partition::Partition::resizePartition(unsigned long int blockCount) {
    this->blockCount = blockCount;
    this->startBlock = new os_project::hard_disk::Block*[blockCount];
    for(int i=0; i < blockCount;i++){
        this->startBlock[i] = new os_project::hard_disk::Block(this->blockSize);
    }
}

unsigned long int os_project::Partition::Partition::getBlockCount() {
    return blockCount;
}

void os_project::Partition::Partition::setFileSystem(os_project::Filesystem::Filesystem* filesystem) {
    this->fileSystem = filesystem;
}

os_project::Filesystem::Filesystem* os_project::Partition::Partition::getFileSystem() {
    return this->fileSystem;
}


