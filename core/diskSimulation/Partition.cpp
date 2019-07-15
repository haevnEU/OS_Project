//
// Created by Leon on 14.07.2019.
//

#include "Partition.h"


Partition::Partition(Block *startBlock, Block *endBlock, FileSystem* formate, bool active) {
    this->startBlock = startBlock;
    this->endBlock = endBlock;
    this->formate = formate;
    this->active = active;
}
