#include "../include/IFileSystem.h"

using namespace os_project::fileSystem;

IFileSystem::IFileSystem(os_project::definitions::file_system_type file_system_type){
	this->fileSystemType_m = file_system_type;
//	this->files_m = new std::vector<File*>();
}

IFileSystem::~IFileSystem(void){
	std::cout << "DTOR of IFileSystem is called" << std::endl;

	//files_m->clear();
	//delete(files_m);
}

os_project::definitions::file_system_type IFileSystem::getType(void){
	return fileSystemType_m;
}
