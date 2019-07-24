#include "../include/IFileSystem.h"

using namespace os_project::fileSystem;

IFileSystem::IFileSystem(os_project::definitions::file_system_type file_system_type){
	this->file_system_type = file_system_type;
	this->files = new std::vector<File*>();
}

IFileSystem::~IFileSystem(void){
	std::cout << "DTOR of IFileSystem is called" << std::endl;

	files->clear();
	delete(files);
}

os_project::definitions::file_system_type IFileSystem::getType(void){
	return file_system_type;
}
