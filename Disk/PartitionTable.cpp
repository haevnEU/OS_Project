#include "PartitionTable.h"

using namespace os_project::hard_disk;

PartitionTable::PartitionTable(void) {
	size_m = 0;
	partitions = new std::vector<Partition*>();
}

PartitionTable::~PartitionTable(void) {
	partitions->clear();
	delete(partitions);
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
