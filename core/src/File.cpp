#include "../include/File.h"

using namespace os_project::fileSystem;

File::~File(void) {

}

File::File(int fileSize, const char name[], const char ext[],
	int attributes, int userID, int timeStamp, int dateStamp) {

	int filename_size = strlen(name);
	int extension_size = strlen(ext);
	int required_blocks = 0;
	int free_blocks = 0;

	// Determine if the filename and extension full fill the requirements
	if (filename_size > 8 || extension_size > 3) {
		throw std::exception("File or extension are to long");
	}

	if (required_blocks > free_blocks) {
		throw std::exception("To many blocks required");
	}

	// Set metadata
	userID_m = userID;
	size_m = fileSize;
	createModifyTime_m = timeStamp;
	createModifyDate_m = dateStamp;
	attributes_m = attributes;
	//file->attributes |= (BS_FILE_FREE | attributes_t);
	fileID_m = 0;
	for (int i = 0; i < 8; i++) {
		name_m[i] = 0;
		if (i < filename_size) {
			name_m[i] = name[i];
		}
	}

	for (int i = 0; i < 3; i++) {
		extension_m[i] = 0;
		if (i < extension_size) {
			extension_m[i] = ext[i];
		}
	}	
}

void File::deleteFile(void) {

}

int File::clusterIndex(int index) {
	return 0;
}

void File::setAttribute(int mask) {
	 attributes_m |= (1 << mask);
}

void File::setAttributes(int mask) {
	attributes_m |= mask;
}

void File::clearAttribute(int mask) {
	attributes_m &= ~(1 << mask);
}

void File::clearAttributes(int mask) {
	attributes_m &= ~mask;
}

const char* File::name(void) {
	return name_m;
}

int File::size(void) {
	return size_m;
}

int File::occupiedBlocks(void) {
	return usedBlocks_m;
}

int File::fileID(void) {
	return fileID_m;
}

int File::userID(void) {
	return userID_m;
}

int File::attributes(int attributeMask) {
	return attributes_m;
}

int File::lastModifyDate(void) {
	return createModifyDate_m;
}

int File::lastModifyTime(void) {
	return createModifyTime_m;
}

std::string File::getAttributesAsString() {
	
	std::string returnString = "";

	if (attributes_m & 0b10000000) {
		returnString += "FREE ";
	}
	
	if (attributes_m & 0b01000000) {
		returnString += "DEL ";
	}

	if (attributes_m & 0b00100000) {
		returnString += "MODI ";
	}

	if (attributes_m & 0b00010000) {
		returnString += "DIR ";
	}

	if (attributes_m & 0b00001000) {
		returnString += "SYS ";
	}

	if (attributes_m & 0b00000100) {
		returnString += "HID ";
	}

	if (attributes_m & 0b00000010) {
		returnString += "EXE ";
	}

	if (attributes_m & 0b00000001) {
		returnString += "RO/";
	}
	else {
		returnString += "RW";
	}

	return returnString;
}


void File::DBG_setTime(unsigned short dt) {
	createModifyTime_m = dt;
}

std::string File::getTimeAsString() {
	int h, m, s;
	h = (createModifyTime_m & 0b1111100000000000) >> 11;
	m = (createModifyTime_m & 0b0000011111000000) >> 6;
	s = (createModifyTime_m & 0b0000000000011111);

	
	std::string returnString = std::to_string(h);
	returnString += ":";
	returnString += std::to_string(m);
	returnString += ":";
	returnString += std::to_string(s);

	return returnString;
}

std::string File::getDateAsString() {

	int y, m, d;
	y = (createModifyTime_m & 0b1111100000000000) >> 11;
	m = (createModifyTime_m & 0b0000011111000000) >> 6;
	d = (createModifyTime_m & 0b0000000000011111);


	std::string returnString = std::to_string(y);
	returnString += ":";
	returnString += std::to_string(m);
	returnString += ":";
	returnString += std::to_string(d);

	return returnString;
}


const char* File::data(){ 
	return nullptr;
}


std::ostream& os_project::fileSystem::operator<< (std::ostream& os, File& file) {


	os << "Filename: ";
	for (int i = 0; i < 5; i++) {
		if (file.name_m[i] == 0) {
			break;
		}
		os << file.name_m[i];
	
	} 
	os << ".";

	for (int i = 0; i < 3; i++) {
		if (file.extension_m[i] == 0) {
			break;
		}
		os << file.extension_m[i];

	}
	os << std::endl;
	
	os	<< "File id: " << file.fileID_m << std::endl
		<< "Attributes: " << file.attributes_m << "(" << file.getAttributesAsString() << ")" << std::endl
		<< "Create date: " << file.createModifyDate_m << "(" << file.getDateAsString() << ")" << std::endl
		<< "Create time: " << file.createModifyTime_m << "(" << file.getTimeAsString() << ")" << std::endl
		<< "Size: " << file.size_m << std::endl
		<< "Used blocks: " << file.usedBlocks_m << std::endl;

	return os;

}

