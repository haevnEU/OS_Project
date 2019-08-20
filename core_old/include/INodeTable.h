#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "INode.h"

#include "IFileSystem.h"

namespace os_project {
	namespace fileSystem {

		class INodeTable : public IFileSystem {
		
		private:
			std::vector<INode*>* inodes_m;
		public:
			INodeTable(void);

			INodeTable(int blockSize, int size);

			~INodeTable(void);

			int createFile(const char* name, const char* extension, int uid);
			void deleteFile(void);
			void createDirectory(void);
			void deleteDirectory(void);

			File* getFile(int index);

			INode* getINode(int index);
			
			/**
			 * TODO write comment
			 */
			friend std::ostream& operator<< (std::ostream& out, INodeTable& inodeTable);
		};

	}
}

