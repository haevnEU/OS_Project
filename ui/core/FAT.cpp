//
// Created by Leon Heindl on 20.08.2019.
//

#include <list>
#include "FAT.h"

/*###########################################
 * Implementaion of FATDirectoryEntry Metods
 ############################################*/

using namespace core;

FATDirectoryEntry::FATDirectoryEntry() {

}

FATDirectoryEntry::FATDirectoryEntry(unsigned long startBlock, std::string *name, std::string *ext, char uid, char gid,
                                     char permission, long access, long created, long changed) : startBlock(startBlock),
                                                                                                 name(name),ext(ext),
                                                                                                 uid(uid), gid(gid),
                                                                                                 permission(permission),
                                                                                                 access(access),
                                                                                                 created(created),
                                                                                                 changed(changed) {
}
std::string FATDirectoryEntry::toString() {
    std::string buffString;
    buffString.append(std::to_string(startBlock));
    buffString.append(",");
    buffString.append(*name);
    buffString.append(",");
    buffString.append(*ext);
    buffString.append(",");
    buffString.append(std::to_string(uid));
    buffString.append(",");
    buffString.append(std::to_string(gid));
    buffString.append(",");
    buffString.append(std::to_string(permission));
    buffString.append(",");
    buffString.append(std::to_string(access));
    buffString.append(",");
    buffString.append(std::to_string(created));
    buffString.append(",");
    buffString.append(std::to_string(changed));
    return buffString;
}

/*############################################
 * Implementaion of FATDirectory Metods
 #############################################*/
FATDirectory::FATDirectory(unsigned long int blockIndex) {
    this->blockIndex = blockIndex;
}

FileData * FATDirectory::writeDirectory(FATDirectory *directory) {
    std::string buffString;
    while(!directory->directoryEntrys.empty()) {
        buffString.append(directory->directoryEntrys.front()->toString());
        buffString.append(";");
    }
    FileData* file = new FileData(static_cast<unsigned long int>(buffString.length()+1));
    for(int i=0; i<=buffString.length();i++){
        file->data[i]=buffString[i];
    }
    return file;
}

FATDirectory *FATDirectory::readDirectory(FileData *file, unsigned long int blockIndex) {
    char inputData[file->length];
    for(int i=0;i< file->length;i++){
        inputData[i]= file->data[i];
    }
    std::string inputString(inputData);
    FATDirectory* buffDirectory = new FATDirectory(blockIndex);
    int x1=0,x2=0;
    for(int i=0; i < inputString.length();i++){
        FATDirectoryEntry buffEntry;
        //convert block index back
        x2 = inputString.find(",",x1);
        buffEntry.startBlock = std::stoul(inputString.substr(x1,x2-x1));
        x1=x2+1;
        //convert name back
        x2 = inputString.find(",",x1);
        buffEntry.name = new std::string(inputString.substr(x1,x2-x1));
        x1=x2+1;
        //conver extention back
        x2 = inputString.find(",",x1);
        buffEntry.ext = new std::string(inputString.substr(x1,x2-x1));
        x1=x2+1;
        //convert uid back
        x2 = inputString.find(",",x1);
        buffEntry.uid = inputString.at(x1);
        x1=x2+1;
        //convert gid back
        x2 = inputString.find(",",x1);
        buffEntry.gid = inputString.at(x1);
        x1=x2+1;
        //convert premission back
        x2 = inputString.find(",",x1);
        buffEntry.permission = inputString.at(x1);
        x1=x2+1;
        //convert access back
        x2 = inputString.find(",",x1);
        buffEntry.access = std::stol (inputString.substr(x1,x2-x1));
        x1=x2+1;
        //convert block index back
        x2 = inputString.find(",",x1);
        buffEntry.created = std::stol (inputString.substr(x1,x2-x1));
        x1=x2+1;
        //convert block index back
        x2 = inputString.find(";",x1);
        buffEntry.changed = std::stol (inputString.substr(x1,x2-x1));
        buffDirectory->addFile(&buffEntry);
        x1 = x2 +1;
    }
    return buffDirectory;

}

bool FATDirectory::addFile(FATDirectoryEntry* file) {
    directoryEntrys.push_back(file);
    return true;
}

bool FATDirectory::removeFile(FATDirectoryEntry* file) {
    std::vector<FATDirectoryEntry *>::iterator it = directoryEntrys.begin();
    while(it != directoryEntrys.end()){
        if((*it)->startBlock == file->startBlock){
            directoryEntrys.erase(it);
            return true;
        }
        it++;
    }
    return false;
}

std::vector<FATDirectoryEntry *>::iterator FATDirectory::getdirectoryEntrys() {
    return directoryEntrys.begin();
}

