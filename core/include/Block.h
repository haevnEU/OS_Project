#ifndef _OS_PROJECT_BLOCK_H_
#define _OS_PROJECT_BLOCK_H_

#include <iostream>
#include <bitset>
#include <iomanip>

#include "Definitionsh.h"

namespace os_project {
    namespace hard_disk {

        /**
         * This class provides a disk block. It is the smallest entity to store data on a simulated disk,
         * It contains a size in bytes which determines the size of data array from type unsigned char.
         * It is also possible to assign a cluster index
         *
         * @author Nils Milewski (nimile)
         * @date July 23 2019
         * @version 1.0
         */
        class Block {
        private:

            /// This is the actual data, its size is block size * 1byte
            unsigned char* data_m;

            /// This variable determines the size of this block
            int blockSize_m;

            /// This is the block index inside a cluster of blocks
            int clusterIndex_m;

            /// This is the current state of this block, @see Definitions.h
            os_project::definitions::block_state state_m;

        public:
            /**
             * Creates a new block with given index and size
             *
             * @param size Size of the block, data type is int
             *
             */
            Block(int size);

            ~Block(void);

            /**
             * This method sets a specific data bit at given position
             *
             * @param bit Position where the bit must be set
             *
             * @contract bit must be smaller than block size * 1byte
             */
            void setBit(int bit);

            /**
             * This method sets given binary bits using setHex
             * @param bin 16 bit Binary data which should be set
             * @param offset Position inside the data block, the offset will be multiplied by 8
             */
            void setBin(int bin, int offset);

            /**
             * This method sets given hex bits using setHex
             * @param bin 16 bit hexadecimal data which should be set
             * @param offset Position inside the data block, the offset will be multiplied by 8
             */
            void setHex(int hex, int offset);

            /**
             * This method sets the data from the block
             *
             * @param data New data which the block should hold. Datatype: const unsigned char*
             *
             * @contract The size of the data must equal the block size
             */
            void setData(const unsigned char* data);

            /**
             * This method sets a specific data bit at given position
             *
             * @param bit Position where the bit must be set
             *
             * @contract bit must be smaller than block size * 1byte
             */
            void clearBit(int bit);

            /**
             * This method clears the data from the block
             */
            void clearData(void);

            /**
             * This method tests a specific data bit at given position
             *
             * @param bit Position where the bit must be set
             *
             * @contract bit must be smaller than block size * 1byte
             */
            bool isBitSet(int pos);

            /**
             * This method sets the block state
             *
             * @param state New state of the block. Details @see Definitions.h
             *
             * @contract state must be a valid block_state
             */
            void setState(os_project::definitions::block_state state_t);

            /**
             * This method returns the state of the block
             *
             * @return Current state of the block.
             *		   To receive details about the state @see Definitions.h
             */
            const os_project::definitions::block_state getState(void);

            /**
             * This method returns the block size in bytes
             *
             * @return size of the block in bytes
             */
            int blockSize(void);

            /**
             * This method returns the block size in bytes
             *
             * @return data of the block as const unsigned char*
             */
            const unsigned char* getData(void);

            /**
             * This method returns the index of this block inside a cluster
             *
             * @return index of the block
             */
            const int getClusterIndex(void);

            /**
             * TODO write comment
             */
            friend std::ostream& operator<< (std::ostream& out, Block& block);

        };



    }
}

#endif //_OS_PROJECT_BLOCK_H_