#ifndef MASTERBOOTRECORD_H
#define MASTERBOOTRECORD_H

#include "partition.h"

//! This namespace contains the core part of the project, everything about disk
namespace core {
    //! This namespace contains the disk part of each disk
    namespace disk{
        /**
         * @brief The MasterBootRecord class
         * @details This class represent a Master Boot Record entry
         * @author Nils Milewski (10010480)
         */
        class MasterBootRecord{
        public:

            /**
             * @brief MAX_PARTITION This variable contains the maximum of available partition
             */
            const static int MAX_PARTITION = 4;
        private:

            /**
             * @brief partitions_m This attribute is array of all registred partitions
             */
            logic::Partition* partitions_m[MAX_PARTITION];

            /**
             * @brief diskCapacity_m This attributes contains the size of the disk
             */
             unsigned long long diskCapacity_m;

            /**
             * @brief availableDiskCapacity_m This attributes contains the available size of the disk
             */
             unsigned long long availableDiskCapacity_m;

        public:

            /**
             * @brief MasterBootRecord Constructor
             * @details This Constructor sets the disk capacity and creates the array of partitions (partitions_m)
             *          with null pointer
             * @param diskCapacity
             */
            MasterBootRecord( unsigned long long diskCapacity);

            /**
             * @brief getPartition This method queries a partition from the Master Boot Record
             * @details First a check about the index will be done, iff the index is out of range a exception will be thrown.
             *          Next a nullpointer check will be done, iff index argument points to a nullpointer entry a exception will be thrown.
             *          Iff all checks are done without an exceptiont the querried partition will be returned
             * @param index Index to access, range form 0 to 3
             * @return Partition assoziated with index Index
             * @throws runtime error if the index is out of range or the access would be a nullpointer
             */
            logic::Partition* getPartition(int index);
            /**
             * @brief addPartition Adds a new partition to the MBR
             * @details First a check if enough space is available is done.
             *          Next the MBR iterates over all entries from his partition table,
             *          iff the MBR finds a free spot (entry is nullptr) the MBR creates a new partition and returns true
             *          otherwise the MBR iterates to the end if all entries are used (not nullptr) false will be returned.
             * @param blockSize Size of the block in bytes
             * @param amountBlocks Amount of blocks the partition owns
             * @param fileSystem Filesystem of the Partition
             * @return true if the Partition was created otherwise false
             */
            bool addPartition( long blockSize,  long amountBlocks, FileSystem::fileSystemType fileSystem);

            /**
             * @brief addPartition Adds a new partition to the MBR
             *  @details First a check if enough space is available is done.
             *          Next the MBR tries to insert a new Partition at given index, iff the spoti a free spot (entry is nullptr)
             *          the MBR creates a new partition and returns true otherwise the MBR false will be returned.
             * @param index Index where the partition should be located, range 0 - 3
             * @param blockSize Size of the block in bytes
             * @param amountBlocks Amount of blocks the partition owns
             * @param fileSystem Filesystem of the Partition
             * @return true if the Partition was created otherwise false
             */
            bool addPartition(int index,  long blockSize,  long amountBlocks, FileSystem::fileSystemType fileSystem);

            /**
             * @brief removePartition Removes a partition
             * @details This method removes a partiton at given index.
             *          First a check will be done to ensure that the index is not out of range(0 - 3),
             *          if its out of range a runtimeexception will be thrown
             *          Next a check will be done to ensure that the partition is not a nullpoint,
             *          if its a nullpointer a runtimeexception will be trhown
             *          Iff all checks are done without an exception the partiton will be removed using his destructor
             *          and assign a nullpointer to the spot inside the partition table
             * @param index
             * @return
             */
            bool removePartition(int index);

            unsigned long long availableSpace(void);


            friend std::ostream& operator<< (std::ostream& os, MasterBootRecord& mbr);
            bool addPartition(logic::Partition *partition);
            bool addPartition(int index, logic::Partition *partition);
        };
    } // disk
} // core

#endif // MASTERBOOTRECORD_H