int FATDirectory::getEntryCount() {
    return directoryEntrys.size();
}

unsigned long int FATDirectory::getstartBlock() {
    return blockIndex;
}


/*#################################
 * Implementaion Of FAT functions
 ##################################*/


//FAT::FAT(unsigned long int blockSize,unsigned long int blockCount, std::vector<logic::Block *>::iterator * startBlock,char separator)
FAT::FAT(unsigned long int blockSize,unsigned long int blockCount, std::vector<logic::Block *>* startBlock,char separator)

: FileSystem(blockSize, blockCount, startBlock,separator) {
    rootDirectory = new FATDirectory(0);
    fileAlocationTable.push_back(0);
    for(int i = 1; i< blockCount_m ;i++){
        fileAlocationTable.push_back(0);
        freeBlocks.push_back(i);
    }
}

FileData * FAT::readFileData(unsigned long int blockIndex) {
    std::list<char > fileBuff;
    unsigned long int nextBlock = blockIndex;
    while(nextBlock != 0){
        for (int i = 0; i < blockSize_m ; i++) {
            fileBuff.push_back((*startBlock)[nextBlock]->getByte(i));
        }
        nextBlock = fileAlocationTable[blockIndex];
    }
    FileData* file = new FileData(fileBuff.size());
    int i=0;
    while(!fileBuff.empty()){
        file->data[i] = fileBuff.front();
        i++;
    }
    return file;
}

unsigned long int FAT::writeFileData(FileData *file) {
    if(ceil(file->length/(double)blockSize_m) >= freeBlocks.size()){
        return 0;
    }else{
        unsigned long int startBlockIndex = 0;
        unsigned long int blockIndex = 0;
        int byteInBlock = 0;
        int byteInData = 0;
        while(byteInData < file->length){
            if(startBlockIndex == 0){
                blockIndex = freeBlocks.front();
                startBlockIndex = blockIndex;
            }
            if(byteInBlock < blockSize_m){
                (*startBlock)[blockIndex]->setByte(byteInBlock,file->data[byteInData]);
                byteInBlock++;
                byteInData++;
            }else{
                unsigned int long nextBlock = freeBlocks.front();
                fileAlocationTable[blockIndex] = nextBlock;
                blockIndex = nextBlock;
            }
        }
        fileAlocationTable[blockIndex] = 0;
        return startBlockIndex;
    }
}


bool FAT::updateFileData(FileData *file, unsigned long int blockIndex) {
        int byteInBlock = 0;
        int byteInData = 0;
        while(byteInData < file->length){
            if(byteInBlock < blockSize_m){
                (*startBlock)[blockIndex]->setByte(byteInBlock,file->data[byteInData]);
                byteInBlock++;
                byteInData++;
            }else{
                unsigned int long nextBlock = fileAlocationTable[blockIndex];
                if(nextBlock == 0) {
                    if(ceil((file->length - byteInData)/(double)blockSize_m) >= freeBlocks.size()){
                        return false;
                    }
                    nextBlock = freeBlocks.front();
                    fileAlocationTable[blockIndex] = nextBlock;
                    blockIndex = nextBlock;
                }else {
                    blockIndex = nextBlock;
                }
            }
        }
        if(fileAlocationTable[blockIndex] != 0) {
            this->removeFileData(blockIndex);
        }
        return true;
    }


bool FAT::removeFileData(unsigned long int blockIndex) {
    if(blockIndex > blockCount_m){
        return false;
    }
    unsigned long int nextBlock = blockIndex;
    while(nextBlock != 0){
        nextBlock = fileAlocationTable[blockIndex];
        fileAlocationTable[blockIndex] = 0;
        freeBlocks.push_front(blockIndex);
        blockIndex = nextBlock;
    }
    return true;
}


FATDirectory *FAT::getDirectoryByPath(std::string path) {
    FATDirectory * directorryBuff = rootDirectory;
    int x1 = 1;
    int x2 = 0;
    bool pathFound = true;
    while(x1 < path.length()) {
        if(!pathFound){
            return nullptr;
        }
        pathFound = false;
        x2 = path.find(separator, x1);
        std::vector<FATDirectoryEntry*>::iterator it = directorryBuff->getdirectoryEntrys();
        for (int i = 0; i < directorryBuff->getEntryCount(); i++) {
            if(it[i]->name->compare(path.substr(x1,x2-x1)) && (it[i]->permission & 128)){
                pathFound = true;
                directorryBuff = FATDirectory::readDirectory(this->readFileData(it[i]->startBlock),it[i]->startBlock);
            }
        }
        x1 = x2 + 1;
    }
    return directorryBuff;

}

