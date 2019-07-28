#ifndef _OS_PROJECT_PARTITION_H_
#define _OS_PROJECT_PARTITION_H_

#include "Block.h"
#include "IFileSystem.h"
#include "INode.h"

namespace os_project {
	namespace hard_disk {

		/* 
		 * This class contains a definition for a partition. A partition contains a fixed amount of block, 
		 * fixed size and a disk index.
		 * The amount of blocks is dynamically calculated.
		 * A partition must not be a primary but a disk must contain a primary partition.
		 * A partition also contains a file system.
		 *
		 * @author Nils Milewski (nimile)
		 * @date July 23 2019
		 * @version 1.0
		 */
		class Partition{
		private:

			/// ...
			os_project::hard_disk::Block** blocks_m;
			
			/// This variable describes the state of a disk. All possible state can be seen inside @see Defintions.h
			os_project::definitions::partition_state state_m;

			/// This variable is used for the file system
			os_project::fileSystem::IFileSystem* fileSystem_m;

			/// This variable describes if the partition is a primary one
			bool primary_m;

			/// This variable is the disk index from the partition
			int index_m;

			/// This variable contains the disk size
			int size_m;

			/// This variable is dynamically calculated during creation and states how many blocks exist
			int amountBlocks_m;

			int blockSize_m;

		public:

			/**
			 * This constructor creates a new partition with given blocks and the amount blocks. 
			 * It is possible to promote this partition to a primary one, the operated files system is also used
			 *
			 * @param blocks This is used to assign blocks from a disk. 
			 * @param amountBlocks This variable states how many blocks are given
			 * @param primary This variable promotes this partition to a primary bootable one
			 * @param index This param is the index at the disk
			 * @param fileSystem This param is the operated file system. For more information see inside @see Definitions.h
			 */
			Partition(int amountBlocks, int blockSize, bool primary, int index, os_project::definitions::file_system_type fileSystem);

			~Partition(void);

			/**
			 * This method mounts the partition to the operating system. Note the state will be set to mount
			 */
			void mount(void);

			/**
			 * This method unmounts the partition from the operating system. Note the state will be set to unmount
			 */
			void unmount(void);

			/**
			 * This method returns a block from the partition.
			 *
			 * @param index Index from the block
			 *
			 * @return Pointer to the block which is associated with index
			 */
			os_project::hard_disk::Block* getBlock(int index);

			/**
			 * This method returns all blocks from the partition
			 *
			 * @return Array of pointer to all blocks
			 */
			os_project::hard_disk::Block** getBlocks(void);

			/**
			 * This method returns the state of the partition. 
			 * To get details about the state @see Definitions.h
			 *
			 * @return State of the partition
			 */
			os_project::definitions::partition_state state(void);

			/**
			 * This method returns the underlying file system
			 *
			 * @return File system which is used to operate the partition
			 */
			os_project::fileSystem::IFileSystem* fileSystem(void);

			/**
			 * This method tests the partition about its primary state, if it is set to true the method returns true
			 *
			 * @return true iff the partition is a primary one
			 */
			bool isPrimary();

			/**
			 * This method will return the index at the disk
			 *
			 * @return Disk index from the partition
			 */
			int index(void);

			/**
			 * This method returns the total amount of size
			 *
			 * @return amount of space
			 */
			int size(void);

			/**
			 * This method returns the amount of blocks used by the partition
			 *
			 * @return amount of used blocks
			 */
			int amountBlocks(void);
			
			/**
			 * TODO write comment
			 */
			friend std::ostream& operator<< (std::ostream& out, Partition& block);

		};
	}
}

#endif // _OS_PROJECT_PARTITION_H_
