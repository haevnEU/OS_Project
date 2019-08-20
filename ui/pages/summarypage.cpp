#include "summarypage.h"

SummaryPage::SummaryPage(QWidget* parent) : QWizardPage (parent){
    setTitle("Summary Page");
    setFinalPage(true);
}

void SummaryPage::initializePage(){
    bool createPartition = field("createPartition").toBool();
    long diskSize = field("DiskSize").toInt();
    int dimension = field("dimension").toInt();
    QString name = field("DiskName").toString();

    QString text = "Disk\n";
    text.append("Manufator name: ").append(name).append("\nDisk size: ").append(QString::number(diskSize));

    switch(dimension){
        case 0:
            text.append("MB");
            break;
        case 1:
            text.append("GB");
            break;
        case 2:
            text.append("TB");
            break;
        case 3:
            text.append("EB");
            break;
    }

    if(createPartition){
        long blockSize = field("partitionBlockSize").toInt();
        long blockCount = field("partitionBlockCount").toInt();
        int fs = field("partitionFileSystem").toInt();
        text.append("\n\nPartition\n").append("Block size: ").append(QString::number(blockSize));
        text.append("\nAmount blocks: ").append(QString::number(blockCount));
        text.append("\nFilesystem: ");

        switch(fs){
        case 0:
            text.append("INode");
            break;
        case 1:
            text.append("FAT");
            break;
        case 2:
            text.append("CD-ROM");
            break;
        }
    }
    setSubTitle(text);
}
