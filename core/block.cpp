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

void Block::setBit(int pos) {
    if (pos < blockSize_m) {
        this->data_m[pos / 8] |= (1 << (7 - (pos % 8)));
    }
}

void Block::setBin(int bin, int offset) {
    setHex(bin, offset);
}

void Block::setHex(int hex, int offset) {

    offset *= 8;
    int pos = 0;
    for (int i = 0; i < 8; i++) {
        pos = (offset + i);
        // Test if bit is set
        if (hex & (1 << i)) {
            this->data_m[pos / 8] |= (1 << (pos % 8));
        }
        else {
            this->data_m[pos / 8] &= ~(1 << (pos % 8));
        }
    }

}

void Block::clearBit(int pos) {
    if (pos < blockSize_m) {
        this->data_m[pos / 8] &= ~(1 << (7 - (pos % 8)));
    }
}

void Block::clearData(void) {
    setState(block_state::free);
    data_m = 0;
}

bool Block::isBitSet(int pos) {
    return data_m[pos / 8] & (1 << (7 - (pos % 8)));
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

std::ostream& logic::operator<<(std::ostream& os, Block& block){

    return os;
}



