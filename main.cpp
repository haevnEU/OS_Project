#include <iostream>
#include <random>
#include <string>
#include <ctype.h>
using namespace std;
struct BsCluster{
    unsigned int blockId;
    BsCluster* next;
    BsCluster* previous;
};

struct BsFile{
    string filename;
    bool writeAbel;
    bool readAbel;
    bool hidden;
    unsigned int ownerid;
    BsCluster* startcluster;
    unsigned int clustercount;

};

struct BsFat{
    char* state;
    unsigned int blockCount;
    BsFile* files[10];
};

BsCluster* newBsClusterList(unsigned int blocks[], unsigned int blockCount){
    //std::cout << sizeof(blocks) ;
    BsCluster* first = new BsCluster;
    BsCluster* temp = first;
    temp->previous = nullptr;
    temp->blockId = blocks[0];
    for(int i=1 ; i < blockCount;i++){
        temp->next = new BsCluster;
        temp->next->previous = temp;
        temp = temp->next;
        temp->next = nullptr;
        temp->blockId = blocks[i];
    }
    return (first);
}
BsFat* createBsFat(unsigned int plateSize,unsigned int blockSize){
    BsFat* tempBsFat = new BsFat;
    tempBsFat->blockCount = plateSize / blockSize;
    tempBsFat->state = new char[tempBsFat->blockCount];
    for(int i=0;i<tempBsFat->blockCount;i++) {
        tempBsFat->state[i] = 'F';
    }
    for(int i=0;i<10;i++){
        tempBsFat->files[i] = nullptr;
    }
    return (tempBsFat);
}
int getFreeDiskSpace(BsFat* pFat){
    int freeblocks = 0;
    for(int i = 0; i <= pFat->blockCount;i++){
        if(pFat->state[i] == 'F'){
            freeblocks++;
        }
    }
    return (freeblocks);
}
BsFile* createFile(BsFat* pFat,int szFile,string filename, unsigned int owner , bool writeAbel , bool readAbel,bool hidden){
    if(getFreeDiskSpace(pFat) >= szFile){
        string filename2 ;
        char* c1 = new char;
        for (int i = 0;i < filename.length();i++){
            *c1 = toupper(filename.at(i));
            filename2.append(c1,c1+1);
        }
        string filenameFirstPart = filename2.substr(0,filename2.find('.'));
        string filenameSecondPart = filename2.substr(filename2.find('.'));
        if(filenameFirstPart.length() > 8){
            filenameFirstPart = filenameFirstPart.substr(0,6) + '~' + filenameFirstPart.substr(filenameFirstPart.length()-1);
        }
        if(filenameSecondPart.length() > 4){
            filenameSecondPart = filenameSecondPart.substr(0,4);
        }
        filename2 = filenameFirstPart+ filenameSecondPart;
        cout <<"filename : " << filename2 <<endl;
        BsFile *buff = new BsFile;
        buff->filename = filename2;
        buff->clustercount = szFile;
        buff->ownerid = owner;
        buff->hidden = hidden;
        buff->readAbel = readAbel;
        buff->writeAbel = writeAbel;
        bool safed = false;
        unsigned int fileBlocks[szFile];
        for (int i = 0; i < 10 && (!safed); i++) {
            if (pFat->files[i] == nullptr) {
                pFat->files[i] = buff;
                safed = true;
            }
        }
        for (int i = 0; i < szFile;) {
            int location = std::rand() % pFat->blockCount;
            if (pFat->state[location]=='F') {
                pFat->state[location] = 'B';
                fileBlocks[i] = location;
                i++;
            }
        }
        buff->startcluster = newBsClusterList(fileBlocks, szFile);
    }
}
void deleteFile(BsFat* pFat,string fileName){
    for(int i =0; i < 10;i++){
        if(pFat->files[i] != nullptr) {
            if (pFat->files[i]->filename == fileName) {
                BsCluster* temp = pFat->files[i]->startcluster;
                while(temp != nullptr){
                    pFat->state[temp->blockId] = 'F';
                    temp = temp->next;
                }
                delete (pFat->files[i]);
                pFat->files[i] = nullptr;
            }
        }
    }
}

