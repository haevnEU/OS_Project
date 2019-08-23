//
// Created by Leon Heindl on 20.08.2019.
//

#ifndef OS_PROJECT_FAT_H
#define OS_PROJECT_FAT_H


#include "ifilesystem.h"
#include "block.h"
#include "FileSystem.h"
#include "file.h"
#include <list>
#include <vector>
#include <math.h>
namespace core{
/**
 * A struct witch holds all information about a Fat Directory entry
 * @author Leon Heindl
 */
struct FATDirectoryEntry{
    /**
     * Empty constructor to instate an empty instance of the FATDirectoryEntry
     */
    FATDirectoryEntry();
    /**
     * A full constructor to initiate a full instance of the  FATDirectoryEntry
     * @param startBlock the index of the first Block of the file linked to the directory Entry
     * @param name the name of the file as must be exectly 8 bytes (8.3 notation)
     * @param ext the file extention must be exectly 3 bytes (8.3 notation)
     * @param uid
     * @param gid
     * @param permission the premissions of the file as char d h g g g o o o
     * @param access
     * @param created
     * @param changed
     */
    FATDirectoryEntry(unsigned long startBlock, std::string *name, std::string *ext, char uid, char gid, char permission, long access,
                      long created, long changed);
    /// the first index of the file in the FAT
    unsigned long int startBlock;
    /// name of the file 8 characters
    std::string * name;
    /// the file extention 3 carachters
    std::string * ext;
    /// the uid of the file
    char uid;
    /// the gid of the file
    char gid;
    /// the permissions of the file
    char permission;
    /// the last access of the file
    long access;
    /// the cration time of the file
    long created;
    /// the last change time of the file
    long changed;

    /**
     * A to sting methode to make the make a sting of the fat file entry
     * @return
     */
    std::string toString();

};
/**
 * class witch holds a directory in the Fat File system
 */

class FATDirectory{
private:
    /// list holding Directory enterences
    std::vector<FATDirectoryEntry*> directoryEntrys;
    ///self start Block
    unsigned long int blockIndex;
public:
    FATDirectory(unsigned long int blockIndex);
    /**
     * static metod to convert a directory to File data
     * @param directory a FAt directory as an input
     * @return returns a FileData object coding the input Directoy in byte data
     */
    static FileData * writeDirectory(FATDirectory* directory);
    /**
     * static metod to Generate a FATDirectory from File Data reconstructing the object
     * @param file is a FileData object containing a File object
     * @return returns a FAT Directory
     */
    static FATDirectory* readDirectory(FileData *file, unsigned long int blockIndex);
    /**
     * adds a FATDirectoryEntry to the Fat Directory
     * @param file a FATDirectoryEntry to att to the directory
     * @return returns true if the file
     */
    bool addFile(FATDirectoryEntry* file);

    bool removeFile(FATDirectoryEntry* file);

    std::vector<FATDirectoryEntry *>::iterator getdirectoryEntrys();

    int getEntryCount();

    unsigned long int getstartBlock();



};

/**
 * Fat Class this class simulates a fat file system
 * @author Leon Heindl
 */

class FAT : public FileSystem{
private:

    /// a vector witch holds the file alocation tabel of the fat system
    std::vector<unsigned long int> fileAlocationTable;
    /// a list of free block in the Fat partition
    std::list<unsigned long int> freeBlocks;
    /// the rood directory of the Fat Filesystem
    FATDirectory* rootDirectory;
    /**
    * Reads the file data from the BLocks and returns it in form of a FileData structur
    * @param blockIndex the index in the FAT for the first data Block
    * @return a FileData strucur containinng tha data Bytes returns NULLPTR if no file exist at block index
    */
    FileData * readFileData(unsigned long int blockIndex);

    /**
     * Writes File data to the Blocks
     * @param file a File Data Object witch will be written to the File
     * @return the index of the first block int FTA if ther is enug space on the plate otherwise returns 0
     */
    unsigned long int writeFileData(FileData *file);

    bool updateFileData(FileData *file,unsigned long int blockIndex);

    bool removeFileData(unsigned long int blockIndex);

    FATDirectory* getDirectoryByPath(std::string path);

public:
    /**
     * Base constructor for the FAT file system
     * @param blockSize the size of a block on the partition on witch The filesystem is stored
     * @param blockCount the amount of blocks in the partition on witch the filesystem is stored
     * @param startBlock a iterator to the start block of the Partition on witch the filesystem is stored
     */
//    FAT(unsigned long int  blockSize, unsigned long int blockCount, std::vector<logic::Block *>::iterator *startBlock,char separator);
    FAT(unsigned long int  blockSize, unsigned long int blockCount, std::vector<logic::Block *> *startBlock,char separator);

    /**
     * empty destructor
     */
    virtual ~FAT() override;

    bool createFile(File* file) override;

    bool deleteFile(File* file) override;

    bool deleteFile(std::string path) override;

    bool changeFileAtributs(File* oldFile,File* newFile) override;

    bool changeFileAtributs(std::string path,File* newFile) override;

    bool changeFileContent(File* file , FileData* newData) override;

    bool changeFileContent(std::string path , FileData* newData) override;

    std::list<File*> getDirectoryContent(std::string path) override;

    std::list<File*> getDirectoryContent(File* directoy) override;

    File* getFile(std::string path) override;

    File* getFile(File* directory) override ;

    char fragmentation() override;

    bool defrag() override;

    long freeSpace() override;

    long usedSpace() override;

    long capacity() override;

};
} // core

#endif //OS_PROJECT_FAT_H
