#ifndef _OS_PROJECT_INODE_H_
#define _OS_PROJECT_INODE_H_

#include "IFileSystem.h"

namespace os_project {
	namespace fileSystem {
		class INode : public os_project::fileSystem::IFileSystem {
		private:
			/*
			File: f2 
  Size: 6               Blocks: 0          IO Block: 4096   regular file
Device: dh/13d  Inode: 24769797950898151  Links: 2
Access: (0777/-rwxrwxrwx)  Uid: ( 1000/    nils)   Gid: ( 1000/    nils)
Access: 2019-08-05 00:38:26.381845300 +0200
Modify: 2019-08-05 00:38:26.381845300 +0200
Change: 2019-08-05 00:41:54.347723800 +0200
 Birth: -
			
			*/
			
			/*  generation number  */
			unsigned long generation_m;
			/*  mode_t returned by stat () */
			/*  format,attributes and permission bits  */
			int mode;

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

			int permission;



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

			INode(void);

			~INode(void);

			int createFile(void);
			
			void deleteFile(void);
			
			void createDirectory(void);
			
			void deleteDirectory(void);

			File* getFile(int index);
			

			/**
			 * TODO write comment
			 */
			friend std::ostream& operator<< (std::ostream& out, INode& block);
		};
	}
}

#endif // _OS_PROJECT_INODE_H_