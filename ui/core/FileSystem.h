//
// Created by Leon Heindl on 21.08.2019.
//

#ifndef OS_PROJECT_FILESYSTEM_H
#define OS_PROJECT_FILESYSTEM_H


#include <list>
#include <vector>
#include "Block.h"
#include "File.h"

namespace core{
/**
 * Interface Class For Filesystem
 * @author Leon Heindl
 */
class FileSystem {


public:
    enum fileSystemType{INode, FAT,CD_ROM, other};
protected:
    ///an iterator for the first Block in the partition on with the file system lays
    std::vector<logic::Block* > * startBlock;
    ///the size of the blocks in the partition on with the file system lays
    unsigned long int blockSize_m;
    ///the amount of blocks in the partition on with the file system lays
    unsigned long int blockCount_m;
    ///directory separator
    char separator;

public:
    /**
     * Constructor for Filesystem
     * @param blockSize the size of the Blocks in the file system in bytes
     * @param blockCount the count of Blocks in the Filesystem
     * @param startBlock the iterator for the first Block in the Partition
     * @param separator a seperator char to seperat a path
     */
    //FileSystem(unsigned long int blockSize, unsigned long int blockCount,std::vector<logic::Block* >::iterator* startBlock,char separator);
    FileSystem(unsigned long int blockSize, unsigned long int blockCount,std::vector<logic::Block* >* startBlock,char separator);
    virtual ~FileSystem();

    /**
     * Stores File
     * @param file
     * @return
     */
    virtual bool createFile(File* file) = 0;

    virtual bool deleteFile(File* file) =0;

    virtual bool deleteFile(std::string path)=0;

    virtual bool changeFileAtributs(File* oldFile,File* newFile) =0;

    virtual bool changeFileAtributs(std::string path,File* newFile) =0;

    virtual bool changeFileContent(File* file , FileData* newData) = 0;

    virtual bool changeFileContent(std::string path , FileData* newData) = 0;

    virtual std::list<File*> getDirectoryContent(std::string path) =0;

    virtual std::list<File*> getDirectoryContent(File* directoy) =0;

    virtual File* getFile(std::string path) =0;

    virtual File* getFile(File* directory) =0;

    virtual char fragmentation() =0;

    virtual bool defrag() =0;

    virtual long freeSpace() =0;

    virtual long usedSpace() =0;

    virtual long capacity() =0;

};
} //core

#endif //OS_PROJECT_FILESYSTEM_H
