#include "detailpage.h"

using namespace ui::window;

DetailPage::DetailPage() {
    diskInfoPage_m = new DiskInfo();
    resizePartition_m = new ResizePartition();
}

DetailPage::~DetailPage(){
    delete(resizePartition_m);
    delete(diskInfoPage_m);
}

void DetailPage::togglePage(DetailPage::display which){

    switch(which){
    case display::Disk_Info:
        diskInfoPage_m->setVisible(!diskInfoPage_m->isVisible());
        break;
    case display::Partition_Resize:
        resizePartition_m->setVisible(!resizePartition_m->isVisible());
        break;
    }
}

void DetailPage::setDisk(core::disk::Disk* disk){
    workingDisk_m = disk;
    diskInfoPage_m->setDisk(workingDisk_m);
    resizePartition_m->setDisk(disk);
}

void DetailPage::close(){
    diskInfoPage_m->setVisible(false);
    resizePartition_m->setVisible(false);
}
