//
// Created by Leon on 15.07.2019.
//

#ifndef OS_PROJECT_PARTITIONTABLE_H
#define OS_PROJECT_PARTITIONTABLE_H

class FileSystem;
class Block;
class Partition;



class PartitionTable {
private:
    Partition** partitons;
    int partitionCount;
public:
    PartitionTable();
    Partition* addPartiton(Block *startBlock, Block *endBlock, FileSystem* formate, bool active);
    int removePartiton(Partition*);
    ~PartitionTable();

};


#endif //OS_PROJECT_PARTITIONTABLE_H
