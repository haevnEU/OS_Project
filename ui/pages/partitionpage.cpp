#include "partitionpage.h"

PartitionPage::PartitionPage(QWidget* parent) : QWizardPage(parent){

    setTitle("Partition page");
    setSubTitle("");

    sbBlockSize = new QSpinBox();
    sbBlockSize->setMinimum(1);

    QSpinBox* sbAmountBlocks = new QSpinBox();
    sbAmountBlocks->setMinimum(1);
    sbAmountBlocks->setMaximum(INT_MAX);

    QComboBox* cbFileSystem = new QComboBox();
    cbFileSystem->addItem("INode");
    cbFileSystem->addItem("FAT");
    cbFileSystem->addItem("CD-ROM");

    QGridLayout* layout = new QGridLayout();
    layout->addWidget(new QLabel("Block size:"), 0, 0);
    layout->addWidget(sbBlockSize, 0, 1);

    layout->addWidget(new QLabel("Amount of Blocks:"), 1, 0);
    layout->addWidget(sbAmountBlocks, 1, 1);

    layout->addWidget(new QLabel("Filesystem:"), 2, 0);
    layout->addWidget(cbFileSystem, 2, 1);

    registerField("partitionBlockSize*", sbBlockSize);
    registerField("partitionBlockCount*", sbAmountBlocks);
    registerField("partitionFileSystem", cbFileSystem);

    setLayout(layout);
}

int PartitionPage::nextId() const{
    return pages_enum::summaryPage;
}

void PartitionPage::setVisible(bool visible){
     QWizardPage::setVisible(visible);
    int diskSize = field("DiskSize").toInt();
        int dimension = field("dimension").toInt();
        QString subTitle = "You can specify partition details. Available space is: ";
        subTitle.append(QString::number(diskSize));

        switch(dimension){
            case 0:
                subTitle.append("MB");
                break;
            case 1:
                subTitle.append("GB");
                break;
            case 2:
                subTitle.append("TB");
                break;
            case 3:
                subTitle.append("EB");
                break;
        }
        setSubTitle(subTitle);
        sbBlockSize->setMaximum(diskSize * (dimension + 1));
}
