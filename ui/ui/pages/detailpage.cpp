#include "detailpage.h"

using namespace ui::window;

DetailPage::DetailPage() {
    diskInfoPage_m = new DiskInfo();
    resizePartition_m = new ResizePartition();
    addFileDir_m = new AddFileDir();
    modifyFileDir_m = new ModifyFileDir();
    removeFileDir_m = new RemoveFileDir();
    showFragmenation_m = new ShowFragmentation();
    defrag_m = new ui::window::Defrag();
    display_content = new ContentDisplay();

    connect(API::GetInstance(), SIGNAL(diskChanged(void)), this, SLOT(currentDiskChanged(void)));
    connect(API::GetInstance(), SIGNAL(indexChanged(void)), this, SLOT(currentPartitionIndexChanged(void)));
}

DetailPage::~DetailPage(){
    delete(resizePartition_m);
    delete(diskInfoPage_m);
    delete(addFileDir_m);
    delete(modifyFileDir_m);
    delete(removeFileDir_m);
    delete(showFragmenation_m);
    delete(defrag_m);
    delete(display_content);
}

void DetailPage::togglePage(DetailPage::display which){

    switch(which){
    case display::Disk_Info:
        diskInfoPage_m->setVisible(!diskInfoPage_m->isVisible());
        break;
    case display::Partition_Resize:
        resizePartition_m->setVisible(!resizePartition_m->isVisible());
        break;
    case display::Add_File_Dir:
        addFileDir_m->setVisible(!addFileDir_m->isVisible());
        break;
    case display::Modify_File_Dir:
        modifyFileDir_m->setVisible(!modifyFileDir_m->isVisible());
        break;
    case display::Remove_File_Dir:
        removeFileDir_m->setVisible(!removeFileDir_m->isVisible());
        break;
    case display::Display_Content:
        display_content->setVisible(!display_content->isVisible());
        break;
    case display::Show_Fragmentation:
        showFragmenation_m ->setVisible(!showFragmenation_m ->isVisible());
        break;
    case display::Defrag:
        defrag_m->setVisible(!defrag_m->isVisible());
        break;
    }
}


void DetailPage::diskChanged(){
    diskInfoPage_m->diskChanged();
    resizePartition_m->diskChanged();
    addFileDir_m->diskChanged();
}

void DetailPage::setPartition(int idx){
    diskInfoPage_m->setPartition(idx);
    resizePartition_m->setPartition(idx);
    addFileDir_m->setPartition(idx);
}

void DetailPage::closeAll(){
    diskInfoPage_m->setVisible(false);
    resizePartition_m->setVisible(false);

    resizePartition_m->setVisible(false);
    diskInfoPage_m->setVisible(false);
    addFileDir_m->setVisible(false);
    modifyFileDir_m->setVisible(false);
    removeFileDir_m->setVisible(false);
    showFragmenation_m->setVisible(false);
    defrag_m->setVisible(false);
    display_content->setVisible(false);
}

void DetailPage::currentDiskChanged(){
qDebug() << "BLA";
diskInfoPage_m->diskChanged();
resizePartition_m->diskChanged();
addFileDir_m->diskChanged();
}

void DetailPage::currentPartitionIndexChanged(){
    qDebug() << "BLA";
int idx = API::GetInstance()->currentPartitionIndex();
diskInfoPage_m->setPartition(idx);
resizePartition_m->setPartition(idx);
addFileDir_m->setPartition(idx);
}
