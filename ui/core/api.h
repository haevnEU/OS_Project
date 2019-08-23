#ifndef API_H
#define API_H

#include <string>
#include "block.h"
#include "disk.h"
#include "masterbootrecord.h"
#include "partition.h"
#include <QObject>

class API : public QObject{

    Q_OBJECT

public:
    static API* GetInstance();

    void setDisk(core::disk::Disk* disk);

    void clearDisk();

    core::disk::Disk* currentDisk();

    void setIndex(int index);

    int currentPartitionIndex(void);

    unsigned long long blockSize(int index);

    unsigned long long blockCount(int index);

    void defrag(int partitionIndex);

    double fragmentation(int partitionIndex);

    void format(int partitionIndex);

    void addPartition(core::logic::Partition* partition);

    void addPartition(int index, core::logic::Partition* partition);

    void resizePartition(int index, unsigned long long newBlockCount);

    void createFile(int index, std::string name, std::string ext, short uid, short gid, char permision,
                    unsigned long long create, unsigned long long access, unsigned long long change);
    void removeFile(int partitionIndex);

    void modifyFile(int partitionIndex);

    unsigned long long diskSize();

    unsigned long long availableDiskSize();


private:
    core::disk::Disk* curentDisk = nullptr;

    int currentIndex;

    API();

    static API* instance;
public:

signals:
    void diskChanged();

    void indexChanged();
};

#endif // API_H
