#ifndef DISK_H
#define DISK_H

#include <string>

class API{
    void createFile(int disk, int partition){}
    void createDirectory(int disk, int partition){}
    void deleteFile(int disk, int partition){}
    void deleteDirectory(int disk, int partition){}
    void modifyFile(int disk, int partition){}
    void openFile(int disk, int partition){}
    void openDirectory(int disk, int partition){}
    void changeFileAttributes(int disk, int partition){}
    void changeDirectoryAttributes(int disk, int partition){}

    long freeSpace(int disk, int partition){return 0;}
    long usedSpace(int disk, int partition){return 0;}
    long totalSpace(int disk, int partition){return 0;}

    double fragmentation(int disk, int partition){return 0;}
    void fragmentate(int disk, int partition){}

    void createPartition(int disk){}
    void removePartition(int disk, int partition){}
    void resizePartition(int disk, int partition, int newSize){}
    void format(int disk, int partition){}
    void erase(int disk, int partition){}
    void mount(int disk, int partition){}
    void unmount(int disk, int partition){}

    void createDisk(){}

};
class Disk{
public:
    API* api = new API();
};

#endif // DISK_H
