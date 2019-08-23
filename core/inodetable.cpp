#include "inodetable.h"

INodeTable::INodeTable() : IFileSystem (0,0){}

INodeTable::~INodeTable(){}


void INodeTable:: mount(void){}

void INodeTable::unmount(void){}

void INodeTable::selfCheck(void){}

void INodeTable::selfRepair(void){}

void INodeTable::createFile(void){}

void INodeTable::createDirectory(void){}

void INodeTable::deleteFile(void){}

void INodeTable::deleteDirectory(void){}

void INodeTable::openFile(void){}

void INodeTable::closeFile(void){}

const char* INodeTable::readFile(void){}

const char* INodeTable::readFile(int length){}

void INodeTable::writeFile(const char* data, int length){}

char INodeTable::fragmentation(void){}

void INodeTable::defrag(void){}

long INodeTable::freeSpace(void){}

long INodeTable::usedSpace(void){}

long INodeTable::capacity(void){}

void INodeTable::changeAttributes(){}



