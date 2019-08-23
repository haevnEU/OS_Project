/*
 * TODO
 * Write setpartition in detailpage
 * Refresh
 */





#include <QDebug>
#include "core/api.h"
#include "mainwindow.h"

#include <QPushButton>

#include <QListWidgetItem>
#include <QComboBox>
#include "../wizard/diskwizard.h"
#include "ui/pages/addfiledir.h"
#include "diskinfo.h"
#include <QTabWidget>
#include <QTableWidgetItem>
#include "../wizard/partitionwizard.h"
#include <QListWidgetItem>
#include "core/FAT.h"

using namespace ui::window;

MainWindow::MainWindow(){


    // 1. Initialize attributes and UI Elements

    // 1.1 Attributes
    disks = new std::vector<core::disk::Disk*>();
    // TODO Rename
    page = new DetailPage();

    // 1.2 UI Elements
    diskPane = new QListWidget;
    detailPane= new QHBoxLayout;
    partitionPane = new QListWidget();
    addPartition = new customUI::CustomListWidgetItem("Add", "plus.svg");

    toolPane = new QListWidget;
    rootItem = new customUI::CustomListWidgetItem("new", "plus.svg");
    diskInfoItem = new customUI::CustomListWidgetItem("State","info.svg");
    resizeItem = new customUI::CustomListWidgetItem("Resize","code.svg");
    formatItem = new customUI::CustomListWidgetItem("Format","trash-2.svg");
    defragItem = new customUI::CustomListWidgetItem("Defrag","layout.svg");
    showFragmentationItem = new customUI::CustomListWidgetItem("Show Fragmentation","align-center.svg");
    addFileDirItem = new customUI::CustomListWidgetItem("Add","plus.svg");
    closeAllWindowsItem = new customUI::CustomListWidgetItem("Close all window","x-circle.svg");
    displayContentItem = new customUI::CustomListWidgetItem("Display content","code.svg");
    // 2. Setup UI Elements
    diskPane->setFixedWidth(150);
    partitionPane->setFixedWidth(150);
    toolPane->setFixedWidth(150);


    // 3. Add UI Elements to container
    partitionPane->addItem(addPartition);

    diskPane->addItem(rootItem);

    toolPane->addItem(diskInfoItem);
    toolPane->addItem(resizeItem);

    toolPane->addItem(showFragmentationItem);
    toolPane->addItem(defragItem);

    toolPane->addItem(addFileDirItem);
    toolPane->addItem(displayContentItem);
    toolPane->addItem(formatItem);
    toolPane->addItem(closeAllWindowsItem);

    DBGitem = new customUI::CustomListWidgetItem("DISK INFO","State.svg");
    toolPane->addItem(DBGitem);

    layout = new QHBoxLayout;
    layout->addWidget(diskPane);
    layout->addWidget(partitionPane);
    layout->addWidget(toolPane);
    setLayout(layout);


    // Create Signal-Slot connections
    connect(toolPane, SIGNAL(itemActivated(QListWidgetItem*)), this, SLOT(controlPaneItemActivated(QListWidgetItem*)));

    connect(partitionPane, SIGNAL(itemActivated(QListWidgetItem*)), this, SLOT(partitionPaneItemActivated(QListWidgetItem*)));

    connect(diskPane, SIGNAL(currentRowChanged(int)), this, SLOT(diskPaneRowChanged(int)));
    connect(diskPane, SIGNAL(itemActivated(QListWidgetItem*)), this, SLOT(diskPaneItemActivated(QListWidgetItem*)));
    connect(API::GetInstance(), SIGNAL(diskChanged(void)), this, SLOT(diskChanged(void)));

}


void MainWindow::refreshUI(){
    refreshDisks();
    refreshPartition();
}

