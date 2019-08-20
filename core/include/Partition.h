//
// Created by Leon Heindl on 18.08.2019.
//

#include "Filesystem.h"

#ifndef OS_PROJECT_PARTITION_H
#define OS_PROJECT_PARTITION_H

#endif //OS_PROJECT_PARTITION_H
namespace os_project {
    namespace Partition {
        /**
         * Class simulatiting a Partition
         */
        class Partition {
        private:
            /// pointer to start storage Block of the partition
            Block * startBlock;
            /// the size of blocks in the partition in beytes
            unsigned long int blockSize;
            /// The amount ofs block in the partition
            unsigned long int blockCount;
            /// a pointer to the file system on the partition
            FileSystem* fileSystem;
        public:
            /** Consturctor with initiates a instance of a partition
             * @param  blockSize the size of one block in a partition in beytes
             * @param  blockCount the amount of blocks in a partition
             * @param  fileSystem the file system for the partition
            */
            Partition(unsigned long blockSize, unsigned long blockCount,os_project::Filesystem::Filesystem *fileSystem);

            /**
             * Get the first block of the Partition
             * @return a pointer to the start block of the partition
             */
            Block* getStartBlock ();

            /**
             * Get the size of a partition blocks
             * @return the size of a block in the partition in beytes
             */
            unsigned long int getBlockSize ();

            /**
             * Resizes the size of the Partition
             * @param new_var the new value of blockCount
             */
            void resizePartition (unsigned long int blockCount);

            /**
             * gets the a mount of blocks in the partition
             * @return returns the amount of blocks in the partition
             */
            unsigned long int getBlockCount ();

            /**
             * Set the filesystem to of the Partition
             * @param a pointer to a class inhernetd from filesystem
             */
            void setFileSystem (os_project::Filesystem::Filesystem* filesystem);

            /**
             * Get the pointer to the filesystem
             * @return a pointer to a class inhereted from filesystem
             */
            os_project::Filesystem::Filesystem* getFileSystem ();


        };
    }
}
