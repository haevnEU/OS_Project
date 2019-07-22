#pragma once

#include "Block.h"

namespace os_project {
	namespace hard_disk {
		class Partition{
		private:
			os_project::hard_disk::Block** blocks_m;
			os_project::definitions::partition_state state_m;
			os_project::definitions::file_system fileSystem_m;
			bool primary_m;
			int index_m;
			int size_m;
			int amountBlocks_m;
		public:

			Partition(os_project::hard_disk::Block** blocks, int amountBlocks, bool primary, int index, os_project::definitions::file_system fileSystem);

			~Partition(void);

			void mount(void);

			void unmount(void);

			os_project::hard_disk::Block* getBlock(int index);

			os_project::hard_disk::Block** getBlocks(void);

			os_project::definitions::partition_state state(void);

			os_project::definitions::file_system fileSystem(void);

			bool isPrimary();

			int index(void);

			int size(void);

			int amountBlocks(void);

		};
	}
}
