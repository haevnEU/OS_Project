#pragma once

#include <iostream>
#include <cstdlib>

#include "Definitionsh.h"

namespace os_project {
	namespace hard_disk {
		class Block {
		private:

			char* data;

			int size;
			int clusterIndex;

			os_project::definitions::block_state state;

		public:
			Block(int size, int index);

			~Block(void);

			void setData(char data);

			void setBit(int bit);

			void clearData(void);

			void clearBit(int bit);

			bool isBitSet(int pos);

			void setState(os_project::definitions::block_state state_t);

			int blockSize(void);

			void toString(void);

		};
	}
}