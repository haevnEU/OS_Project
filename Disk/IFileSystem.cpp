#include "IFileSystem.h"


os_project::fileSystem::IFileSystem::IFileSystem(os_project::definitions::file_system_type file_system_type){
	this->file_system_type = file_system_type;
	this->files = new std::vector<os_project::fileSystem::File*>();
}

os_project::fileSystem::IFileSystem::~IFileSystem(void){
	files->clear();
	delete(files);
}

os_project::definitions::file_system_type os_project::fileSystem::IFileSystem::getType(void){
	return file_system_type;
}
