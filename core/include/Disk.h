//
// Created by Leon Heindl on 17.08.2019.
//

#ifndef OS_PROJECT_DISK_H
#define OS_PROJECT_DISK_H

#endif //OS_PROJECT_DISK_H
namespace os_project {
    namespace Disk {
        class MBR;
        /**
        * class Disk
        *
        */
        class Disk {
        private:
            /// holds the storage capacity of the drive in bytes
            unsigned long int storageCapacity;
            ///stores the disk name of one char for example C
            char diskName;
            ///stores a pointer to the disks master boot record
            MBR * mbr;
        public:
            /**
             * @param  storageCapacity storage capacity of drive in bytes
             * @param  a single char as drive name
             */
            Disk(unsigned long int storageCapacity, char name);

            /**
             * Empty Destructor
             */
            virtual ~Disk();

            /**
             * Get the storage capacity of the drive in bytes
             * @return the storage capacity of the drive in bytes
             */
            unsigned long int getStorageCapacity ();

            /**
             * Set the disks name
             * @param a single char as drive name
            */
            void setDiskName (char diskName);

            /**
             * Get the disks name
             * @return a single char drive name
             */
            char getDiskName ();
            /**
             * Set the master boot record of the drive
             * @param pointer to a MBR
             */
            void setMbr (MBR * mbr);

            /**
             * Get the master boot record of the drive
             * @return a pointer to a MBR
             */
            MBR * getMbr ();

        };

    }
}