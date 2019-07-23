#include "Partition.h"

using namespace os_project::hard_disk;

Partition::Partition(os_project::hard_disk::Block** blocks, int amountBlocks, bool primary, int index, os_project::fileSystem::IFileSystem* fileSystem) {
	blocks_m = blocks;
	amountBlocks_m = amountBlocks;
	state_m = os_project::definitions::partition_state::partition_unmounted;
	fileSystem_m = fileSystem;
	primary_m = primary;
	index_m = index;
	size_m = amountBlocks_m * blocks[0]->blockSize();
}

Partition::~Partition(void) {
	
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

	os << "Partition: " << partition.index() << " primary: " << (partition.isPrimary() == true ? "true" : "false") << std::endl
		// TODO BUG os prints 800 instead of 2048
		<< "Filesystem: " << partition.fileSystem() << " Size: " << partition.size_m << " amount blocks: " << partition.amountBlocks() << std::endl;

	for (int i = 0; i < partition.amountBlocks(); i++) {
		std::cout << *partition.getBlock(i) << std::endl;
	}
	return os;
}

