#pragma once
namespace os_project {
	namespace definitions {
		enum block_state { block_free, block_reserved, block_occupied, block_corrupted };
		static const char* block_state_names[] = { "free", "reserved", "occupied", "corrupted" };
		
		enum partition_state {partition_mounted, partition_unmounted, partition_corrupted};
		static const char* partition_state_names[] = { "mounted", "unmounted", "corrupted"};

		enum file_system_type { INode, FAT };
		static const char* file_system_type_names[] = { "INode", "FAT" };


	}
}
