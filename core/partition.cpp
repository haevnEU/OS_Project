#include "partition.h"

using namespace logic;

Partition::Partition(Partition* partition){
    throw std::runtime_error("Call to Partition(Partition* partition) is not allowed");
}

Partition::Partition(Partition &partition){
    throw std::runtime_error("Call to Partition(Partition &partition) is not allowed");
}

Partition::Partition(unsigned long blockSize, unsigned long amountBlocks, IFileSystem* fileSystem){
    blockSize_m = blockSize;
    amountBlocks_m = amountBlocks;
    fileSystem_m = fileSystem;
    blocks_m = new std::vector<Block*>();

    for(unsigned long i = 0; i < amountBlocks; i++){
        blocks_m->push_back(new Block(blockSize));
    }

    mounted_m = false;
}

bool Partition::format(unsigned long blockSize, unsigned long amountBlocks, IFileSystem* fileSystem){
    if(isMounted() || !erase()){
        return false;
    }
    blockSize_m = blockSize;
    amountBlocks_m = amountBlocks;
    fileSystem_m = fileSystem;
    blocks_m = new std::vector<Block*>();

    for(unsigned long i = 0; i < amountBlocks; i++){
        blocks_m->push_back(new Block(blockSize));
    }

    mounted_m = false;
    return true;
}

bool Partition::erase(void){
    if(isMounted()){
        return false;
    }
    blockSize_m = 0;
    amountBlocks_m = 0;
    if(nullptr != fileSystem_m){
        delete(fileSystem_m);
        fileSystem_m = nullptr;
    }
    if(nullptr != blocks_m){
        blocks_m->clear();
        delete(blocks_m);
    }
    return true;
}

IFileSystem* Partition::fileSystem(void){
    if(!isMounted()){
        throw std::runtime_error("Partition is not mounted");
    }
    return fileSystem_m;
}

unsigned long Partition::blockSize(void){
    if(!isMounted()){
        throw std::runtime_error("Partition is not mounted");
    }
    return blockSize_m;
}

unsigned long Partition::amountBlocks(void){
    if(!isMounted()){
        throw std::runtime_error("Partition is not mounted");
    }
    return amountBlocks_m;
}

void Partition::mount(void){
    mounted_m = true;
}

void Partition::unmount(void){
    mounted_m = false;
}

bool Partition::isMounted(void){
    return mounted_m;
}


std::ostream& logic::operator<< (std::ostream& os, Partition& partition){

    os << "Mounted: " << (partition.isMounted() ? "True" : "False") << std::endl
       << "Amount blocks: " << partition.amountBlocks_m << " Block size: " << partition.blockSize_m;
       // << "File system: " << partition.fileSystem_m << std::endl;
    return os;
}

std::vector<logic::Block*>::iterator Partition::getStart() {
    return blocks_m->begin();
}
