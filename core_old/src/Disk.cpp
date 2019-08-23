#include "../include/Disk.h"

using namespace os_project::hard_disk;

Disk::Disk(const char* manufactor, long long disk_size) {
	this->diskSize_m = disk_size; 
	this->freeSpace_m = disk_size;
	snprintf(this->manufactor_m, 16, "%s", manufactor);
	partitionTable_m = new PartitionTable();
}

Disk::~Disk(void) {
	std::cout << "DTOR of Disk is called" << std::endl;

	delete(partitionTable_m);
	partitionTable_m = nullptr;
}

const char* Disk::getManufactor(void) {
	return manufactor_m;
}

const long Disk::diskSize(void) {
	return diskSize_m;
}

bool Disk::createPartition(int blockSize, int amountBlocks, bool primary, int index, os_project::definitions::file_system_type fs) {
	if (freeSpace_m < (blockSize * amountBlocks)) {
		return false;
	}
	partitionTable_m->addPartition(amountBlocks, blockSize, primary, index, fs);
	freeSpace_m -= blockSize * amountBlocks;
}

Partition* Disk::getPartition(int index) {
	return partitionTable_m->getPartition(index);
}

bool Disk::erasePartition(int index) {
	return partitionTable_m->removePartition(index);
}

std::ostream& os_project::hard_disk::operator<< (std::ostream& os, Disk& disk) {

	double percentage = (disk.freeSpace_m * 100) / disk.diskSize_m;

	os << "Disk: " << disk.getManufactor() << std::endl
		<< "Size: " << disk.diskSize_m << std::endl
		<< "Not assigned space: " << disk.freeSpace_m << "(" << (percentage * 1) << "%)" << std::endl 
		<< "Partition table: " << std::endl << *disk.partitionTable_m << std::endl;
	return os;


}