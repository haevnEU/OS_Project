#include "../include/PartitionTable.h"


using namespace os_project::hard_disk;



PartitionTable::PartitionTable(void) {
	size_m = 0;
	partitions = new std::vector<Partition*>();
}

PartitionTable::~PartitionTable(void) {
	partitions->clear();
	delete(partitions);
}

int PartitionTable::addPartition(os_project::hard_disk::Block** blocks, int amountBlocks, bool primary, int index, os_project::fileSystem::IFileSystem* fileSystem) {
	size_m++;
	partitions->push_back(new Partition(blocks, amountBlocks, primary, index, fileSystem));
	return size_m;
}

void PartitionTable::addPartition(os_project::hard_disk::Partition* partition_t) {
	size_m++;
	partitions->push_back(partition_t);
}

void PartitionTable::removePartition(int index) {
	if (index >= size_m) {
		return;
	}
	size_m--;
	partitions->erase(partitions->begin() + index);
}

os_project::hard_disk::Partition* PartitionTable::getPartition(int index) {
	if (index >= size_m) {
		nullptr;
	}
	return partitions->at(index);
}

int os_project::hard_disk::PartitionTable::size(void) {
	return size_m;
}

std::ostream& os_project::hard_disk::operator<<(std::ostream& os, PartitionTable& partitionTable) {

	os << "PartitionTable size: " << partitionTable.size() << std::endl;
	for (int i = 0; i < partitionTable.size(); i++) {
		os << *partitionTable.getPartition(i) << std::endl;
	}
	return os;
}