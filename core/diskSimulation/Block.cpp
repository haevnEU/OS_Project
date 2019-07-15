//
// Created by Leon on 14.07.2019.
//

#include "Block.h"

Block::Block(long blockSize) {
    data = new char[blockSize/8];

}

bool Block::getBit(long bitNumm) {
    return data[ bitNumm / 8 ] & (1<<(7-(bitNumm % 8 )));
}

void Block::setBit(long bitNumm, bool value) {

}

Block::~Block() {

}
