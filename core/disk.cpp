#include "disk.h"

using namespace disk;

Disk::Disk(Disk &disk){
    throw std::runtime_error("call to Disk(Disk &disk) is not allowed");}

Disk::Disk(Disk* disk){
    throw std::runtime_error("call to Disk(Disk* disk) is not allowed");
}

Disk::Disk(long capacity, std::string name){
    capacity_m = capacity;
    name_m = name;
    MBR_m = new MasterBootRecord(capacity_m);
}

Disk::Disk(long capacity, const char* name){
    capacity_m = capacity;
    name_m = std::string(name);
    MBR_m = new MasterBootRecord(capacity_m);
}

long Disk::capacity(void){
    return capacity_m;
}

const std::string Disk::name(void){
    return name_m;
}

MasterBootRecord* Disk::MBR(void){
    return MBR_m;
}