#ifndef DISK_H
#define DISK_H

#include <iostream>
#include <string>
#include <exception>

#include "masterbootrecord.h"

namespace disk{
    /**
     * @brief The Disk class
     * @details This class is a representation of a physical disk
     * @author Nils Milewski (10010480)
     */
    class Disk {
    private:

        /**
         * @brief capacity_m This attributes contains the size of the disk
         */
        long capacity_m;

        /**
         * @brief MBR_m This attribute represents a Master Boot Recorc entry
         */
        MasterBootRecord* MBR_m;

        /**
         * @brief name_m This attributes contains the manufactor name
         */
        std::string name_m;

        /**
         * @brief Disk Copy Constructor
         * @details A disk copy operation is not allowed as a result to
         *          represent a physical hard drive
         * @throws Allways throws a runtime exception
         */
        Disk(Disk &disk);

        /**
         * @brief Disk Copy Constructor
         * @details A disk copy operation is not allowed as a result to
         *          represent a physical hard drive
         * @throws Allways throws a runtime exception
         */
        Disk(Disk* disk);

    public:
        /**
         * @brief Disk Constructor
         * @details This constructor creates a new Disk with an empty Master Boot Record
         * @param capacity This argument will be assigned to capacity_m and specify the disk capactiy
         * @param name This argument will be assigned to name_m and specify the manufcator name
         */
        Disk(long capacity, std::string name);

        /**
         * @brief Disk Constructor
         * @details This constructor creates a new Disk with an empty Master Boot Record
         * @param capacity This argument will be assigned to capacity_m and specify the disk capactiy
         * @param name This argument will be assigned to name_m and specify the manufcator name
         */
        Disk(long capacity, const char* name);

        /**
         * @brief capacity This method returns the disk capacity
         * @return capacity_m
         */
        long capacity(void);

        /**
         * @brief name This method returns the manufcator name of the disk
         * @return name_m
         */
        const std::string name(void);

        /**
         * @brief MBR This method returns the Master Boot Record
         * @return mbr_m
         */
        MasterBootRecord* MBR(void);

        friend std::ostream& operator<< (std::ostream& os, Disk& disk);

    };

}
#endif // DISK_H
