#include "block.h"
#include "disk.h"
#include "masterbootrecord.h"
#include "partition.h"

#include <iostream>
#include <iomanip>

int main(int argc, const char* argv[]){
/*
    std::cout << "BLA" << std::boolalpha << std::endl;
    disk::Disk* disk = new disk::Disk(1024, "computer inc");
    std::cout << disk->MBR()->addPartition(512,1,nullptr) << std::endl;
    std::cout << disk->MBR()->addPartition(1024,1,nullptr)<< std::endl;
    std::cout << disk->MBR()->addPartition(2, 512,1, nullptr)<< std::endl;
    std::cout << disk->MBR()->addPartition(3, 1024,1, nullptr)<< std::endl;

    disk->MBR()->getPartition(2)->mount();
    std::cout << *disk << std::endl;
*/
    return 0;
}
