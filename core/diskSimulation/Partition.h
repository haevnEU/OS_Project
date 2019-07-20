//
// Created by Leon on 14.07.2019.
//

#ifndef OS_PROJECT_PARTITION_H
#define OS_PROJECT_PARTITION_H


class FileSystem;

class Block;

class Partition {
private:
    Block * startBlock;
    Block * endBlock;
    FileSystem * formate;
    bool active;
public:
    Partition(Block *startBlock, Block *endBlock, FileSystem * formate, bool active);
    ~Partition();
};


#endif //OS_PROJECT_PARTITION_H
