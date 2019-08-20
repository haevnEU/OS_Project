//
// Created by Leon Heindl on 18.08.2019.
//

#ifndef OS_PROJECT_FILESYSTEM_H
#define OS_PROJECT_FILESYSTEM_H

#endif //OS_PROJECT_FILESYSTEM_H
namespace os_project {
    namespace Filesystem {
        /**
         * abstract class for as base for inode and fat file systems
         */
        class Filesystem{
        private:
            /// start block of the partition on witch the filesystem lays
            Block* startBlock;
            /// size of a block in a partition
            unsigned long int blockSize;
            /// block holds the amount of blocks in the partition
            unsigned long int blockCount;
        public:
            /**
             * Set the start block of the partion in the filesystem
             * @param startBlock of the partition for use in filesystem
             */
            void setStartBlock (Block startBlock);

            /**
             * Get the startBlock of the filesystem
             * @return the value of startBlock sould be the same as the start block of the partition
             */
            Block getStartBlock ();

            /**
             * Set the value of blockSize sets the value of the block size from the partition for use in the file system
             * @param new_var the new value of blockSize
             */
            void setBlockSize (unsigned long int new_var);

            /**
             * Get the value of blockSize
             * @return the value of blockSize
             */
            unsigned long int getBlockSize ();

            /**
             * Set the value of blockCount
             * @param new_var the new value of blockCount
             */
            void setBlockCount (unsigned long int new_var);

            /**
             * Get the value of blockCount
             * @return the value of blockCount
             */
            unsigned long int getBlockCount ();


            /**
            * Fragmentation in percent
            * @return returns the fragmentation of the filesystem in percent
            */
            virtual char fragmentation ()
            {
            }


            /**
             * defragmanting the filesystem
             * @return int
             */
            virtual int defragmentation ()
            {
            }


            /**
             * get free space in the filesystem
             * @return filesystem free space in bytes
             */
            virtual unsigned long int getFreeSpace ()
            {
            }


            /**
             * get used space in the filesystem
             * @return filesystem used space in bytes
             */
            virtual unsigned long int getUsedSpace ()
            {
            }


            /**
             * the maximum capasity of fylesystem
             * @return filesystem maximal storage in bytes
             */
            virtual unsigned long int getMaximumSpace ()
            {
            }


            /**
             */
            virtual void createFolder ()
            {
            }


            /**
             */
            virtual void createFile ()
            {
            }


            /**
             */
            virtual void cangeFileAtributs ()
            {
            }


            /**
             */
            virtual void readFile ()
            {
            }


            /**
             */
            virtual void writeFile ()
            {
            }
        };
    }
}