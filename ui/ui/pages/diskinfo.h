#ifndef DISKINFO_H
#define DISKINFO_H

#include <QLabel>
#include <QObject>
#include <QGridLayout>

#include "core/disk.h"

//! This namespace contains all ui elements for this project
namespace ui{
    //! This namespace contains all windows for this project
    namespace window{
    /**
     * @brief This class provides a disk info window
     * @details This class is a window which displays all basic information about a disk
     *          As basic information we understand the name, size and MBR Entries.
     *          From the MBR entry only the partitions are shown with the basic information
     * @author Nils Milewski (10010480)
     */
    class DiskInfo : public QWidget {

        Q_OBJECT

    private:
        /**
         * @brief diskLayout This provides a container for the disk info layout
         */
        QGridLayout* diskLayout;

        /**
         * @brief partition1Layout This provides a container for the parititon 1
         */
        QGridLayout* partition1Layout;

        /**
         * @brief partition1Layout This provides a container for the parititon 2
         */
        QGridLayout* partition2Layout;

        /**
         * @brief partition1Layout This provides a container for the parititon 3
         */
        QGridLayout* partition3Layout;

        /**
         * @brief partition1Layout This provides a container for the parititon 4
         */
        QGridLayout* partition4Layout;

        /**
         * @brief lbDiskCapacity This UI element provides the displaying of the space functionality
         */
        QLabel* lbDiskCapacity;

        /**
         * @brief lbDiskName This UI element provides the displaying of the disk name
         */
        QLabel* lbDiskName;

        /**
         * @brief lbPartition1Size This UI element provides the display of partition 1 size
         */
        QLabel* lbPartition1Size;

        /**
         * @brief lbPartition1AmountBlocks This UI element provides the display of partition 1 used blocks
         */
        QLabel* lbPartition1AmountBlocks;

        /**
         * @brief lbPartition1Mounted This UI element provides the display about the mounted state of partition 1
         */
        QLabel* lbPartition1Mounted;

        /**
         * @brief lbPartition1Size This UI element provides the display of partition 2 size
         */
        QLabel* lbPartition2Size;

        /**
         * @brief lbPartition1AmountBlocks This UI element provides the display of partition 2 used blocks
         */
        QLabel* lbPartition2AmountBlocks;

        /**
         * @brief lbPartition1Mounted This UI element provides the display about the mounted state of partition 2
         */
        QLabel* lbPartition2Mounted;

        /**
         * @brief lbPartition1Size This UI element provides the display of partition 3 size
         */
        QLabel* lbPartition3Size;

        /**
         * @brief lbPartition1AmountBlocks This UI element provides the display of partition 3 used blocks
         */
        QLabel* lbPartition3AmountBlocks;

        /**
         * @brief lbPartition1Mounted This UI element provides the display about the mounted state of partition 3
         */
        QLabel* lbPartition3Mounted;

        /**
         * @brief lbPartition1Size This UI element provides the display of partition 4 size
         */
        QLabel* lbPartition4Size;

        /**
         * @brief lbPartition1AmountBlocks This UI element provides the display of partition 4 used blocks
         */
        QLabel* lbPartition4AmountBlocks;

        /**
         * @brief lbPartition1Mounted This UI element provides the display about the mounted state of partition 4
         */
        QLabel* lbPartition4Mounted;

        /**
         * @brief workingDisk_m This attribute is used as the disk which all information contains
         */
        core::disk::Disk* workingDisk_m;

    public:
        /**
         * @brief DiskInfo Constructor
         * @details This constructor initalizes all required attributes and UI Elements,
         *          it will also create the whole UI.
         */
        DiskInfo();

        /**
          * @brief ~DiskInfo Destructor
          * @details This destructor will destroy all UI elements.
          *          It will not destruct the workingDisk_m attirbute
          */
        ~DiskInfo();

        /**
         * @brief setDisk This method sets the working disk
         * @param disk New working disk
         * @details This method sets the working disk of this windows
         */
        void setDisk(core::disk::Disk* workingDisk_m);

    };
    } // window
} // ui

#endif // DISKINFO_H