float getFragmentation(BsFat* pFat){
    int numberOfConsecutiveBlocks = 0;
    int numberOfNotConsecutiveBlocks = 0;
    for (int i = 0; i < 10; i++) {
        if (pFat->files[i] != NULL) {
            BsCluster* cluster = pFat->files[i]->startcluster;
            unsigned int clusterBlock = cluster->blockId;
            while(cluster->next != NULL) {
                numberOfConsecutiveBlocks++;
                cluster = cluster->next;
                if (cluster->blockId != clusterBlock + 1)
                    numberOfNotConsecutiveBlocks++;
                clusterBlock = cluster->blockId;
            }
        }
    }
    if (numberOfConsecutiveBlocks == 0)
        return 0.0f;

    return (float)numberOfNotConsecutiveBlocks / (float)numberOfConsecutiveBlocks * 100.0f;

}


void showFat(BsFat* pFat){
    for (int i = 0; i < pFat->blockCount ; i++) {
        if(pFat->state[i] == 'B'){
            for (int j = 0; j < 10; j++) {
                if (pFat->files[j] != NULL) {
                    BsCluster* cluster;
                    cluster = pFat->files[j]->startcluster;
                    while (cluster != NULL) {
                        if (cluster->blockId == i) {
                            cout << '|' << j;
                            break;
                        }
                        cluster = cluster->next;
                    }
                }
            }
        }else{
            cout <<'|' <<pFat->state[i] ;
        }
    }
    cout <<'|' << endl;
}

void switchBlocks(BsFat* pFat,unsigned int a , unsigned int b){
    for (int j = 0; j < 10; j++) {
        if (pFat->files[j] != NULL) {
            BsCluster* cluster;
            cluster = pFat->files[j]->startcluster;
            while (cluster != NULL) {
                if (cluster->blockId == a) {
                    cluster->blockId = b;
                    pFat->state[b] = 'B';
                    pFat->state[a] = 'F';
                    return;
                }
                cluster = cluster->next;
            }
        }
    }
}

void defragDisk(BsFat* pFat){
    if(getFreeDiskSpace(pFat)==0){
        cout << "Storage fulll no defragmation posible" << endl;
        return;
    }
    unsigned int fragmanted=0;
    for(int file=0; file < 10 ; file++){
        if(pFat->files[file] != nullptr){
            BsCluster* temp = pFat->files[file]->startcluster;
            while(temp != nullptr){
                bool moved = false;
                for (int i = fragmanted; i < pFat->blockCount && !moved ; i++) {
                    if(pFat->state[i]!= 'D'&&pFat->state[i]!= 'R'){
                        if(pFat->state[i] == 'B'){
                            bool freeSpaceFound = false;
                            for (int j = pFat->blockCount -1;  !freeSpaceFound && j >= 0 ; j--) {
                                if(pFat->state[j]=='F'){
                                    switchBlocks(pFat,i,j);
                                    freeSpaceFound = true;
                                    moved = true;
                                    showFat(pFat);
                                    cout<<"Fragmentation: "<< getFragmentation(pFat) << " Percent" <<endl;
                                }
                            }
                        }else{
                            pFat->state[temp->blockId] = 'F';
                            pFat->state[i] = 'B';
                            temp->blockId=i;
                            fragmanted = i+1;
                            temp = temp->next;
                            moved=true;
                            showFat(pFat);
                            cout<<"Fragmentation: "<< getFragmentation(pFat) << " Percent" <<endl;
                        }
                    }
                }
            }
        }
    }

}

int main() {
    BsFat* bd = createBsFat(8192,512);
    showFat(bd);
    bd->state[2] = 'D';
    bd->state[3] = 'R';
    bd->state[6] = 'D';
    bd->state[7] = 'R';
    cout << "Create file" << endl;
    createFile(bd,2,"hallooooo1.txt",1,0,0,0);
    showFat(bd);
    cout << "Create file" << endl;
    createFile(bd,4,"hallo2.txt",1,0,0,0);
    showFat(bd);


    cout << "Create file" << endl;
    createFile(bd,2,"hallo32323.txte",1,0,0,0);
    showFat(bd);

    cout << "Create file" << endl;

    createFile(bd,4,"hallo4.txte",1,0,0,0);
    showFat(bd);
    cout<<"Fragmentation: "<< getFragmentation(bd) << " Percent" <<endl;

    defragDisk(bd);
    cout << "Delead file HALLO2.TXT" << endl;
    deleteFile(bd,"HALLO2.TXT");
    defragDisk(bd);
    return 0;
}