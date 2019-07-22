#include "Block.h"

using namespace os_project::hard_disk;

Block::Block(int size, int index) {
	this->state = os_project::definitions::block_state::free;
	this->size = size;
	this->data = 0;
	this->clusterIndex = index;
}

Block::~Block(void) {

}

void Block::setData(char data) {
	this->data = data;
	setState(os_project::definitions::block_state::occupied);
}

void Block::setBit(int pos) {
		this->data[pos / 8] |= (1 << (7 - (pos % 8)));
	}

void Block::clearData(void) {
	setState(os_project::definitions::block_state::free);
	data = 0;
}

void Block::clearBit(int pos) {
	this->data[pos / 8] &= ~(1 << (7 - (pos % 8)));
}

void Block::setState(os_project::definitions::block_state state_t) {
	state = state_t;
}

bool Block::isBitSet(int pos) {
	return data[pos / 8] & (1 << (7 - (pos % 8)));
}

int Block::blockSize(void) {
	return size;
}

void Block::toString(void) {
	std::cout << "Size: " << size << std::endl
		<< "Clusterindex: " << clusterIndex << std::endl
		<< "State: " << state << std::endl
		<< "Data: " << data << std::endl;
}

