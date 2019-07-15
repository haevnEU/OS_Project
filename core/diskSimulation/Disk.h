//
// Created by Leon on 14.07.2019.
//

#ifndef PROJEKT_DISK_H
#define PROJEKT_DISK_H


class Block;
class MBR;
class Partition;
enum FormatType{};


class Disk {
private:
    long diskSize;
    long blockSize;
    Block * storageBlocks ;
    MBR * mbr;

public:
    Disk(long diskSize, long blockSize);
    Partition * addPartition(FormatType type , long size);
    int removePartition(Partition* partition);
    ~Disk();


};


#endif //PROJEKT_DISK_H
