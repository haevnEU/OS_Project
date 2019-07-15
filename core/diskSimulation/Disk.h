//
// Created by Leon on 14.07.2019.
//

#ifndef PROJEKT_DISK_H
#define PROJEKT_DISK_H


class PartitionTable;

class Block;
class MBR;
class Partition;
class FileSystem;


class list;

class Disk {
private:
    long diskSize;
    long blockSize;
    long blockCount;
    Block ** blocks ;
    MBR * mbr;
    PartitionTable* partitions;

public:
    Disk(long diskSize, long blockSize);
    Partition * addPartition(Block *startBlock, Block *endBlock, FileSystem* formate, bool active);
    int removePartition(Partition* partition);
    bool getBit(long blockNumm,long bitNumm);
    void setBit(long blockNumm,long bitNumm,bool value);
    int coppyBlockContent(long block1,long block2);
    ~Disk();


};


#endif //PROJEKT_DISK_H
