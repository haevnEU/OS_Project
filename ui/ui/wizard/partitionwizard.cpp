#include "partitionwizard.h"

using namespace ui::wizard;

PartitionWizard::PartitionWizard(unsigned long long diskSize, QWidget* parent) :QWizard(parent){
    setPage(pages::pages_enum::introPage, new pages::IntroPage("This wizard will guide you through the creation of a partition.", pages::pages_enum::partitionPage));
    setPage(pages::pages_enum::partitionPage, new pages::PartitionPage(diskSize));
    setPage(pages::pages_enum::summaryPage, new pages::SummaryPage(pages::pages_enum::partitionPage));
    setStartId(pages::pages_enum::introPage);
    setWizardStyle(QWizard::WizardStyle::NStyles);
}

PartitionWizard::~PartitionWizard(){
    QWizard::~QWizard();
}


core::logic::Partition* PartitionWizard::getResultedPartition(void){
    long blockSize = field("partitionBlockSize").toLongLong();
    long blockCount = field("partitionBlockCount").toLongLong();
    int fs = field("partitionFileSystem").toInt();

    switch(fs){
    case 0:
//        text.append("INode");
        break;
    case 1:
//        text.append("FAT");
        break;
    case 2:
//        text.append("CD-ROM");
        break;
    }

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

   return new core::logic::Partition(static_cast<unsigned long long>(blockSize), static_cast<unsigned long long>(blockCount), nullptr);
}

void PartitionWizard::done(int result){

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Finish", "Are you sure that you are done?", QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          QWizard::done(result);
      }
}
