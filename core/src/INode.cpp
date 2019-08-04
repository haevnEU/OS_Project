#include "../include/INode.h"

using namespace os_project::fileSystem;

INode::INode(void) : IFileSystem(os_project::definitions::file_system_type::INode) {

}

INode::~INode(void) {

}

int INode::createFile(void) {

	//files->insert(nullptr);
	return 0;
}

void INode::deleteFile(void) {

}

void INode::createDirectory(void) {

}

void INode::deleteDirectory(void) {

}

File* INode::getFile(int index) {
	return nullptr;
}


std::ostream& os_project::fileSystem::operator<< (std::ostream& os, INode& inode) {
	/*
				File: f2 
  Size: 6           
  Blocks: 0       
  IO Block: 4096   
  regular file
Device: dh/13d  
Inode: 24769797950898151 
Links: 2
Access: (0777/-rwxrwxrwx) 
Uid: ( 1000/    nils)  
Gid: ( 1000/    nils)
Access: 2019-08-05 00:38:26.381845300 +0200
Modify: 2019-08-05 00:38:26.381845300 +0200
Change: 2019-08-05 00:41:54.347723800 +0200
 Birth: -
	*/
/*
	unsigned long generation_m;
	int mode;
	unsigned short aountLinks_m;
	unsigned short acct_m;
	unsigned short UID_m;
	unsigned GID_m;
	unsigned int size_m;
	unsigned long amounBlocks_m;
	int modifyTime_m;
	int accessTime_m;
	int changeTime_m;
	unsigned int blockSize_m;
*/

	os << "File: " << std::endl
		<< "Size: " << inode.size_m << " Blocks: " << inode.amounBlocks_m << " IO Block: " << inode.blockSize_m << std::endl
		<< "Device: " << inode.acct_m << " INode: " << "Links: " << inode.aountLinks_m << std::endl
		<< "Access: " << inode.permission << " UID: " << inode.UID_m << " GUID: " << inode.GID_m << std::endl
		<< "Access: " << inode.accessTime_m << std::endl
		<< "Change: " << inode.changeTime_m << std::endl
		<< "Change: " << inode.changeTime_m << std::endl;

	return os;

}


