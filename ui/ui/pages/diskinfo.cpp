#include "diskinfo.h"
#include "core/api.h"

using namespace ui::window;

DiskInfo::DiskInfo(){

    QGridLayout* layout = new QGridLayout;

    diskLayout = new QGridLayout();
    partition1Layout = new QGridLayout();
    partition2Layout = new QGridLayout();
    partition3Layout = new QGridLayout();
    partition4Layout = new QGridLayout();

    diskLayout->addWidget(new QLabel("Disk info"), 0, 0, 1, 2, Qt::AlignCenter);
    partition2Layout->addWidget(new QLabel("Partition 2 info"), 0, 0, 1, 2);
    partition3Layout->addWidget(new QLabel("Partition 3 info"), 0, 0, 1, 2);
    partition4Layout->addWidget(new QLabel("Partition 4 info"), 0, 0, 1, 2);


     lbDiskCapacity = new QLabel();
     lbDiskName = new QLabel();
     lbPartition1Size = new QLabel();
     lbPartition1AmountBlocks = new QLabel();
     lbPartition1Mounted = new QLabel();
     lbPartition2Size = new QLabel();
     lbPartition2AmountBlocks = new QLabel();
     lbPartition2Mounted = new QLabel();
     lbPartition3Size = new QLabel();
     lbPartition3AmountBlocks = new QLabel();
     lbPartition3Mounted = new QLabel();
     lbPartition4Size = new QLabel();
     lbPartition4AmountBlocks = new QLabel();
     lbPartition4Mounted = new QLabel();

     diskLayout->addWidget(new QLabel("Name"), 1, 0);
     diskLayout->addWidget(new QLabel("Capacity"), 2, 0);

     diskLayout->addWidget(lbDiskName, 1, 1);
     diskLayout->addWidget(lbDiskCapacity, 2, 1);

    partition1Layout->addWidget(new QLabel("Partition 1 info"),  0, 0, 1, 2);
    partition1Layout->addWidget(new QLabel("Block size"),        1, 0);
    partition1Layout->addWidget(new QLabel("Amount block size"), 2, 0);
    partition1Layout->addWidget(new QLabel("Mounted"),           3, 0);
    partition1Layout->addWidget(lbPartition1Size,                1, 1);
    partition1Layout->addWidget(lbPartition1AmountBlocks,        2, 1);
    partition1Layout->addWidget(lbPartition1Mounted,             3, 1);

    partition2Layout->addWidget(new QLabel("Block size"), 1, 0);
    partition2Layout->addWidget(new QLabel("Amount block size"), 2, 0);
    partition2Layout->addWidget(new QLabel("Mounted"), 3, 0);

    partition3Layout->addWidget(new QLabel("Block size"), 1, 0);
    partition3Layout->addWidget(new QLabel("Amount block size"), 2, 0);
    partition3Layout->addWidget(new QLabel("Mounted"), 3, 0);

    partition4Layout->addWidget(new QLabel("Block size"), 1, 0);
    partition4Layout->addWidget(new QLabel("Amount block size"), 2, 0);
    partition4Layout->addWidget(new QLabel("Mounted"), 3, 0);


    partition2Layout->addWidget(lbPartition2Size, 1, 1);
    partition2Layout->addWidget(lbPartition2AmountBlocks, 2, 1);
    partition2Layout->addWidget(lbPartition2Mounted, 3 ,1);

    partition3Layout->addWidget(lbPartition3Size, 1, 1);
    partition3Layout->addWidget(lbPartition3AmountBlocks, 2, 1);
    partition3Layout->addWidget(lbPartition3Mounted, 3, 1);

    partition4Layout->addWidget(lbPartition4Size, 1 ,1);
    partition4Layout->addWidget(lbPartition4AmountBlocks, 2 ,1);
    partition4Layout->addWidget(lbPartition4Mounted, 3, 1);

    layout->addItem(diskLayout, 0, 0, 1, 2);
    layout->addItem(partition1Layout, 1, 0);
    layout->addItem(partition2Layout, 1, 1);
    layout->addItem(partition3Layout, 2, 0);
    layout->addItem(partition4Layout, 2, 1);

    this->setLayout(layout);
}

DiskInfo::~DiskInfo(){

}

void DiskInfo::diskChanged(){
    core::disk::Disk* disk = API::GetInstance()->currentDisk();
    lbDiskCapacity->setText(QString::number(disk->capacity()).append("Byte"));
    lbDiskName->setText(QString(disk->name().c_str()));
    if(nullptr != disk->MBR()->getPartition(0)){
        lbPartition1Size->setText(QString::number(disk->MBR()->getPartition(0)->blockSize()));
        lbPartition1AmountBlocks->setText(QString::number(disk->MBR()->getPartition(0)->amountBlocks()));
        if(disk->MBR()->getPartition(0)->isMounted()){
            lbPartition1Mounted->setText("mounted");
        }else{
            lbPartition1Mounted->setText("unmounted");
        }
    }else{

        lbPartition1Size->setText("");
        lbPartition1AmountBlocks->setText("");
        lbPartition1Mounted->setText("");
    }

    if(nullptr != disk->MBR()->getPartition(1)){
        lbPartition2Size->setText(QString::number(disk->MBR()->getPartition(1)->blockSize()));
        lbPartition2AmountBlocks->setText(QString::number(disk->MBR()->getPartition(1)->amountBlocks()));
        if(disk->MBR()->getPartition(1)->isMounted()){
            lbPartition2Mounted->setText("mounted");
        }else{
            lbPartition2Mounted->setText("unmounted");
        }
    }else{

        lbPartition2Size->setText("");
        lbPartition2AmountBlocks->setText("");
        lbPartition2Mounted->setText("");
    }


    if(nullptr != disk->MBR()->getPartition(2)){
        lbPartition3Size->setText(QString::number(disk->MBR()->getPartition(2)->blockSize()));
        lbPartition3AmountBlocks->setText(QString::number(disk->MBR()->getPartition(2)->amountBlocks()));
        if(disk->MBR()->getPartition(2)->isMounted()){
            lbPartition3Mounted->setText("mounted");
        }else{
            lbPartition3Mounted->setText("unmounted");
        }
    }else{

        lbPartition3Size->setText("");
        lbPartition3AmountBlocks->setText("");
        lbPartition3Mounted->setText("");
    }

    if(nullptr != disk->MBR()->getPartition(3)){
        lbPartition4Size->setText(QString::number(disk->MBR()->getPartition(3)->blockSize()));
        lbPartition4AmountBlocks->setText(QString::number(disk->MBR()->getPartition(3)->amountBlocks()));
        if(disk->MBR()->getPartition(3)->isMounted()){
            lbPartition4Mounted->setText("mounted");
        }else{
            lbPartition4Mounted->setText("unmounted");
        }
    }else{

        lbPartition4Size->setText("");
        lbPartition4AmountBlocks->setText("");
        lbPartition4Mounted->setText("");
    }

    // TODO setup UI info
}


void DiskInfo::setPartition(int idx){

}
