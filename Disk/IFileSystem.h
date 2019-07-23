#pragma once

#include <vector>

#include "File.h"
#include "Definitionsh.h"

namespace os_project {



	namespace fileSystem {
		class IFileSystem{
		private:

			std::vector<os_project::fileSystem::File*>* files;
			os_project::definitions::file_system_type file_system_type;
		public:
			IFileSystem(os_project::definitions::file_system_type file_system_type);
			virtual ~IFileSystem(void);
			virtual void createFile(void) = 0;
			virtual void deleteFile(void) = 0;
			virtual void createDirectory(void) = 0;
			virtual void deleteDirectory(void) = 0;
		
			virtual File* getFile(int index) = 0;
			virtual std::vector<os_project::fileSystem::File*> getFiles(void) = 0;

			os_project::definitions::file_system_type getType(void);
		};

	}
}
