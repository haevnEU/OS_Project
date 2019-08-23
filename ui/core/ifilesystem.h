#ifndef IFILESYSTEM_H
#define IFILESYSTEM_H

#include "FileSystem.h"

namespace core{
typedef FileSystem IFileSystem;

 /*   class IFileSystem{
    private:
        long blockSize_m;
        long blockCount_m;

    public:
        IFileSystem(long blockSize, long blockCount);

        long blockSize(void);

        long amountBlocks(void);

        virtual void mount(void) = 0;
        virtual void unmount(void) = 0;

        virtual void selfCheck(void) = 0;
        virtual void selfRepair(void) = 0;

        virtual void createFile(void) = 0;
        virtual void createDirectory(void) = 0;

        virtual void deleteFile(void) = 0;
        virtual void deleteDirectory(void) = 0;

        virtual void openFile(void) = 0;
        virtual void closeFile(void) = 0;

        virtual const char* readFile(void) = 0;
        virtual const char* readFile(int length) = 0;
        virtual void writeFile(const char* data, int length) = 0;

        virtual char fragmentation(void) = 0;
        virtual void defrag(void) = 0;
        virtual long freeSpace(void) = 0;
        virtual long usedSpace(void) = 0;
        virtual long capacity(void) = 0;



        virtual void changeAttributes() = 0;

    };*/
} // core
#endif // IFILESYSTEM_H
