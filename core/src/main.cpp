#include <iostream>

#include "../include/Block.h"
#include "../include/Definitionsh.h"
#include "../include/File.h"
#include "../include/IFileSystem.h"
#include "../include/Partition.h"
#include "../include/PartitionTable.h"
#include "../include/Disk.h"

#define DEBUG

int main(int argc, const char* argv[]) {

	os_project::hard_disk::Disk* disk = new os_project::hard_disk::Disk("Computer inc", 128000);

	disk->createPartition(512, 50, true, 0, os_project::definitions::file_system_type::INode);
	disk->createPartition(1024, 50, false, 1, os_project::definitions::file_system_type::INode);
	

	disk->getPartition(0)->getBlock(0)->setBit(0);
	disk->getPartition(0)->getBlock(0)->setBit(1);
	disk->getPartition(0)->getBlock(0)->clearBit(2);
	disk->getPartition(0)->getBlock(0)->setBit(3);
	disk->getPartition(0)->getBlock(0)->setBit(4);
	disk->getPartition(0)->getBlock(0)->setBit(5);
	disk->getPartition(0)->getBlock(0)->setBit(6);
	disk->getPartition(0)->getBlock(0)->clearBit(7);
	disk->getPartition(0)->getBlock(0)->setBit(8);
	disk->getPartition(0)->getBlock(0)->clearBit(9);
	disk->getPartition(0)->getBlock(0)->setBit(0);
	disk->getPartition(0)->getBlock(0)->setBit(10);
	disk->getPartition(0)->getBlock(0)->clearBit(11);
	disk->getPartition(0)->getBlock(0)->setBit(12);
	disk->getPartition(0)->getBlock(0)->setBit(13);
	disk->getPartition(0)->getBlock(0)->clearBit(14);
	disk->getPartition(0)->getBlock(0)->setBit(15);
	disk->getPartition(0)->getBlock(0)->setBit(16);
	disk->getPartition(0)->getBlock(0)->clearBit(17);
	disk->getPartition(0)->getBlock(0)->setBit(18);
	disk->getPartition(0)->getBlock(0)->setBit(19);
	disk->getPartition(0)->getBlock(0)->setBit(20);
	disk->getPartition(0)->getBlock(0)->setBit(21);
	disk->getPartition(0)->getBlock(0)->setBit(22);
	disk->getPartition(0)->getBlock(0)->clearBit(23);
	disk->getPartition(0)->getBlock(0)->setBit(24);
	disk->getPartition(0)->getBlock(0)->setBit(25);
	disk->getPartition(0)->getBlock(0)->setBit(26);
	disk->getPartition(0)->getBlock(0)->clearBit(27);
	disk->getPartition(0)->getBlock(0)->setBit(28);
	disk->getPartition(0)->getBlock(0)->setBit(29);
	disk->getPartition(0)->getBlock(0)->setBit(30);
	disk->getPartition(0)->getBlock(0)->setBit(31);
	

	std::cout << *disk << std::endl;
	std::cout << std::endl << std::endl << "Destruct disk " << std::endl;
	delete(disk);
}