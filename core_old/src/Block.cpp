#include "../include/Block.h"

using namespace os_project::hard_disk;

Block::Block(int size, int index) {
	this->state_m = os_project::definitions::block_state::block_free;
	this->blockSize_m = size;
	this->clusterIndex_m = index;
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
	setState(os_project::definitions::block_state::block_free);
	data_m = 0;
}

bool Block::isBitSet(int pos) {
	return data_m[pos / 8] & (1 << (7 - (pos % 8)));
}

void Block::setState(os_project::definitions::block_state state_t) {
	state_m = state_t;
}

const os_project::definitions::block_state Block::getState(void) {
	return state_m;
}

int Block::blockSize(void) {
	return blockSize_m;
}

const unsigned char* Block::getData(void) {
	return data_m;
}

const int Block::getClusterIndex(void) {
	return clusterIndex_m;
}

std::ostream& os_project::hard_disk::operator<<(std::ostream& os, Block& block){
	os << "Block" << std::endl 
		<< "Size: " << block.blockSize() << std::endl
		<< "State: " << os_project::definitions::block_state_names[block.getState()] << std::endl
		<< "Cluster index: " << block.getClusterIndex() << std::endl
		<< "Data: " << std::endl;
	
	for (int i = 0; i < block.blockSize(); i++) {
		os << std::setw(2) << std::setfill('0') << std::hex << std::uppercase << ((int)block.getData()[i]) << std::dec << " ";
	}
	os << std::endl;
	return os;
}



