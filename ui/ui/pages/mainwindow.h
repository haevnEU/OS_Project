#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QWidget>
#include <QLayout>
#include <QListWidget>
#include <QGridLayout>

#include "core/disk.h"
#include "detailpage.h"
#include "../customUI/CustomControlBar.h"
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
        ui::customUI::CustomControlBar* tmp;
        QListWidget* diskPane;
        QListWidgetItem* currentDisk;
        QListWidget* partitionPane;
        QListWidgetItem* currentPartition;
        QListWidget* toolPane;
        QListWidgetItem* currentTool;


        ui::customUI::CustomListWidgetItem* rootItem;
        ui::customUI::CustomListWidgetItem* diskInfoItem;
        ui::customUI::CustomListWidgetItem* resizeItem;


        ui::customUI::CustomListWidgetItem* addPartition;
        std::vector<core::disk::Disk*>* disks;
        core::disk::Disk* workingDisk;

    public:
        MainWindow();

        ~MainWindow();

        void refreshDisks(void);
        void refreshPartition(void);

        void refreshUI();

    protected:
        void hideEvent(QHideEvent* event) override;

    public slots:
        void diskPaneItemClicked(QListWidgetItem* item);
        void click();
        void controlPaneItemClicked(QListWidgetItem *item);
        void partitionPaneItemClicked(QListWidgetItem *item);
    };
    } // window
} // ui
#endif // MAINWINDOW_H
