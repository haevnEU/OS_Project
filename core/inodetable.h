#ifndef INODE_H
#define INODE_H

#include <list>

#include "ifilesystem.h"
#include "inode.h"

class INodeTable : public IFileSystem
{

private:
    std::list<INode*> inodes;
public:
    INodeTable();
    ~INodeTable();
public:

    void mount(void);
    void unmount(void);

    void selfCheck(void);
    void selfRepair(void);

    void createFile(void);
    void createDirectory(void);

    void deleteFile(void);
    void deleteDirectory(void);

    void openFile(void);
    void closeFile(void);

    const char* readFile(void);
    const char* readFile(int length);
    void writeFile(const char* data, int length);

    char fragmentation(void);
    void defrag(void);
    long freeSpace(void);
    long usedSpace(void);
    long capacity(void);



    void changeAttributes();
};

#endif // INODE_H
