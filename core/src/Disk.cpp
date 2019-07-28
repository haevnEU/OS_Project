#include "../include/Disk.h"

using namespace os_project::hard_disk;

Disk::Disk(const char* manufactor, long long disk_size) {
	this->disk_size = disk_size; 
	this->free_space = disk_size;
	snprintf(this->manufactor, 16, "%s", manufactor);
	partitionTable = new PartitionTable();
}

Disk::~Disk(void) {
	std::cout << "DTOR of Disk is called" << std::endl;

	delete(partitionTable);
	partitionTable = nullptr;
}

const char* Disk::getManufactor(void) {
	return manufactor;
}

const long Disk::getDiskSize(void) {
	return disk_size;
}

bool Disk::createPartition(int blockSize, int amountBlocks, bool primary, int index, os_project::definitions::file_system_type fs) {
	if (free_space < (blockSize * amountBlocks)) {
		return false;
	}
	partitionTable->addPartition(amountBlocks, blockSize, primary, index, fs);
	free_space -= blockSize * amountBlocks;
}

Partition* Disk::getPartition(int index) {
	return partitionTable->getPartition(index);
}

bool Disk::erasePartition(int index) {
	return partitionTable->removePartition(index);
}

std::ostream& os_project::hard_disk::operator<< (std::ostream& os, Disk& disk) {

	double percentage = (disk.free_space * 100) / disk.disk_size;

	os << "Disk: " << disk.getManufactor() << std::endl
		<< "Size: " << disk.disk_size << std::endl
		<< "Not assigned space: " << disk.free_space << "(" << (percentage * 1) << "%)" << std::endl 
		<< "Partition table: " << std::endl << *disk.partitionTable << std::endl;
	return os;


}