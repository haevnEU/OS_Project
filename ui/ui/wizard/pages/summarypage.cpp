#include "summarypage.h"

using namespace ui::wizard::pages;

SummaryPage::SummaryPage(int usedPages, QWidget* parent) : QWizardPage (parent){
    setTitle("Summary Page");
    usedPages_m = usedPages;
}

void SummaryPage::initializePage(){
    QString text = "";
    if((usedPages_m & pages_enum::diskPage) == pages_enum::diskPage){
        text.append(getDiskText());
        if(field("createPartition").toBool()){
            text.append("\n\n").append(getPartitioNText());
        }
    }else if((usedPages_m & pages_enum::partitionPage) == pages_enum::partitionPage){
        text = getPartitioNText();
    }

    setSubTitle(text);
}

QString SummaryPage::getPartitioNText(){
    long blockSize = field("partitionBlockSize").toInt();
    long blockCount = field("partitionBlockCount").toInt();
    int fs = field("partitionFileSystem").toInt();
    QString text = "";
    text.append("Partition\n").append("Block size: ").append(QString::number(blockSize));
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

    return text;
}

QString SummaryPage::getDiskText(){
    int diskSize = field("DiskSize").toInt();
    int dimension = field("dimension").toInt();
    QString name = field("DiskName").toString();

    switch(diskSize){
    case 0:
        diskSize = 512;
        break;
    case 1:
        diskSize = 1024;
        break;
    case 2:
        diskSize = 2048;
        break;
    case 3:
        diskSize = 4096;
        break;
    case 4:
        diskSize = 8192;
        break;
    }

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
    return text;
}

int SummaryPage::nextId() const{
    return -1;
}
