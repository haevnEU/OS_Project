#include "resizepartition.h"

using namespace ui::window;

ResizePartition::ResizePartition(){

    // Initialize UI elements
    lbMaxValue= new QLabel();
    lbCurrentValue= new QLabel();
    sdPartitionSize = new QSlider;
    btOk = new QPushButton("Ok");
    btCancel = new QPushButton("Cancel");

    // Set up UI
    btOk->setMaximumWidth(75);
    btCancel->setMaximumWidth(75);

    lbCurrentValue->setAlignment(Qt::AlignHCenter);
    sdPartitionSize->setOrientation(Qt::Orientation::Horizontal);

    QGridLayout* layout = new QGridLayout;

    layout->addWidget(lbCurrentValue, 0,0,1,3);
    layout->addWidget(new QLabel("0"), 1,0);
    layout->addWidget(sdPartitionSize, 1, 1);
    layout->addWidget(lbMaxValue, 1,2);
    layout->addWidget(btOk, 2,0);
    layout->addWidget(btCancel,2, 2);

    setLayout(layout);
    setMinimumWidth(300);

    // Set attributes
    index_m = 0;

    // Connect singals and slots
    connect(sdPartitionSize, SIGNAL(valueChanged(int)), this, SLOT(valueChanged(int)));
    connect(btOk, SIGNAL(pressed()), this, SLOT(btOkPressed()));
    connect(btCancel, SIGNAL(pressed()), this, SLOT(btCancelPressed()));

}

ResizePartition::~ResizePartition(){
    QWidget::~QWidget();
}

void ResizePartition::btOkPressed(){
    unsigned long long newSize = sdPartitionSize->value();
    disk_m->MBR()->getPartition(index_m)->resize(newSize);
    this->setVisible(false);
}

void ResizePartition::btCancelPressed(){
    this->setVisible(false);
}

void ResizePartition::setDisk(core::disk::Disk *disk){
    this->disk_m = disk;
}

void ResizePartition::setIndex(int index){
    this->index_m = index;
}

void ResizePartition::showEvent(QShowEvent *event){
    QWidget::showEvent(event);
    if(nullptr == disk_m){
        return;
    }
    if(nullptr == disk_m->MBR()->getPartition(index_m)){
        return;
    }

    long long maxSize = disk_m->MBR()->getPartition(index_m)->blockSize() * disk_m->MBR()->getPartition(index_m)->amountBlocks();
    lbMaxValue->setText(QString::number(maxSize));
    sdPartitionSize->setMinimum(0);
    sdPartitionSize->setMaximum(maxSize);
}


void ResizePartition::valueChanged(int value){
    lbCurrentValue->setText(QString::number(value));
}
