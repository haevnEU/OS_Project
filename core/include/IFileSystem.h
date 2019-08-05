#ifndef _OS_PROJECT_IFILESYSTEM_H_
#define _OS_PROJECT_IFILESYSTEM_H_

#include <vector>
#include <iostream>

#include "File.h"
#include "Definitionsh.h"

namespace os_project {

	namespace fileSystem {

		/*
		 * This class provides an interface for all supported file system.
		 * Every file system must implement some basic file and directory operation
		 *
		 * @author Nils Milewski (nimile)
		 * @date July 23 2019
		 * @version 1.0
		 */
		class IFileSystem{
		protected: 
			/// This attribute is used to assign a file system. For more information @see Definitions.h
			os_project::definitions::file_system_type fileSystemType_m;

		public:

			IFileSystem(os_project::definitions::file_system_type fileSystemType);
			virtual ~IFileSystem(void);
			virtual int createFile(const char* name, const char* extension, int uid, int gid, os_project::definitions::file_system_file_types type) = 0;
			virtual void deleteFile(void) = 0;
			virtual void createDirectory(void) = 0;
			virtual void deleteDirectory(void) = 0;
		
			virtual File* getFile(int index) = 0;

			/**
			 * This method returns the type of the file system. 
			 * For information about available file system @see Definitions.h
			 *
			 * @return Used file system type
			 */
			os_project::definitions::file_system_type getType(void);
		};

	}
}

#endif // _OS_PROJECT_IFILESYSTEM_H_
