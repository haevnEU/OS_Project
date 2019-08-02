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

	disk->getPartition(0)->getBlock(0)->setHex(0xDE, 0);
	disk->getPartition(0)->getBlock(1)->setBin(0b11011110, 0);
	
	disk->getPartition(0)->getBlock(0)->setHex(0xAD, 1);
	disk->getPartition(0)->getBlock(1)->setBin(0b10101101, 1);

	disk->getPartition(0)->getBlock(0)->setHex(0xBE, 2); 
	disk->getPartition(0)->getBlock(1)->setBin(0b10111110, 2);

	disk->getPartition(0)->getBlock(0)->setHex(0xEF, 3);
	disk->getPartition(0)->getBlock(1)->setBin(0b10101111, 3);

	std::cout << (*disk->getPartition(0)->getBlock(0)) << std::endl;
	std::cout << (*disk->getPartition(0)->getBlock(1)) << std::endl;
	
	std::cout << *disk << std::endl;
	std::cout << std::endl << std::endl << "Destruct disk " << std::endl;
	delete(disk);
}