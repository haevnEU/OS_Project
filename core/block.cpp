#include "block.h"

using namespace logic;

Block::Block(unsigned long size) {
    this->state_m = block_state::free;
    this->blockSize_m = size;
    this->data_m = new unsigned char[size];

    for (int i = 0; i < size; i++) {
        this->data_m[i] = 0;
    }
}

Block::~Block(void) {
    delete(data_m);
    data_m = nullptr;
}

void Block::setState(block_state state_t) {
    state_m = state_t;
}

const block_state Block::state(void) {
    return state_m;
}

int Block::blockSize(void) {
    return blockSize_m;
}

const unsigned char* Block::data(void) {
    return data_m;
}

bool Block::setByte(int offset,char byte) {
    if(offset>blockSize_m) {
        return false;
    }else{
        data_m[offset] = byte;
        return true;
    }
}

char Block::getByte(int offset) {
    if(offset>blockSize_m) {
        return 0;
    }else{
        return data_m[offset];
    }
}



