#include "partition.h"
#include "FAT.h"
using namespace core::logic;

Partition::Partition(Partition* partition){
    throw std::runtime_error("Call to Partition(Partition* partition) is not allowed");
}

Partition::Partition(Partition &partition){
    throw std::runtime_error("Call to Partition(Partition &partition) is not allowed");
}

Partition::Partition(unsigned long long blockSize, unsigned long long amountBlocks, FileSystem::fileSystemType fileSystem){
    blockSize_m = blockSize;
    amountBlocks_m = amountBlocks;
    blocks_m = new std::vector<Block*>();

    switch(fileSystem){
        case core::FileSystem::fileSystemType::INode:
            fileSystem_m = nullptr;
            break;
        case core::FileSystem::fileSystemType::FAT:

            fileSystem_m = new FAT(blockSize, amountBlocks, blocks_m, '/');
            break;
        case core::FileSystem::fileSystemType::CD_ROM:
            fileSystem_m = nullptr;
            break;
        case core::FileSystem::fileSystemType::other:
            fileSystem_m = nullptr;
            break;
    }

    for(unsigned long long i = 0; i < amountBlocks; i++){
        blocks_m->push_back(new Block(blockSize));
    }

    mounted_m = false;
}

bool Partition::format(unsigned long long blockSize, unsigned long long amountBlocks, FileSystem::fileSystemType fileSystem){
    if(isMounted() || !erase()){
        return false;
    }
    blockSize_m = blockSize;
    amountBlocks_m = amountBlocks;

    switch(fileSystem){
        case core::FileSystem::fileSystemType::INode:
            fileSystem_m = nullptr;
            break;
        case core::FileSystem::fileSystemType::FAT:

            fileSystem_m = new FAT(blockSize, amountBlocks, blocks_m, '/');
            break;
        case core::FileSystem::fileSystemType::CD_ROM:
            fileSystem_m = nullptr;
            break;
        case core::FileSystem::fileSystemType::other:
            fileSystem_m = nullptr;
            break;
    }

    blocks_m = new std::vector<Block*>();

    for(unsigned long long i = 0; i < amountBlocks; i++){
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

core::FileSystem* Partition::fileSystem(void){
    return fileSystem_m;
}

unsigned long long Partition::blockSize(void){
    return blockSize_m;
}

unsigned long long Partition::amountBlocks(void){
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

void Partition::resize(unsigned long long newSize){
    long long requiredBlocks = static_cast<long long>(newSize) - static_cast<long long>((amountBlocks_m));
    if(requiredBlocks > 0){
        for(long long i = 0; i < requiredBlocks; i++){
           blocks_m->push_back(new logic::Block(blockSize_m));
           amountBlocks_m++;
        }
    }else if(requiredBlocks < 0){
        for(long long i = requiredBlocks; i < 0; i++){
           blocks_m->pop_back();
           amountBlocks_m--;
        }
    }
}


std::ostream& core::logic::operator<< (std::ostream& os, Partition& partition){

    os << "Mounted: " << (partition.isMounted() ? "True" : "False") << std::endl
       << "Amount blocks: " << partition.amountBlocks_m << " Block size: " << partition.blockSize_m;
       // << "File system: " << partition.fileSystem_m << std::endl;
    return os;
}
