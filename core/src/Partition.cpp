#include "../include/Partition.h"

using namespace os_project::hard_disk;

Partition::Partition(int amountBlocks, int blockSize,
	bool primary, int index, os_project::definitions::file_system_type fileSystem) {

	this->blockSize_m = blockSize;
	this->amountBlocks_m = amountBlocks;

	blocks_m = new Block * [amountBlocks];
	for (int i = 0; i < amountBlocks; i++) {
		blocks_m[i] = new Block(blockSize, i);
	}
	amountBlocks_m = amountBlocks;
	state_m = os_project::definitions::partition_state::partition_unmounted;
	
	primary_m = primary;
	index_m = index;
	size_m = amountBlocks_m * blockSize;

	switch (fileSystem) {
	case os_project::definitions::file_system_type::FAT:
		// TODO Add FAT
		break;
	case os_project::definitions::file_system_type::INode:
		fileSystem_m = new os_project::fileSystem::INode();
		break;

	}
}

Partition::~Partition(void) {
	std::cout << "DTOR of Partition is called" << std::endl;

	for (int i = 0; i < amountBlocks_m; i++) {
		std::cout << "DTOR of " << i << std::endl;
		delete(blocks_m[i]);
		blocks_m[i] = nullptr;
	}
	delete(blocks_m);
	blocks_m = nullptr;

	delete(fileSystem_m);
	fileSystem_m = nullptr;
}

void Partition::mount(void) {
	state_m = os_project::definitions::partition_state::partition_mounted;
}

void Partition::unmount(void) {
	state_m = os_project::definitions::partition_state::partition_unmounted;
}

Block* Partition::getBlock(int index) {
	if (index >= amountBlocks_m) {
		return nullptr;
	}
	return blocks_m[index];
}

Block** Partition::getBlocks(void) {
	return blocks_m;
}

os_project::definitions::partition_state Partition::state(void) {
	return state_m;
}

os_project::fileSystem::IFileSystem* Partition::fileSystem(void) {
	return fileSystem_m;
}

bool Partition::isPrimary(void) {
	return primary_m;
}

int Partition::index(void) {
	return index_m;
}

int Partition::size(void) {
	return size_m;
}

int Partition::amountBlocks(void) {
	return amountBlocks_m;
}

std::ostream& os_project::hard_disk::operator<< (std::ostream& os, Partition& partition) {

	os << "Partition: " << partition.index() << " primary: " << (partition.primary_m == true ? "true" : "false") << std::endl
		// TODO BUG os prints 800 instead of 2048
		<< "File system: " << os_project::definitions::file_system_type_names[partition.fileSystem()->getType()]
		<< " Size: " << partition.size_m << " amount blocks: " << partition.amountBlocks() << std::endl;

	for (int i = 0; i < partition.amountBlocks(); i++) {
		std::cout << *partition.getBlock(i) << std::endl;
	}
	return os;
}

