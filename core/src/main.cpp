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

#define DEBUG

int main(int argc, const char* argv[]) {


	os_project::fileSystem::File* f = new os_project::fileSystem::File(10, "TEST", "exe", 0b11110000, 0, 0b1111111111111111, 0b0000000000000000);

	os_project::fileSystem::INode* f2 = new os_project::fileSystem::INode(512);// (10, "TEST", "exe2", 0b11110000, 0, 0b1111111111111111, 0b0000000000000000);
	os_project::fileSystem::INode* f3 = new os_project::fileSystem::INode(512);// (10, "TEST", "exe2", 0b11110000, 0, 0b1111111111111111, 0b0000000000000000);
	f2->createFile("Hello", "out", 0, 0, os_project::definitions::file_system_file_types::file);
	f3->createFile("", "tmp", 1, 1, os_project::definitions::file_system_file_types::block_special_file);

	f2->data();
	f2->changeExtension("out");
	f2->changeName("Hello");
	f2->changeGID(0);
	f2->changeUID(1);


	std::cout << *f2 << std::endl;
	std::cout << *f3 << std::endl;




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