#ifndef DETAILPAGE_H
#define DETAILPAGE_H

#include <QObject>
#include <QHBoxLayout>

#include "diskinfo.h"
#include "core/disk.h"
#include "resizepartition.h"
#include "addfiledir.h"
#include "modifyfiledir.h"
#include "removefiledir.h"
#include "showfragmentation.h"
#include "defrag.h"
#include "contentdisplay.h"

//! This namespace contains all ui elements for this project
namespace ui{
    //! This namespace contains all windows for this project
    namespace window{
    /**
     * @brief This class handles all new created windows
     * @details This class is a handler for UI windows, it will create and destroy windows
     *          As well as manage their data content.
     * @author Nils Milewski (10010480)
     */
    class DetailPage : QObject{

        Q_OBJECT

    public:

        static enum display{Disk_Info, Partition_Resize,
                            Add_File_Dir, Remove_File_Dir, Modify_File_Dir, Defrag, Show_Fragmentation,
                            Display_Content};

    private:

        /**
         * @brief diskInfoPage This page shows all infomration about a specified disk
         */
        DiskInfo* diskInfoPage_m;

        /**
         * @brief diskInfoPage This page allows resizeing a partition from a specific partition of a specified disk
         */
        ResizePartition* resizePartition_m;

        /**
         * @brief addFileDir_m This page allows adding a file or directory to the filesystem
         */
        AddFileDir* addFileDir_m;

        /**
         * @brief modifyFileDir_m This page allows modify a file or directory to the filesystem
         */
        ModifyFileDir* modifyFileDir_m;

        /**
         * @brief removeFileDir_m This page allows removing a file or directory to the filesystem
         */
        RemoveFileDir* removeFileDir_m;

        /**
         * @brief showFragmenation_m This page shows the partition fragmentation
         */
        ShowFragmentation* showFragmenation_m;

        /**
         * @brief defrag_m This page shows the partition fragmentation
         */
        ui::window::Defrag* defrag_m;

        /**
         * @brief defrag_m This page shows the content of a partition fragmentation
         */
        ContentDisplay* display_content;


    public:
        /**
         * @brief DetailPage Constructor
         * @details This constructor creates all required attritbutes and windows
         */
        DetailPage();

        /**
         * @brief ~DetailPage Destructor
         * @details This destructor calls all windows destructors and frees his used heap memory.
         *          It will not destruct the workinDisk_m attribute.
         */
        virtual ~DetailPage();

        /**
         * @brief togglePage This method toggles the visibility of a window
         * @param which Which window should be toggled @see static enum display
         * @details This method toggles the visibility of a window. The window must be specified by
         *          the parameter which, which is an enum of all possible windows.
         *          If a window is allready visible it will hide the window.
         *          If a window is allready hidden it will show the window.
         */
        void togglePage(display which);

        /**
         * @brief diskChanged This method should be called if the disk changes
         * @details This method should be invoked if the disk changed to another one.
         *          This method will handle all requirements to refresh the UI
         */
        void diskChanged();

        /**
         * @brief setPartition This method sets the current partiton of the working disk
         * @param disk New working disk
         * @details This method sets the current partition of the disk of all windows using
         * their setPartition method
         */
        void setPartition(int idx);

        /**
         * @brief close This method closes all windows
         * @details This method calls the hide method from all available windows
         */
        void closeAll(void);

    private slots:
        void currentDiskChanged(void);


        void currentPartitionIndexChanged(void);
    };
    } // window
} // ui
#endif // DETAILPAGE_H
