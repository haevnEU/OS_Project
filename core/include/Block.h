#ifndef _OS_PROJECT_BLOCK_H_
#define _OS_PROJECT_BLOCK_H_

#include <iostream>
#include <cstdlib>
#include <bitset>
#include <iomanip>

#include "Definitionsh.h"

namespace os_project {
	namespace hard_disk {
		class Block {
		private:
			
			unsigned char* data;

			int size;
			int clusterIndex;

			os_project::definitions::block_state state;

		public:
			Block(int size, int index);

			~Block(void);

			void setData(const unsigned char* data);

			void setBit(int bit);

			void clearData(void);

			void clearBit(int bit);

			bool isBitSet(int pos);

			void setState(os_project::definitions::block_state state_t);

			int blockSize(void);


			const unsigned char* getData(void);

			const int getSize(void);
			const int getClusterIndex(void);

			const os_project::definitions::block_state getState(void);

			friend std::ostream& operator<< (std::ostream& out, Block& block);

		};

	
		
	}
}

#endif //_OS_PROJECT_BLOCK_H_
