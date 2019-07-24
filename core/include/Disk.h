#ifndef _OS_PROJECT_DISK_H_
#define _OS_PROJECT_DISK_H_

#include <iostream>

#include "PartitionTable.h"

namespace os_project {
	namespace hard_disk {

		class Disk {
		private:
			char manufactor[16];
			long disk_size;
			os_project::hard_disk::PartitionTable* partitionTable;

		public:
			Disk(const char* manufactor, long disk_size);

			~Disk(void);

			const char* getManufactor(void);

			const long getDiskSize(void);

			os_project::hard_disk::PartitionTable* getPartitionTable(void);

			/**
			 * TODO write comment
			 */
			friend std::ostream& operator<< (std::ostream& os, Disk& disk);
		};
	}
}

#endif // _OS_PROJECT_DISK_H_
