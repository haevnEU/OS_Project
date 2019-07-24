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
	os_project::hard_disk::Block** block1 = new os_project::hard_disk::Block * [2];
	for (int i = 0; i < 2; i++) {
		block1[i] = new os_project::hard_disk::Block(512, i);
	}


	os_project::hard_disk::Block** block2 = new os_project::hard_disk::Block * [4];
	for (int i = 0; i < 4; i++) {
		block2[i] = new os_project::hard_disk::Block(1024, i);
	}
	
	os_project::hard_disk::Disk* disk = new os_project::hard_disk::Disk("Computer inc", 1099511627776);

	disk->getPartitionTable()->addPartition(block1, 2, true, 0, nullptr);
	disk->getPartitionTable()->addPartition(block2, 4, false, 0, nullptr);

	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(0);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(1);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->clearBit(2);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(3);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(4);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(5);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(6);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->clearBit(7);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(8);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->clearBit(9);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(0);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(10);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->clearBit(11);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(12);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(13);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->clearBit(14);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(15);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(16);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->clearBit(17);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(18);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(19);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(20);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(21);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(22);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->clearBit(23);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(24);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(25);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(26);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->clearBit(27);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(28);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(29);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(30);
	disk->getPartitionTable()->getPartition(0)->getBlock(0)->setBit(31);
	

	std::cout << *disk << std::endl;
	std::cout << std::endl << std::endl << "Destruct disk " << std::endl;
	delete(disk);
}