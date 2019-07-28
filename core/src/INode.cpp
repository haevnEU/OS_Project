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

std::vector<os_project::fileSystem::File*>* INode::getFiles(void) {
	return nullptr;
}

