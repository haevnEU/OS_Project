#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QWidget>
#include <QLayout>
#include <QListWidget>
#include <QGridLayout>

#include "core/disk.h"
#include "detailpage.h"
#include "../customUI/customlistwidgetitem.h"

//! This namespace contains all ui elements for this project
namespace ui{
    //! This namespace contains all windows for this project
    namespace window{
    /**
     * @brief The MainWindow class
     */
    class MainWindow : public QWidget{
        Q_OBJECT
    private:
        DetailPage* page;
        QTabWidget *tabWidget;


        QHBoxLayout *layout;
        QHBoxLayout* detailPane;
        QListWidget* diskPane;
        QListWidgetItem* currentDiskWidgetItem;
        QListWidget* partitionPane;
        QListWidgetItem* currentPartitionWidgetItem;
        QListWidget* toolPane;
        QListWidgetItem* currentTool;


        ui::customUI::CustomListWidgetItem* DBGitem;
        ui::customUI::CustomListWidgetItem* rootItem;
        ui::customUI::CustomListWidgetItem* diskInfoItem;
        ui::customUI::CustomListWidgetItem* resizeItem;
        ui::customUI::CustomListWidgetItem* formatItem;
        ui::customUI::CustomListWidgetItem* defragItem;
        ui::customUI::CustomListWidgetItem* showFragmentationItem;
        ui::customUI::CustomListWidgetItem* addFileDirItem;
        ui::customUI::CustomListWidgetItem* closeAllWindowsItem;
        ui::customUI::CustomListWidgetItem* displayContentItem;

        ui::customUI::CustomListWidgetItem* addPartition;
        std::vector<core::disk::Disk*>* disks;
        core::disk::Disk* workingDisk;

    public:
        MainWindow();


        void refreshDisks(void);
        void refreshPartition(void);

        void refreshUI();

    protected:
        void hideEvent(QHideEvent* event) override;

    public slots:
        void diskPaneItemActivated(QListWidgetItem *item);
        void controlPaneItemActivated(QListWidgetItem *item);
        void partitionPaneItemActivated(QListWidgetItem *item);
        void diskPaneRowChanged(int row);
        void partitionPaneRowChanged(int row);
        void diskChanged();

    };
    } // window
} // ui
#endif // MAINWINDOW_H
