#include "../include/Disk.h"

using namespace os_project::hard_disk;

Disk::Disk(const char* manufactor, long disk_size) {
	this->disk_size = disk_size;	
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

PartitionTable* Disk::getPartitionTable(void) {
	return partitionTable;
}

std::ostream& os_project::hard_disk::operator<< (std::ostream& os, Disk& disk) {
	os << "Disk: " << disk.getManufactor() << std::endl
		<< "Size: " << disk.getDiskSize() << std::endl
		<< "Partition table: " << std::endl << *disk.getPartitionTable() << std::endl;
	return os;
}