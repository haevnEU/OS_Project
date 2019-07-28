#ifndef _OS_PROJECT_DISK_H_
#define _OS_PROJECT_DISK_H_

#include <iostream>

#include "PartitionTable.h"
#include "Block.h"

namespace os_project {
	namespace hard_disk {

		class Disk {
		private:
			char manufactor[16];
			long long disk_size;
			long long free_space;
			os_project::hard_disk::PartitionTable* partitionTable;

		public:
			Disk(const char* manufactor, long long disk_size);

			~Disk(void);

			const char* getManufactor(void);

			const long getDiskSize(void);

			// TODO Switch IFilesytem with enumerator
			bool createPartition(int blockSize, int amountBlocks, bool primary, int index, os_project::definitions::file_system_type fs);

			Partition* getPartition(int index);

			bool erasePartition(int index);

			//os_project::hard_disk::PartitionTable* getPartitionTable(void);

			/**
			 * TODO write comment
			 */
			friend std::ostream& operator<< (std::ostream& os, Disk& disk);
		};
	}
}

#endif // _OS_PROJECT_DISK_H_