bool FAT::createFile(File *file) {
    std::string pathBuff;
    FATDirectory * directorryBuff = getDirectoryByPath(*file->getPath());
    if(directorryBuff == nullptr){
        return false;
    }
    unsigned long int blockIndex = freeBlocks.front();
    if(!(file->getPermission() & 128) ) { //if file is not a directory
        if(this->writeFileData(file->getData()) == 0){
            return false;
        }
    }
        directorryBuff->addFile(new FATDirectoryEntry(blockIndex,file->getName(),file->getExt(),file->getUid(),
                file->getGid(),file->getPermission(),file->getAccess(),file->getCreated(),file->getChanged()));
        return this->updateFileData(FATDirectory::writeDirectory(directorryBuff),directorryBuff->getstartBlock());
}


bool FAT::deleteFile(File *file) {
    return this->deleteFile(*(file->getPath()) + *(file->getName()) + "." + *(file->getExt()));
}

bool FAT::deleteFile(std::string path) {
    FATDirectory* directoryBuff  = this->getDirectoryByPath(path.substr(0,path.size()-path.rfind(separator)));
    if(directoryBuff == nullptr){
        return false;
    }
    std::vector<FATDirectoryEntry* >::iterator it = directoryBuff->getdirectoryEntrys();
    for (int i = 0; i < directoryBuff->getEntryCount(); i++) {
        if((it[i]->name->compare(path.substr(path.rfind(separator)))) ||
        ((*(it[i]->name) +"."+*(it[i]->ext)).compare(path.substr(path.rfind(separator))))){
            this->removeFileData(it[i]->startBlock);
            directoryBuff->removeFile(it[i]);
            return this->updateFileData(FATDirectory::writeDirectory(directoryBuff),directoryBuff->getstartBlock());
        }
    }
}

std::list<File *> FAT::getDirectoryContent(std::string path) {
    std::list<File *> fileListBuff;
    FATDirectory* directoryBuff  = this->getDirectoryByPath(path.substr(0,path.size()-path.rfind(separator)));
    if(directoryBuff == nullptr){
        return fileListBuff;
    }
    std::vector<FATDirectoryEntry* >::iterator it = directoryBuff->getdirectoryEntrys();
    for (int i = 0; i < directoryBuff->getEntryCount(); i++) {
            fileListBuff.push_back(new File(this->readFileData(it[i]->startBlock),it[i]->name,it[i]->ext,it[i]->uid,it[i]->gid,it[i]->permission,it[i]->access,it[i]->created,it[i]->changed));
    }
    return fileListBuff;
}

std::list<File *> FAT::getDirectoryContent(File *directoy) {
    return this->getDirectoryContent(*(directoy->getPath()) + *(directoy->getName()) + "." + *(directoy->getExt()));
}

File *FAT::getFile(std::string path) {
    FATDirectory* directoryBuff  = this->getDirectoryByPath(path.substr(0,path.size()-path.rfind(separator)));
    if(directoryBuff == nullptr){
        return nullptr;
    }
    std::vector<FATDirectoryEntry* >::iterator it = directoryBuff->getdirectoryEntrys();
    for (int i = 0; i < directoryBuff->getEntryCount(); i++) {
        if((it[i]->name->compare(path.substr(path.rfind(separator)))) ||
           ((*(it[i]->name) +"."+*(it[i]->ext)).compare(path.substr(path.rfind(separator))))){
            File* fileBuff = new File(this->readFileData(it[i]->startBlock),it[i]->name,it[i]->ext,it[i]->uid,it[i]->gid,it[i]->permission,it[i]->access,it[i]->created,it[i]->changed);
            return fileBuff;
        }
    }
    return nullptr;
}

File* FAT::getFile(File *directory) {
    return this->getFile(*(directory->getPath()) + *(directory->getName()) + "." + *(directory->getExt()));
}

char FAT::fragmentation() {
    return 10;
}

bool FAT::defrag() {
    if(freeBlocks.size()>0){
        return true;
    }
    return false;
}

long FAT::freeSpace() {
    return (freeBlocks.size()*blockSize_m);
}

long FAT::usedSpace() {
    return (this->capacity() - this->freeSpace());
}

long FAT::capacity() {
    return (blockCount_m * blockSize_m);
}

FAT::~FAT() {

}

bool FAT::changeFileAtributs(File *oldFile, File *newFile) {
    return false;
}

bool FAT::changeFileAtributs(std::string path, File *newFile) {
    return false;
}

bool FAT::changeFileContent(File *file, FileData *newData) {
    return false;
}

bool FAT::changeFileContent(std::string path, FileData *newData) {
    return false;
}

