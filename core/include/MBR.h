//
// Created by Leon Heindl on 17.08.2019.
//

#ifndef OS_PROJECT_MBR_H
#define OS_PROJECT_MBR_H

#include <list>

class Partition
namespace os_project {
    namespace mbr {
        /**
         * Master Boot Record Class
         * simulates a MBR and holds a array of partitions on the plate and the information witch of the partitions is the boot partition
         *
         */
        class MBR {
        private:
            /// array witch holds the list of partitions
            Partition** partitions;
            /// the number of partitions on the drive
            int partitionCount;
            /// the index of the boot part partition in the array
            int bootPartitionIndex;
        public:
            /**
             * Empty Contructor generates a MBR
             */
            MBR();

            /**
             * gets a partition by its index from the mbr
             * @param partitionIndex the index of the partition you want to get
             * @return the partition with of the index you requested nullptr if no partition exist to this index
             */
            Partition * getPartion(int partitionIndex);

            /**
             * adds a partition to teh mbr and returns it index
             * @param partition is a pointer of type partition witch will be added to the mbr
             * @return the index in the mbr where the partition is stored
             */
            int addPartition(Partition* partition);

            /**
             * Removes a partition from the mbr by its Index
             * @param partitionIndex of the partition you want to remove
             * @return returns false if the removal do not work fore example if no partition is mapped to the index true if the deletion worked
             */
            bool removePartition(int partitionIndex);

            /**
             * returns an array of all partitions
             * @param partitionArray a pointer to a array witch will be set to the pointers of partitions
             * @return returns the number of entrances of the array stored to partitionArray zero if no partitions are stored in teh mbr
             */
            int listPartions(Partition** partitionArray);

        };
    }
}

#endif //OS_PROJECT_MBR_H
