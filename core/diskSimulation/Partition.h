//
// Created by Leon on 14.07.2019.
//

#ifndef OS_PROJECT_PARTITION_H
#define OS_PROJECT_PARTITION_H


#include "Block.h"
#include "FormatType.h"

class Partition {
private:
    Block * startBlock;
    Block * endBlock;
    FormatType formate;
    bool active;

};


#endif //OS_PROJECT_PARTITION_H