// Refresh the disk listwidget
void MainWindow::refreshDisks(){

    // 1. Retreive how many items are in the disk pane
    int idx = diskPane->count();
    // 2. Loop over all entries
    while(idx >= 0){
        // 2.1 take the widget at position idx, it will remove the item from the widget
        QListWidgetItem *it = diskPane->takeItem(idx);
        // 2.2 If the item is not the root item destroy it
        if(rootItem != dynamic_cast<customUI::CustomListWidgetItem*>(it)){
            delete it;

        }else{
            // 2.2 Otherwise add it again to the view
            diskPane->addItem(rootItem);
        }
        // 2.3 Decrement the index counter
        idx--;
    }

    // 3 Add all entries from the disk list again into the view
    for(unsigned long long i = 0; i < disks->size(); i++){
        // 3.1 Create a new Custom widget with hard drive icon
        customUI::CustomListWidgetItem* item = new customUI::CustomListWidgetItem(QString("Disk ").append(QString::number(i)),"hard-drive.svg");
        // 3.2 Create an zero based index and assign it to the userData from the ListItem
        unsigned long long  index = disks->size() - 1;
        item->setData(Qt::UserRole, QVariant(index));
        // 3.3 Add a new item, before the add disk entry, to the diskpane
        diskPane->insertItem(diskPane->count() - 1, item);
    }
}

// Refresing the partition pane
void MainWindow::refreshPartition(){

    // Most of the code is the same as refreshDisks()
    int idx = partitionPane->count();
    while(idx >= 0){

        QListWidgetItem *it = partitionPane->takeItem(idx);
        if(addPartition != dynamic_cast<customUI::CustomListWidgetItem*>(it)){
            delete it;

        }else{
            partitionPane->addItem(addPartition);
        }
        idx--;
    }

    // 0. Display partition from current disk iff the currentDisk is not a null pointer
    if(nullptr != workingDisk){
        // 1. Iterate over all available partition inside the disks MBR
        for(int i = 0; i < workingDisk->MBR()->MAX_PARTITION; i++){
            // 1.1 Check if the partition with index i exist
            if(nullptr != workingDisk->MBR()->getPartition(i)){
                customUI::CustomListWidgetItem* item;
                // 1.1.2 Create a new Custom widget with partition icon

                if(core::FAT* fs = dynamic_cast<core::FAT*>(workingDisk->MBR()->getPartition(i)->fileSystem())){
                    item = new customUI::CustomListWidgetItem(QString("Partition ").append(QString::number(i)),"layers.svg");
                }else if(core::FileSystem* fs = dynamic_cast<core::FileSystem*>(workingDisk->MBR()->getPartition(i)->fileSystem())){
                    item = new customUI::CustomListWidgetItem(QString("Partition ").append(QString::number(i)),"database.svg");
                }else{
                    item = new customUI::CustomListWidgetItem(QString("Partition ").append(QString::number(i)),"database.svg");
                }
                // 1.1.3 Add element to the view before the add sign
                partitionPane->insertItem(partitionPane->count() - 1, item);
            }
        }
    }

}

// Calles when the window is closed
void MainWindow::hideEvent(QHideEvent *event){
    // Close all open windows
    page->closeAll();
    // Close this
    this->close();
}

// Called when a new partition should be created
void MainWindow::partitionPaneItemActivated(QListWidgetItem* item){
    // 1. Check if the item is not a null pointer or the item is not the current item
    if(nullptr == item){
        // 1.1 if its so abort the operation
        return;
    }
    // 2. Check if a partition should be created
    if(item == addPartition){
        // 2.1 Check if the the user selected a valid disk from diskpane
        if(workingDisk != nullptr){
            // 2.1.1 Execute the partition wizard
            wizard::PartitionWizard wiz(workingDisk->MBR()->availableSpace());
            wiz.exec();
            // 2.1.2 Add the disk from the wizard to the mbr from selected disk
            workingDisk->MBR()->addPartition(wiz.getResultedPartition());
            // 2.1.3 Refresh the UI
            page->diskChanged();
            refreshPartition();
        }
    }
    // 4. Set currentPartition selection to this item
    currentPartitionWidgetItem = item;
}

