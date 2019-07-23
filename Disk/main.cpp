#include <iostream>

#include "Block.h"
#include "Definitionsh.h"
#include "File.h"
#include "IFileSystem.h"
#include "Partition.h"
#include "PartitionTable.h"



int main(int argc, const char* argv[]) {
	os_project::hard_disk::Block** block1 = new os_project::hard_disk::Block * [2];
	for (int i = 0; i < 2; i++) {
		block1[i] = new os_project::hard_disk::Block(512, i);
	}


	os_project::hard_disk::Block** block2 = new os_project::hard_disk::Block * [4];
	for (int i = 0; i < 4; i++) {
		block2[i] = new os_project::hard_disk::Block(512, i);
	}
	
	os_project::hard_disk::PartitionTable* table = new os_project::hard_disk::PartitionTable();
	table->addPartition(block1, 2, true, 0, nullptr);
	table->addPartition(block2, 4, true, 0, nullptr);

	std::cout << *table << std::endl;
}