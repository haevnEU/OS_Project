#include "../include/INodeTable.h"

using namespace os_project::fileSystem;

INodeTable::INodeTable(void) : IFileSystem(os_project::definitions::file_system_type::INode) {
	inodes_m = new std::vector<INode*>();
}

INodeTable::INodeTable(int blockSize, int size) : IFileSystem(os_project::definitions::file_system_type::INode) {
	inodes_m = new std::vector<INode*>();
	for (int i = 0; i < size; i++) {
		inodes_m->push_back(new INode(blockSize));
	}
}

INodeTable::~INodeTable(void){
	inodes_m->clear();
	delete(inodes_m);
}

int INodeTable::createFile(const char* name, const char* extension, int uid) {
	return 0;
}

void INodeTable::deleteFile(void) {

}

void INodeTable::createDirectory(void) {

}

void INodeTable::deleteDirectory(void) {

}

File* INodeTable::getFile(int index) {
	return nullptr;
}

INode* os_project::fileSystem::INodeTable::getINode(int index){
	if (index > inodes_m->size() || index < 0) {
		throw std::exception("Index out of range");
	}
	return inodes_m->at(index);
}


std::ostream& os_project::fileSystem::operator<< (std::ostream& os, INodeTable& inodeTable) {
	os << "INode table" << std::endl
		<< "File system:" << inodeTable.fileSystemType_m << std::endl;
	for (int i = 0; i < inodeTable.inodes_m->size(); i++) {
		os << *inodeTable.getINode(i) << std::endl;
	}

	return os;
}
