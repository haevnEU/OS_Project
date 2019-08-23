#include "diskwizard.h"

using namespace ui::wizard;

DiskWizard::DiskWizard(QWidget* parent) : QWizard (parent){
    setPage(pages::pages_enum::introPage, new pages::IntroPage("This wizard will guide you through the creation of a disk.", pages::pages_enum::diskPage));
    setPage(pages::pages_enum::diskPage, new pages::DiskPage());
    setPage(pages::pages_enum::partitionPage, new pages::PartitionPage());
    setPage(pages::pages_enum::summaryPage, new pages::SummaryPage(pages::pages_enum::diskPage | pages::pages_enum::partitionPage));
    setStartId(pages::pages_enum::introPage);
    setWizardStyle(QWizard::WizardStyle::NStyles);
}


core::disk::Disk *DiskWizard::getResultedDisk(){

    QString name = field("DiskName").toString();
    unsigned long long capacity = field("DiskSize").toLongLong();
    int dimension = field("dimension").toLongLong();
    switch(dimension){
    case 0:
        capacity *= KB;
        break;
    case 1:
        capacity *= MB;
        break;
    case 2:
        capacity *= GB;
        break;
    case 3:
        capacity *= TB;
        break;
    }
    core::disk::Disk* disk = new core::disk::Disk(capacity, name.toStdString());

    bool partition = field("createPartition").toBool();
    if(partition){
        unsigned long long blockSize = field("partitionBlockSize").toLongLong();
        unsigned long long amluntBlocks = field("partitionBlockCount").toLongLong();
        switch(blockSize){
        case 0:
            blockSize = 512;
            break;
        case 1:
            blockSize = 1024;
            break;
        case 2:
            blockSize = 2048;
            break;
        case 3:
            blockSize = 4096;
            break;
        case 4:
            blockSize = 8192;
            break;
        }
        int fs = field("partitionFileSystem").toInt();
        core::FileSystem::fileSystemType fileSystem;
        switch(fs){
            // INode
            case 0:
                fileSystem = core::FileSystem::fileSystemType::INode;
                break;
            // FAT
            case 1:
                fileSystem = core::FileSystem::fileSystemType::FAT;
                break;
            // CD-ROM
            case 2:
                fileSystem = core::FileSystem::fileSystemType::CD_ROM;
                break;
            default:
                fileSystem = core::FileSystem::fileSystemType::other;
        }
        disk->MBR()->addPartition(blockSize, amluntBlocks, fileSystem);
    }

    return disk;
}

void DiskWizard::done(int result){
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Finish", "Are you sure that you are done?", QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          QWizard::done(result);
      }
}
