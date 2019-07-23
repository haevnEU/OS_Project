#include "../include/Block.h"

using namespace os_project::hard_disk;

Block::Block(int size, int index) {
	this->state = os_project::definitions::block_state::block_free;
	this->size = size;
	this->data = new unsigned char[size];
	for (int i = 0; i < size; i++) {
		this->data[i] = 0;
	}
	this->clusterIndex = index;
}

Block::~Block(void) {
	delete(data);
}

void Block::setData(const unsigned char* data) {
	this->data = const_cast<unsigned char*>(data);
	setState(os_project::definitions::block_state::block_occupied);
}

void Block::setBit(int pos) {
		this->data[pos / 8] |= (1 << (7 - (pos % 8)));
	}

void Block::clearData(void) {
	setState(os_project::definitions::block_state::block_free);
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

const unsigned char* Block::getData(void) {
	return data;
}

const int Block::getSize(void) {
	return size;
}

const int Block::getClusterIndex(void) {
	return clusterIndex;
}

const os_project::definitions::block_state Block::getState(void) {
	return state;
}

std::ostream& os_project::hard_disk::operator<<(std::ostream& os, Block& block){
	os << "Block" << std::endl 
		<< "Size: " << block.getSize() << std::endl
		<< "State: " << block.getState() << std::endl
		<< "Cluster index: " << block.getClusterIndex() << std::endl
		<< "Data: " << std::endl;
	
	for (int i = 0; i < block.getSize(); i++) {
		os << std::setw(2) << std::setfill('0') << std::hex << std::uppercase << ((int)block.getData()[i]) << " ";
	}
	os << std::endl;
	return os;
}



