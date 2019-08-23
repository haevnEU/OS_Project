#ifndef _OS_PROJECT_INODE_H_
#define _OS_PROJECT_INODE_H_

#include <iostream>
#include <ctime>
#include <string>

#include "Definitionsh.h"
#include "IFileSystem.h"

namespace os_project {
	namespace fileSystem {
		class INode {
		private:
			static unsigned int idCounter;

			unsigned int id_m;

			
			/*  generation number  */
			unsigned long generation_m;
			/*  mode_t returned by stat () */
			/*  format,attributes and permission bits  */
			
			
			/// This attribute is the file extension, Important it is not NULL terminated
			char extension_m[3];

			/// This attribute is the file name, Important it is not NULL terminated
			char name_m[8];

			/* number of links to file(if 0,inode is available)  */
			unsigned short aountLinks_m;

			/* accounting ID  */
			unsigned short acct_m;

			/* user id of owner  */
			unsigned short UID_m;

			/* group id of owner  */
			unsigned GID_m;

			/* size of file  */
			unsigned int size_m;

			/* number of blocks actually used by file  */
			unsigned long amounBlocks_m;

			/* time last modified  */
			int modifyTime_m;

			/* time last accessed  */
			int accessTime_m;

			/* time last changed inode  */
			int changeTime_m;

			unsigned int blockSize_m;
			
			// 16 | 15 | 14 | 13 | 12 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 
			//	                 |  t |  h | x | w | r | x | w | r | x | w | r		
			short mode_m;

			// TODO Add data, double data and tripple data pointer

		/*	int id;

			int fileSize;

			int deviceID;

			int UID;

			int GID;

			int mode;
			
			int timestamps;

			int access;
			
			int modify;

			int change;



			int* pData;*/

		public:

			INode(unsigned int blockSize);

			~INode(void);

			int createFile(const char* name, const char* extension, int uid, int gid, os_project::definitions::file_system_file_types type);
			
			void deleteFile(void);
			
			void createDirectory(void);
			
			void deleteDirectory(void);


			File* getFile(int index);
			








			unsigned int id(void);

			unsigned long generation(void);

			int mode(void);

			char* extension(void);

			void changeExtension(const char* ext);

			char* name(void);

			void changeName(const char* name);

			unsigned short aountLinks(void);

			void addLink(void);

			void removeLink(void);

			unsigned short acct(void);

			unsigned short UID(void);
			
			void changeUID(unsigned short uid);

			unsigned int GID(void);

			void changeGID(unsigned short gid);

			unsigned int size(void);

			unsigned long amounBlocks(void);

			void changeMode(int mode);

			int modifyTime(void);

			int accessTime(void);

			int changeTime(void);

			unsigned int blockSize(void);

			const char* data(void);

			void append(const char* data);

			void remove(int start, int end);

			void add(int pos, const char* data);

			void forbidAll();

			bool readAllowed(os_project::definitions::file_system_groups who);

			void allowRead(os_project::definitions::file_system_groups who);

			void forbidRead(os_project::definitions::file_system_groups who);

			bool writeAllowed(os_project::definitions::file_system_groups who);

			void allowWrite(os_project::definitions::file_system_groups who);
			
			void forbidWrite(os_project::definitions::file_system_groups who);

			bool executeAllowed(os_project::definitions::file_system_groups who);

			void allowExecute(os_project::definitions::file_system_groups who);
			
			void forbidExecute(os_project::definitions::file_system_groups who);

			bool isHidden(void);

			os_project::definitions::file_system_file_types type(void);

			std::string permissionAsString();

			/**
			 * TODO write comment
			 */
			friend std::ostream& operator<< (std::ostream& out, INode& block);
		};
	}
}

#endif // _OS_PROJECT_INODE_H_