#include "resizepartition.h"

#include <QDebug>

using namespace ui::window;

ResizePartition::ResizePartition(){

    // Initialize UI elements
    lbMaxValue= new QLabel();
    lbPartitionInfo = new QLabel();
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

    layout->addWidget(lbPartitionInfo, 0,0);
    layout->addWidget(lbCurrentValue, 0,1);
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
    API::GetInstance()->resizePartition(index_m, sdPartitionSize->value());
    this->setVisible(false);
}

void ResizePartition::btCancelPressed(){
    this->setVisible(false);
}

void ResizePartition::diskChanged(){
    display();
}

void ResizePartition::setIndex(int index){
    this->index_m = index;
}

void ResizePartition::showEvent(QShowEvent *event){
    QWidget::showEvent(event);
    if(nullptr == API::GetInstance()->currentDisk()){
        return;
    }
   display();
}

void ResizePartition::display(){
    if(nullptr == API::GetInstance()->currentDisk()->MBR()->getPartition(index_m)){
        return;
    }

    unsigned long long newBlockCount = 0;
    unsigned long long blockSize = API::GetInstance()->blockSize(index_m);
    unsigned long long amountBlocks = API::GetInstance()->blockCount(index_m);
    unsigned long long maxSize =  amountBlocks + API::GetInstance()->availableDiskSize() / blockSize;

    lbMaxValue->setText(QString::number(maxSize));
    sdPartitionSize->setMinimum(1);
    sdPartitionSize->setMaximum(maxSize);
    sdPartitionSize->setValue(amountBlocks);

    lbPartitionInfo->setText(QString("Amount blocks: ").append(QString::number(amountBlocks))
                             .append("Block size").append(QString::number(blockSize)));
    API::GetInstance()->resizePartition(index_m, newBlockCount);
}

void ResizePartition::valueChanged(int value){
    lbCurrentValue->setText(QString::number(value));
}

void ResizePartition::setPartition(int idx){
    setIndex(idx);
    display();
}
