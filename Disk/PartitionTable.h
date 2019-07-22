#pragma once

#include <vector>

#include "Partition.h"

namespace os_project {
	namespace hard_disk {
		class PartitionTable{
		private: 

			std::vector<os_project::hard_disk::Partition*>* partitions;
			int size_m;

		public:
			PartitionTable(void);
			~PartitionTable(void);

			void addPartition(os_project::hard_disk::Partition* partition_t);
			void removePartition(int index);			
			os_project::hard_disk::Partition* getPartition(int index);
		
		};
	}
}


