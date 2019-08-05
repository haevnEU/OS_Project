#ifndef _OS_PROJECT_DEFINITIONS_H_
#define _OS_PROJECT_DEFINITIONS_H_

namespace os_project {
	namespace definitions {

		/**
		 * This enumeration describes all states of a block
		 * block_free: No data is written on this block, the block is available to write on
		 * block_reserved: This block is marked to be used by the operating system,
		 *				   data will be written on the block soon
		 * block_occupied: Data is written on the block, the block is not available to write on
		 * block_corrupted: The block contains error and is not possible to use anymore
		 */
		enum block_state { block_free, block_reserved, block_occupied, block_corrupted };
		/// This array maps the block_state enumeration to strings
		static const char* block_state_names[] = { "free", "reserved", "occupied", "corrupted" };
		
		/**
		 * This enumeration describes all states of a partition
		 * partition_mounted: The partition is mounted into the operating system and is now allowed to be used. 
		 *					  Modifying the partition is not possible
		 * partition_unmounted: The partition is unmounted from the operating system and cannot be used 
		 *						until a mount operation occur. modification are allowed now.
		 * partition_corrupted: The partition is corrupted and cannot be mounted anymore, all data is lost
		 */
		enum partition_state {partition_mounted, partition_unmounted, partition_corrupted};
		/// This array maps the partition_state enumeration to strings
		static const char* partition_state_names[] = { "mounted", "unmounted", "corrupted"};

		/**
		 * This enumeration is used to differentiate between supported file system, currently supported are FAT and INode
		 * FAT: File Allocation Table file system
		 * INode: Index Node file system
		 */
		enum file_system_type { INode, FAT };
		/// This array maps the file_system_types enumeration to strings
		static const char* file_system_type_names[] = { "INode", "FAT" };
			   
		enum file_system_file_types {file = 0, directory = 1, symbolic_link = 2, 
									 block_special_file = 3, character_special_file = 4,
								     named_pipe_file = 5, loacl_socket_special_file = 6,
									 unknown = 7};
		/// This array maps the file_system_file_types enumeration to strings
		static const char* file_system_file_types_name[] = {"-", "d", "l", "b", "c", "p", "s", "u"};

		enum file_system_groups {Owner, Group, Other};
	}
}

#endif // _OS_PROJECT_DEFINITIONS_H_
