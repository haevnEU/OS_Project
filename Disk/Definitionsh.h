#pragma once
namespace os_project {
	namespace definitions {
		enum block_state { free, reserved, occupied, corrupted };
		enum partition_state {mounted, unmounted, corrupted};
		enum file_system{INode, FAT};
	}
}
