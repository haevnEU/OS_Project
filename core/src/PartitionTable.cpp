#include "../include/PartitionTable.h"

using namespace os_project::hard_disk;

PartitionTable::PartitionTable(void) {
	for (int i = 0; i < MAX_PARTITION; i++) {
		partitions_[i] = nullptr;
	}
}

PartitionTable::~PartitionTable(void) {
	std::cout << "DTOR of PartitionTable is called" << std::endl;

	for (int i = 0; i < MAX_PARTITION; i++) {
		delete(partitions_[i]); 
		partitions_[i] = nullptr;
	}
}

int PartitionTable::addPartition(os_project::hard_disk::Block** blocks, int amountBlocks,
	bool primary, int index, os_project::fileSystem::IFileSystem* fileSystem) {
	int idx = 0;
	for (int i = 0; i < MAX_PARTITION; i++) {
		idx = i;
		if (nullptr == partitions_[i]) {
			partitions_[i] = new Partition(blocks, amountBlocks, primary, i, fileSystem);
			break; 
		}
	}
	return idx;
}

void PartitionTable::addPartition(os_project::hard_disk::Partition* partition_t) {
	int idx = 0;
	for (int i = 0; i < MAX_PARTITION; i++) {
		idx = i;
		if (nullptr == partitions_[i]) {
			partitions_[i] = partition_t;
			break;
		}
	}
}

void PartitionTable::removePartition(int index) {
	if (index >= MAX_PARTITION) {
		return;
	}

	delete(partitions_[index]);
	partitions_[index] = nullptr;
}

os_project::hard_disk::Partition* PartitionTable::getPartition(int index) {
	if (index >= MAX_PARTITION) {
		nullptr;
	}

	return partitions_[index];
}

int os_project::hard_disk::PartitionTable::maxSize(void) {
	return MAX_PARTITION;
}

std::ostream& os_project::hard_disk::operator<<(std::ostream& os, PartitionTable& partitionTable) {

	os << "PartitionTable size: " << partitionTable.maxSize() << std::endl;
	for (int i = 0; i < partitionTable.maxSize(); i++) {
		Partition* partition = partitionTable.getPartition(i);
		if (nullptr != partition) {
			os << "Partition No: " << i << std::endl << *partition << std::endl;
		}
		else {
			os << "Partition No: " << i << std::endl << "Not exist" << std::endl;
		} 
	}
	return os;
}