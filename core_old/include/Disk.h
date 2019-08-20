#ifndef _OS_PROJECT_DISK_H_
#define _OS_PROJECT_DISK_H_

#include <iostream>

#include "PartitionTable.h"
#include "Block.h"

namespace os_project {
	namespace hard_disk {

		class Disk {
		private:
			/// This variable contains the manufacturer name, it will not be null terminated
			char manufactor_m[16];

			/// This variable is the actual disk size, it will not be modified after creation
			long long diskSize_m;

			/// This variable is the total, not occupied, available disk size
			long long freeSpace_m;

			/// This variable contains all partition, the table contains only 4 entries
			os_project::hard_disk::PartitionTable* partitionTable_m;

		public:

			/**
			 * This method create a new Disk with given disk size and manufacturer name. 
			 * It will also initialize the partition table.
			 */
			Disk(const char* manufactor, long long diskSize);

			~Disk(void);

			/**
			 * This method returns the manufacturer name, important the returned string is not null terminated
			 *
			 * @return const char* to the manufacturer name
			 */
			const char* getManufactor(void);

			/**
			 * This method receives the total disk size from the disk
			 *
			 * @return The total disk size will be returned as a cons int 
			 */
			const long diskSize(void);

			/**
			 * This method creates a new partition with given block size, amount blocks, 
			 *	filesystem and index it will also add it into the partition table
			 * 
			 * @return false iff the disk size has enough free space and the partition table will not exceed 4 entries.
			 */
			bool createPartition(int blockSize, int amountBlocks, bool primary, int index, os_project::definitions::file_system_type fs);
			 
			/**
			 * This method will be used to retreive a specifc partition
			 *
			 * @param index Index of the partition inside the partition table,
			 *			the index must be smaller than 4 and must be pointing to a valid index
			 *
			 * @return Partition based on given index
			 */
			Partition* getPartition(int index);

			/**
			 * This method erases a partition from the disk, the space will be available for new partition
			 *
			 * @param index Index of the partition inside the partition table,
			 *			the index must be smaller than 4 and must be pointing to a valid index
			 *
			 * @return true iff the partition was successfully erased
			 */
			bool erasePartition(int index);

			/**
			 * TODO write comment
			 */
			friend std::ostream& operator<< (std::ostream& os, Disk& disk);
		};
	}
}

#endif // _OS_PROJECT_DISK_H_
