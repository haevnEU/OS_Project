#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>

namespace logic{
enum block_state{
    free, reserved, corrupted
};

/**
 * @brief The Block class
 * @details This class implementes all required methods and attributes for a block
 *          A Block is used as the smallest entity which can be addressed
 * @author Nils Milewski (10010480)
 */
class Block{
private:

    /// This is the actual data, its size is block size * 1byte
    unsigned char* data_m;

    /// This variable determines the size of this block
    /// TODO maybe remove
    unsigned long blockSize_m;

    /// This is the current state of this block, @see Definitions.h
    block_state state_m;

public:
    /**
     * Creates a new block with given index and size
     *
     * @param size Size of the block, data type is int
     *
     * @param index Index of the block inside a block cluster, data type is int
     */
    Block(unsigned long blockSize);

    ~Block(void);

    /**
     * This method sets the block state
     *
     * @param state New state of the block. Details @see Definitions.h
     *
     * @contract state must be a valid block_state
     */
    void setState(block_state state_t);

    /**
     * This method returns the state of the block
     *
     * @return Current state of the block.
     *		   To receive details about the state @see Definitions.h
     */
    const block_state state(void);

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
    const unsigned char* data(void);

    /**
     * sets byte in block
     * @author Leon
     * @param offset the index in block
     * @param byte the byte to set
     * @return returns false if index is out of bounce
     */
    bool setByte(int offset,char byte);
    /**
     * gets byte out of block
     * @author Leon
     * @param offset index in the block
     * @return the byte value of the index in the block if offset out of bounce returns 0
     */
    char getByte(int offset);

};
}
#endif // BLOCK_H
