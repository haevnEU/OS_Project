#pragma once

#include <vector>

#include "Partition.h"
#include "IFileSystem.h"

namespace os_project {
	namespace hard_disk {
		class PartitionTable{
		private: 

			std::vector<os_project::hard_disk::Partition*>* partitions;
			int size_m;

		public:
			PartitionTable(void);
			~PartitionTable(void);

			int size(void);

			void addPartition(os_project::hard_disk::Partition* partition_t);
			int addPartition(os_project::hard_disk::Block** blocks, int amountBlocks, bool primary, int index, os_project::fileSystem::IFileSystem* fileSystem);
			void removePartition(int index);			
			os_project::hard_disk::Partition* getPartition(int index);
		
			friend std::ostream& operator<< (std::ostream& out, PartitionTable& block);

		};
	}
}


