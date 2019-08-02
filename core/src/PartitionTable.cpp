#include "../include/PartitionTable.h"

using namespace os_project::hard_disk;

PartitionTable::PartitionTable(void) {
	for (int i = 0; i < MAX_PARTITION; i++) {
		partitions_m[i] = nullptr;
	}
}

PartitionTable::~PartitionTable(void) {
	std::cout << "DTOR of PartitionTable is called" << std::endl;

	for (int i = 0; i < MAX_PARTITION; i++) {
		delete(partitions_m[i]); 
		partitions_m[i] = nullptr;
	}
}

int PartitionTable::addPartition(int amountBlocks, int blockSIze, bool primary, int index, os_project::definitions::file_system_type fileSystem) {
	int idx = 0;
	for (int i = 0; i < MAX_PARTITION; i++) {
		idx = i;
		if (nullptr == partitions_m[i]) {
			partitions_m[i] = new Partition(amountBlocks, blockSIze, primary, i, fileSystem);
			break; 
		}
	}
	return idx;
}

bool PartitionTable::removePartition(int index) {
	if (index >= MAX_PARTITION) {
		return false;
	}

	delete(partitions_m[index]);
	partitions_m[index] = nullptr;
	
	return true;
}

os_project::hard_disk::Partition* PartitionTable::getPartition(int index) {
	if (index >= MAX_PARTITION) {
		nullptr;
	}

	return partitions_m[index];
}

std::ostream& os_project::hard_disk::operator<<(std::ostream& os, PartitionTable& partitionTable) {

	os << "PartitionTable size: " << MAX_PARTITION << std::endl;
	for (int i = 0; i < MAX_PARTITION; i++) {
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