//
// Created by Leon on 14.07.2019.
//

#ifndef PROJEKT_BLOCK_H
#define PROJEKT_BLOCK_H


class Block {
private:
    char* data;

public:
    Block(long blockSize);
    bool getBit(long bitNumm);
    void setBit(long bitNumm,bool value);
    ~Block();

    Block();
};


#endif //PROJEKT_BLOCK_H
