#ifndef _OS_PROJECT_PARTITION_TABLE_H_
#define _OS_PROJECT_PARTITION_TABLE_H_

#include "Partition.h"
#include "IFileSystem.h"

namespace os_project {
	namespace hard_disk {

		/* 
		 * This class describes a partition table. A partition table contains all partition available on a disk.
		 * To achieve the above requirement this implementation utilizes a vector from the std namespace, 
		 * the second implemented attribute is the current size (however it is possible to substitute this with 
		 * the one from vector class)
		 *
		 * @author Nils Milewski (nimile)
		 * @date July 23 2019
		 * @version 1.0
		 */
		class PartitionTable{
		private: 
			/// This attributes is the size of the table
			#define MAX_PARTITION 4
			/// This attributes contains all partition
			os_project::hard_disk::Partition* partitions_m[MAX_PARTITION];

		public:

			/**
			 * This constructor creates a new partition table it also instantiate all required attributes.
			 */
			PartitionTable(void);

			~PartitionTable(void);

			/**
			 * This method creates a new partition and returns its index inside the table.
			 * The constructor of the partition class will be invoked so this method requires a couple basic 
			 * information about the partition.
			 *
			 * @param blocks This is used to assign blocks from a disk. 
			 * @param amountBlocks This variable states how many blocks are given
			 * @param primary This variable promotes this partition to a primary bootable one
			 * @param index This param is the index at the disk
			 * @param fileSystem This param is the operated file system. For more information see inside @see Definitions.h
			 *
			 * @return Index inside the partitiont able
			 */
			int addPartition(int amountBlocks, int blockSize, bool primary, int index, os_project::definitions::file_system_type fileSystemType);

			/**
			 * This method removes a partition based on an index from the table.
			 *
			 * @param index Index which should be used to remove the partition
			 *
			 * @contract Index must be smaller or equal the size (@size_m) of the table
			 */
			bool removePartition(int index);			
			
			/**
			 * This method returns a partition based on an index from the table.
			 *
			 * @param index Index which should be used to return the partition
			 *
			 * @return Partition from the table based on given index
			 *
			 * @contract Index must be smaller or equal the size (@size_m) of the table
			 */
			os_project::hard_disk::Partition* getPartition(int index);
		
			/**
			 * TODO Write comment
			 */
			friend std::ostream& operator<< (std::ostream& out, PartitionTable& block);

		};
	}
}

#endif // _OS_PROJECT_PARTITION_TABLE_H_
