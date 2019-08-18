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
             * Set the value of startBlock
             * @param new_var the new value of startBlock
             */
            void setStartBlock (Block new_var);

            /**
             * Get the value of startBlock
             * @return the value of startBlock
             */
            Block getStartBlock ();

            /**
             * Set the value of blockSize
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
            * @return char
            */
            virtual char fragmentation ()
            {
            }


            /**
             * @return int
             */
            virtual int defragmentation ()
            {
            }


            /**
             * @return unsigned long int
             */
            virtual unsigned long int getFreeSpace ()
            {
            }


            /**
             * @return unsigned long int
             */
            virtual unsigned long int getUsedSpace ()
            {
            }


            /**
             * @return unsigned long int
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