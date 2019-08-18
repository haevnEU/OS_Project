//
// Created by Leon Heindl on 18.08.2019.
//

#include <Partition.h>
#include <FileSystem.h>
#include <Block.h>

os_project::Partition::Partition::Partition(unsigned long int blockSize, unsigned long int blockCount,os_project::Filesystem::Filesystem* fileSystem) {

}

os_project::hard_disk::Block *os_project::Partition::Partition::getStartBlock() {
    return nullptr;
}

unsigned long int os_project::Partition::Partition::getBlockSize() {
    return 0;
}

void os_project::Partition::Partition::resizePartition(unsigned long int blockcount) {

}

unsigned long int os_project::Partition::Partition::getBlockCount() {
    return 0;
}

void os_project::Partition::Partition::setFileSystem(os_project::Filesystem::Filesystem* filesystem) {

}

os_project::Filesystem::Filesystem* os_project::Partition::Partition::getFileSystem() {
    return nullptr;
}

