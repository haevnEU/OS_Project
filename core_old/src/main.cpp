#include <iostream>
#include <string>

#include "../include/Block.h"
#include "../include/Definitionsh.h"
#include "../include/File.h"
#include "../include/IFileSystem.h"
#include "../include/Partition.h"
#include "../include/PartitionTable.h"
#include "../include/Disk.h"

#include "../include/File.h"

#include "../include/INode.h"
#include "../include/INodeTable.h"

#define DEBUG

int main(int argc, const char* argv[]) {


	os_project::fileSystem::INodeTable* tbl = new os_project::fileSystem::INodeTable(512, 5);
	   	  


	tbl->getINode(0)->createFile("Hello", "out", 0, 0, os_project::definitions::file_system_file_types::file);
	tbl->getINode(1)->createFile("", "tmp", 1, 1, os_project::definitions::file_system_file_types::block_special_file);

	tbl->getINode(0)->data();
	tbl->getINode(0)->changeExtension("out");
	tbl->getINode(0)->changeName("Hello");
	tbl->getINode(0)->changeGID(0);
	tbl->getINode(0)->changeUID(1);


	std::cout << *tbl->getINode(0) << std::endl;
	std::cout << *tbl->getINode(1) << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << *tbl << std::endl;


	return 0;





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