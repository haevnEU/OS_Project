#ifndef _OS_PROJECT_PARTITION_H_
#define _OS_PROJECT_PARTITION_H_

#include "Block.h"
#include "IFileSystem.h"

namespace os_project {
	namespace hard_disk {
		class Partition{
		private:
			os_project::hard_disk::Block** blocks_m;
			os_project::definitions::partition_state state_m;
			os_project::fileSystem::IFileSystem* fileSystem_m;
			bool primary_m;
			int index_m;
			int size_m;
			int amountBlocks_m;
		public:

			Partition(os_project::hard_disk::Block** blocks, int amountBlocks, bool primary, int index, os_project::fileSystem::IFileSystem* fileSystem);

			~Partition(void);

			void mount(void);

			void unmount(void);

			os_project::hard_disk::Block* getBlock(int index);

			os_project::hard_disk::Block** getBlocks(void);

			os_project::definitions::partition_state state(void);

			os_project::fileSystem::IFileSystem* fileSystem(void);

			bool isPrimary();

			int index(void);

			int size(void);

			int amountBlocks(void);
			
			friend std::ostream& operator<< (std::ostream& out, Partition& block);

		};
	}
}

#endif // _OS_PROJECT_PARTITION_H_
