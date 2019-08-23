//
// Created by Leon Heindl on 21.08.2019.
//

#include "FileSystem.h"

FileSystem::FileSystem(unsigned long int blockSize, unsigned long int blockCount, std::vector<logic::Block *>::iterator * startBlock,char separator):blockCount_m(blockCount),blockSize_m(blockSize),startBlock(startBlock),separator(separator) {

}

FileSystem::~FileSystem() {

}
