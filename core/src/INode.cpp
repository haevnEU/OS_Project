#include "../include/INode.h"

using namespace os_project::fileSystem;

unsigned int INode::idCounter = 0;

INode::INode(unsigned int blockSize) : IFileSystem(os_project::definitions::file_system_type::INode) {
	id_m = idCounter;
	idCounter++;

	generation_m = 0;
	mode_m = 0;
	aountLinks_m = 0;

	blockSize_m = blockSize;

	name_m[0] = 0;
	name_m[1] = 0;
	name_m[2] = 0;
	name_m[3] = 0;
	name_m[4] = 0;
	name_m[5] = 0;
	name_m[6] = 0;
	name_m[7] = 0;

	extension_m[0] = 0;
	extension_m[1] = 0;
	extension_m[2] = 0;
	
	UID_m = 0;
	GID_m = 0;
	size_m = 0;
	amounBlocks_m = 0;
	modifyTime_m = 0;
	accessTime_m = 0;
	changeTime_m = 0;
	permission_m = 0;

}

INode::~INode(void) {

}

int INode::createFile(const char* name, const char* extension, int uid, int gid, os_project::definitions::file_system_file_types type) {
	int nameLength = strlen(name);
	int extLength = strlen(extension);
	if (nameLength > 8) {
		throw std::exception("To big name");
	}
	if (extLength > 3) {
		throw std::exception("To big extension");
	}

	for (int i = 0; i < 8; i++) {
		name_m[i] = 0;
		if (name[i] != 0) {
			name_m[i] = name[i];
		}
	}

	for (int i = 0; i < 3; i++) {
		extension_m[i] = 0;
		if (extension[i] != 0) {
			extension_m[i] = extension[i];
		}
	}

	UID_m = uid;
	GID_m = gid;
	size_m = 0;
	amounBlocks_m = 0;
	modifyTime_m = accessTime_m = changeTime_m = std::time(0);
	forbidAll();
	allowRead(os_project::definitions::file_system_groups::Owner);
	allowRead(os_project::definitions::file_system_groups::Group);
	allowWrite(os_project::definitions::file_system_groups::Owner);
	allowWrite(os_project::definitions::file_system_groups::Group);
	allowExecute(os_project::definitions::file_system_groups::Owner);
	allowExecute(os_project::definitions::file_system_groups::Group);
	
	switch (type) {
	case os_project::definitions::file_system_file_types::file:
		permission_m &= ~(1 << 10);
		permission_m &= ~(1 << 11);
		permission_m &= ~(1 << 12);
		break;

	case os_project::definitions::file_system_file_types::directory:
		permission_m |= 1 << 10;
		permission_m &= ~(1 << 11);
		permission_m &= ~(1 << 12);
		break;

	case os_project::definitions::file_system_file_types::symbolic_link:
		permission_m &= ~(1 << 10);
		permission_m |= 1 << 11;
		permission_m &= ~(1 << 12);
		break;

	case os_project::definitions::file_system_file_types::block_special_file:
		permission_m |= 1 << 10;
		permission_m |= 1 << 11;
		permission_m &= ~(1 << 12);
		break;

	case os_project::definitions::file_system_file_types::character_special_file:
		permission_m &= ~(1 << 10);
		permission_m &= ~(1 << 11);
		permission_m |= 1 << 12;
		break;

	case os_project::definitions::file_system_file_types::named_pipe_file:
		permission_m |= 1 << 10;
		permission_m &= ~(1 << 11);
		permission_m |= 1 << 12;
		break;

	case os_project::definitions::file_system_file_types::loacl_socket_special_file:
		permission_m &= ~(1 << 10);
		permission_m |= 1 << 11;
		permission_m |= 1 << 12;
		break;
	}

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



unsigned int INode::id() {
	return id_m;
}

unsigned long INode::generation(void){
	return generation_m;
}

int INode::mode(void){
	return mode_m;
}

void INode::changeMode(int mode) {

	mode_m = mode;
	accessTime_m = changeTime_m = std::time(0);
}

char* INode::extension(void) {
	return extension_m;
}

void os_project::fileSystem::INode::changeExtension(const char* ext){

	int length = strlen(ext);
	
	if (length > 3) {
		throw std::exception("To big extension");
	}
	for (int i = 0; i < 3; i++) {
		extension_m[i] = 0;
		if (i < length) {
			extension_m[i] = ext[i];
		}

	}
	accessTime_m = modifyTime_m = changeTime_m = std::time(0);
}

char* INode::name(void){
	return name_m;
}

void os_project::fileSystem::INode::changeName(const char* name){

	int length = strlen(name);

	if (length > 8) {
		throw std::exception("To big name");
	}
	for (int i = 0; i < 8; i++) {
		name_m[i] = 0;
		if (i < length) {
			name_m[i] = name[i];
		}

	}
	accessTime_m = modifyTime_m = changeTime_m = std::time(0);
}

unsigned short INode::aountLinks(void){
	return aountLinks_m;
}

void os_project::fileSystem::INode::addLink(void){

	// TODO
	accessTime_m = changeTime_m = std::time(0);
}

void os_project::fileSystem::INode::removeLink(void){

	// TODO
	accessTime_m = changeTime_m = std::time(0);
}

unsigned short INode::acct(void){
	return acct_m;
}

unsigned short INode::UID(void){
	return UID_m;
}

void os_project::fileSystem::INode::changeUID(unsigned short uid){

	UID_m = uid;
	accessTime_m = changeTime_m = std::time(0);	
}

unsigned int INode::GID(void){
	return GID_m;
}

void os_project::fileSystem::INode::changeGID(unsigned short gid){
	GID_m = gid;
	accessTime_m = changeTime_m = std::time(0);
}

unsigned int INode::size(void){
	return size_m;
}

unsigned long INode::amounBlocks(void){
	return amounBlocks_m;
}

int INode::modifyTime(void){
	return modifyTime_m;
}

int INode::accessTime(void){
	return accessTime_m;
}

int INode::changeTime(void){
	return changeTime_m;
}

unsigned int INode::blockSize(void){
	return blockSize_m;
}

const char* INode::data(void){

	accessTime_m = std::time(0);
	// TODO add
	return nullptr;
}

void os_project::fileSystem::INode::append(const char* data){
	
	// TODO add
	accessTime_m = modifyTime_m = std::time(0);
}

void os_project::fileSystem::INode::remove(int start, int end){

	// TODO add
	accessTime_m = modifyTime_m = std::time(0);
}

void os_project::fileSystem::INode::add(int pos, const char* data){

	// TODO add
	accessTime_m = modifyTime_m = std::time(0);
}


void INode::forbidAll() {

}
	
bool INode::readAllowed(os_project::definitions::file_system_groups who) {
	switch (who) {
	case os_project::definitions::file_system_groups::Other:
		return (permission_m & 0b0000000001000000);
		break;
	case os_project::definitions::file_system_groups::Group:
		return (permission_m & 0b0000000000001000);
		break;
	case os_project::definitions::file_system_groups::Owner:
		return (permission_m & 0b0000000000000001);
		break;
	}
	return false;
}

void os_project::fileSystem::INode::allowRead(os_project::definitions::file_system_groups who){
	switch (who) {
	case os_project::definitions::file_system_groups::Other:
		permission_m |= 1 << 0;
		break;

	case os_project::definitions::file_system_groups::Group:
		permission_m |= 1 << 3;
		break;

	case os_project::definitions::file_system_groups::Owner:
		permission_m |= 1 << 6;
		break;
	}
}

void os_project::fileSystem::INode::forbidRead(os_project::definitions::file_system_groups who){

	switch (who) {
	case os_project::definitions::file_system_groups::Other:
		permission_m &= ~(1 << 0);
		break;

	case os_project::definitions::file_system_groups::Group:
		permission_m &= ~(1 << 3);
		break;

	case os_project::definitions::file_system_groups::Owner:
		permission_m &= ~(1 << 6);
		break;
	}
}

bool INode::writeAllowed(os_project::definitions::file_system_groups who) {
	switch (who) {
	case os_project::definitions::file_system_groups::Other:
		return (permission_m & 0b0000000010000000);
	case os_project::definitions::file_system_groups::Group:
		return (permission_m & 0b0000000000010000);
	case os_project::definitions::file_system_groups::Owner:
		return (permission_m & 0b0000000000000010);
	}
	return false;
}

void os_project::fileSystem::INode::allowWrite(os_project::definitions::file_system_groups who){
	switch (who) {
	case os_project::definitions::file_system_groups::Other:
		permission_m |= 1 << 1;
		break;

	case os_project::definitions::file_system_groups::Group:
		permission_m |= 1 << 4;
		break;

	case os_project::definitions::file_system_groups::Owner:
		permission_m |= 1 << 7;
		break;
	}
}

void os_project::fileSystem::INode::forbidWrite(os_project::definitions::file_system_groups who){

	switch (who) {
	case os_project::definitions::file_system_groups::Other:
		permission_m &= ~(1 << 1);
		break;

	case os_project::definitions::file_system_groups::Group:
		permission_m &= ~(1 << 4);
		break;

	case os_project::definitions::file_system_groups::Owner:
		permission_m &= ~(1 << 7);
		break;
	}
}

bool INode::executeAllowed(os_project::definitions::file_system_groups who) {
	switch (who) {
	case os_project::definitions::file_system_groups::Other:
		return (permission_m & 0b0000000100000000);
	case os_project::definitions::file_system_groups::Group:
		return (permission_m & 0b0000000000100000);
	case os_project::definitions::file_system_groups::Owner:
		return (permission_m & 0b0000000000000100);
	}
	return false;
}

void os_project::fileSystem::INode::allowExecute(os_project::definitions::file_system_groups who){
	switch (who) {
	case os_project::definitions::file_system_groups::Other:
		permission_m |= 1 << 8;
		break;

	case os_project::definitions::file_system_groups::Group:
		permission_m |= 1 << 5;
		break;

	case os_project::definitions::file_system_groups::Owner:
		permission_m |= 1 << 2;
		break;
	}
}

void os_project::fileSystem::INode::forbidExecute(os_project::definitions::file_system_groups who){
	
	switch (who) {
	case os_project::definitions::file_system_groups::Other:
		permission_m &= ~(1 << 8);
		break;

	case os_project::definitions::file_system_groups::Group:
		permission_m &= ~(1 << 5);
		break;

	case os_project::definitions::file_system_groups::Owner:
		permission_m &= ~(1 << 2);
		break;
	}
}

bool INode::isHidden(void) {
	return (permission_m & 0b0000001000000000);
}

os_project::definitions::file_system_file_types INode::type(void) {
	int val = (permission_m & 0b0001110000000000) >> 10;
	os_project::definitions::file_system_file_types ret = static_cast<os_project::definitions::file_system_file_types>(val);
	return ret;
}

std::string os_project::fileSystem::INode::permissionAsString() {
	
	int val = (permission_m & 0b0001110000000000) >> 10;
	std::string str = os_project::definitions::file_system_file_types_name[val];
	 
	// type
	

	// Owner

	if (readAllowed(os_project::definitions::file_system_groups::Owner)) {
		str += "r";
	}
	else {
		str += "-";
	}

	if (writeAllowed(os_project::definitions::file_system_groups::Owner)) {
		str += "w";
	}
	else {
		str += "-";
	}

	if (executeAllowed(os_project::definitions::file_system_groups::Owner)) {
		str += "x";
	}
	else {
		str += "-";
	}

	// Group

	if (readAllowed(os_project::definitions::file_system_groups::Group)) {
		str += "r";
	}
	else {
		str += "-";
	}

	if (writeAllowed(os_project::definitions::file_system_groups::Group)) {
		str += "w";
	}
	else {
		str += "-";
	}

	if (executeAllowed(os_project::definitions::file_system_groups::Group)) {
		str += "x";
	}
	else {
		str += "-";
	}

	// Other

	if (readAllowed(os_project::definitions::file_system_groups::Other)) {
		str += "r";
	}
	else {
		str += "-";
	}

	if (writeAllowed(os_project::definitions::file_system_groups::Other)) {
		str += "w";
	}
	else {
		str += "-";
	}

	if (executeAllowed(os_project::definitions::file_system_groups::Other)) {
		str += "x";
	}
	else {
		str += "-";
	}


	return str;
}

std::ostream& os_project::fileSystem::operator<< (std::ostream& os, INode& inode) {

	os << "File: ";

	for (int i = 0; i < 8; i++) {
		if (inode.name_m[i] == 0) {
			break;
		}
		os << inode.name_m[i];
	}

	os << ".";


	for (int i = 0; i < 3; i++) {
		if (inode.extension_m[i] == 0) {
			break;
		}
		os << inode.extension_m[i];
	}

	os << std::endl;

	os << "Size: " << inode.size_m << " Blocks: " << inode.amounBlocks_m << " IO Block: " << inode.blockSize_m << std::endl
		<< "Device: " << inode.acct_m << " INode: " << inode.id_m << " Links: " << inode.aountLinks_m << std::endl
		<< "Access: " << inode.permissionAsString() << " UID: " << inode.UID_m << " GUID: " << inode.GID_m << std::endl
		<< "Access: " << inode.accessTime_m << std::endl
		<< "Change: " << inode.changeTime_m << std::endl
		<< "Change: " << inode.changeTime_m << std::endl;

	return os;

}
