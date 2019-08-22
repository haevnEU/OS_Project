#ifndef PARTITION_H
#define PARTITION_H

class IFileSystem;

#include <exception>
#include <list>

#include "Block.h"

//! This namespace contains the core part of the project, everything about disk
namespace core {
    //! This namespace contains the logic part of each disk
    namespace logic{

        /**
         * @brief The Partition class
         * @details This class represent a partition with all required attributes and method.
         *          A partition contains the block information(size and amount) as well as the blocks itself.
         *          It also contains a file system and can be mounted. The partition can be formated and erased, as well as
         *          mounted and unmounted
         * @author Nils Milewski (10010480)
         */
        class Partition{
        private:
            /**
             * @brief blockSize_m Size of each block
             */
            unsigned long long blockSize_m;

            /**
             * @brief amountBlocks_m Amount of used blocks
             */
            unsigned long long amountBlocks_m;

            /**
             * @brief blocks_m The actual blocks
             */
            std::list<Block*>* blocks_m;

            /**
             * @brief fileSystem_m The used filesystem(INode, FAT)
             */
            IFileSystem* fileSystem_m;

            /**
             * @brief mounted_m States if the partition is mounted or not
             */
            bool mounted_m;

            /**
             * @brief Partition Copy Constructor
             * @details A partition copy operation is not allowed to ensure that the partition will not be accessed twice
             * @throws Allways throws a runtime exception
             */
            Partition(Partition* partition);

            /**
             * @brief Partition Copy Constructor
             * @details A partition copy operation is not allowed to ensure that the partition will not be accessed twice
             * @throws Allways throws a runtime exception
             */
            Partition(Partition &partition);

        public:

            /**
             * @brief Partition Constructor
             * @details This method constructs a new partition. All required attributes will be set and ininitalized
             *          The partition will not be mounted
             * @param blockSize Size of each block
             * @param amountBlocks Amount of the blocks, how many block should be created
             * @param fileSystem The underlying file system
             */
            Partition(unsigned long long blockSize, unsigned long long amountBlocks, IFileSystem* fileSystem);

            /**
             * @brief format This method formats the partition
             * @details A format operation contains of a check if the partition is mounted and could be erased
             *          If these check fails the operation will abort and return false.
             *          The first check is done to inspect the mounted attribute if its false the next check will be done
             *          Next check if the partition was erased, this is done with invoking the erase method, if this was succesfull
             *          the partition will be formated.
             *          Finally the operation as the constructor done will be executed
             * @param blockSize New Blocksize
             * @param amountBlocks New amount of blocks
             * @param fileSystem New File syste,
             * @return true if the partition was formated otherwise false
             */
            bool format(unsigned long long blockSize, unsigned long long amountBlocks, IFileSystem* fileSystem);

            /**
             * @brief erase This method erased the partition
             * @details First a check if the partition is mounted will be done if not the operation will abort
             *          and returns false.
             *          Next all attributes except filesystem and blocks will be set to zero (0)
             *          Following the filesystem will be deleted using its destructor
             *          Finally the blocks are cleared and deleted using a destructor
             *          Sidenote filesystem as wel as blocks will only deleted if neither one is a nullpointer
             * @return true iff the erase operation was succesfull
             */
            bool erase(void);

            /**
             * @brief blockSize getter of block size
             * @return blockSize_m
             */
            unsigned long long blockSize(void);

            /**
             * @brief amountBlocks getter of amount block
             * @return amountBlocks_m
             */
            unsigned long long amountBlocks(void);

            /**
             * @brief fileSystem getter of file system
             * @details This method is the primary way to interact with the underlying file system
             * @return fileSystem_m
             */
            IFileSystem* fileSystem(void);

            /**
             * @brief mount This method mounts the partition and sets the mounted_m attribute to true
             */
            void mount(void);

            /**
             * @brief mount This method unmounts the partition and sets the mounted_m attribute to false
             */
            void unmount(void);

            /**
             * @brief mount This method determines if the partition is mounted.
             * @return true iff the partition is mounted (attribtued mounted_m is true), otherwise false
             */
            bool isMounted(void);

            /**
             * @brief resize This method resizes the partition
             * @details This method resized the partition, it will shrink the partition if the new
             *          size is smaller than the previous size and grow if the new size is bigger
             *          than the previous size. If the partition will shrink data will be lost.
             * @param newSize New size of the partition
             */
            void resize(unsigned long long newSize);

            friend std::ostream& operator<< (std::ostream& os, Partition& partition);

        };
    } // logic
} // core

#endif // PARTITION_H
