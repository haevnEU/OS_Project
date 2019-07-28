#ifndef _OS_PROJECT_INODE_H_
#define _OS_PROJECT_INODE_H_

#include "IFileSystem.h"
namespace os_project {
	namespace fileSystem {
		class INode : public os_project::fileSystem::IFileSystem {

		public:

			INode(void);

			~INode(void);

			int createFile(void);
			
			void deleteFile(void);
			
			void createDirectory(void);
			
			void deleteDirectory(void);

			File* getFile(int index);
			
			std::vector<os_project::fileSystem::File*>* getFiles(void);
		};
	}
}

#endif // _OS_PROJECT_INODE_H_