// Called when a tool changed
void MainWindow::controlPaneItemActivated(QListWidgetItem* item){
    // 1. Check if the item is not a null pointer or the item is not the currentTool
    if(nullptr == item){
        return;
    }
    // 2. Disk info was clicked
    // Note the remaining else if are the same as this if statement
    //      they will not be documented more
    if(item == diskInfoItem){
        // Toggle view of the diskinfo page
        page->togglePage(DetailPage::display::Disk_Info);

    } else if(item == resizeItem){
        page->togglePage(DetailPage::display::Partition_Resize);
    }else if(item == formatItem){
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Format", "Are you sure that you want to format disk?\nAll data will be lost for ever", QMessageBox::Yes|QMessageBox::No);
          if (reply == QMessageBox::Yes) {
              int index = 0;
              workingDisk->MBR()->getPartition(index)->erase();
              wizard::PartitionWizard wiz(workingDisk->MBR()->availableSpace());
              wiz.exec();
              delete(workingDisk->MBR()->getPartition(index));

              workingDisk->MBR()->addPartition(index, wiz.getResultedPartition());
        }
    }else if(item == addFileDirItem){
        page->togglePage(DetailPage::display::Add_File_Dir);
    }else if(item == displayContentItem){
        page->togglePage(DetailPage::display::Display_Content);
    }else if(item == showFragmentationItem){
        page->togglePage(DetailPage::display::Show_Fragmentation);
    }else if(item == defragItem){
        page->togglePage(DetailPage::display::Defrag);
    }else if(item == closeAllWindowsItem){
        page->closeAll();
    }

    else if(item == DBGitem){
        QString name(workingDisk->name().c_str());
        unsigned long long size = workingDisk->capacity();
        for(int i = 0; i < workingDisk->MBR()->MAX_PARTITION; i++){
            qDebug() << "Partition: " << i;
            if(workingDisk->MBR()->getPartition(i) != nullptr){
                unsigned long long blocks = workingDisk->MBR()->getPartition(0)->amountBlocks();
                unsigned long long blockSize = workingDisk->MBR()->getPartition(0)->blockSize();

                qDebug() << "Name : " << name << " Size: " << QString::number(size);
                qDebug() << "Blocksize : " << QString::number(blockSize) << " amout: " << QString::number(blocks);
            }else{
                qDebug() << "Not Exist";
            }
        }

    }
    // 3. Set the current tool to this item
    currentTool = item;
}

void MainWindow::diskPaneItemActivated(QListWidgetItem* item){
    // 1. Check if the item is not a null pointer or the item is not the currentDisk
    if(nullptr == item){
        return;
    }
    // 2. Root item was clicked
    if(item == rootItem){
        // 2.1 Start new disk wizard
        wizard::DiskWizard wizard;
        wizard.exec();
        // 2.2 The wizard returns an accepted state
        if(wizard.result() == QDialog::Accepted){
            // 2.2.1 Push a new disk into the disk list
            disks->push_back(wizard.getResultedDisk());
            workingDisk = disks->at(disks->size() - 1);
            API::GetInstance()->setDisk(disks->at(disks->size() - 1));
            // 2.2.2 Refresh the UI
            refreshDisks();
        }
    }
    // 3. A disk was selected
    else{
        // 3.1 Get the index from the userData
        int index = item->data(Qt::ItemDataRole::UserRole).toInt();

        // 3.2 Set the working disk to corresponding disklist entry
        workingDisk = disks->at(index);
        API::GetInstance()->setDisk(disks->at(index));
        // 3.3 Change the disk for all open and further detail windows
        page->diskChanged();
        refreshPartition();
    }

    // Change the currentDiskWidgetItem to this item
    currentDiskWidgetItem = item;
}


void MainWindow::partitionPaneRowChanged(int row){
    if(row < partitionPane->count()) {
        if(row >= 0 && row < workingDisk->MBR()->MAX_PARTITION){
            page->setPartition(row);
            refreshPartition();
        }
    }
}

void MainWindow::diskChanged(){
    refreshPartition();
}

void MainWindow::diskPaneRowChanged(int row){
    if(row < diskPane->count()) {
        if(row >= 0 && row < disks->size()){
            workingDisk = disks->at(row);
            API::GetInstance()->setDisk(disks->at(row));
            disks->at(row);
            page->diskChanged();
            refreshPartition();
        }else{
            workingDisk = nullptr;
            API::GetInstance()->clearDisk();
            refreshPartition();
        }
    }
}
