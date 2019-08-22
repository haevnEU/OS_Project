#ifndef DETAILPAGE_H
#define DETAILPAGE_H

#include <QObject>
#include <QHBoxLayout>

#include "diskinfo.h"
#include "core/disk.h"
#include "resizepartition.h"

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

        static enum display{Disk_Info, Partition_Resize};

    private:
        /**
         * @brief workingDisk_m This is the disk which all windows should be using
         */
        core::disk::Disk* workingDisk_m;

        /**
         * @brief diskInfoPage This page shows all infomration about a specified disk
         */
        DiskInfo* diskInfoPage_m;

        /**
         * @brief diskInfoPage This page allows resizeing a partition from a specific partition of a specified disk
         */
        ResizePartition* resizePartition_m;

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
         * @brief setDisk This method sets the workind disk
         * @param disk New working disk
         * @details This method sets the working disk of all windows using their setDisk method
         */
        void setDisk(core::disk::Disk *disk);

        /**
         * @brief close This method closes all windows
         * @details This method calls the hide method from all available windows
         */
        void close(void);
    };
    } // window
} // ui
#endif // DETAILPAGE_H
