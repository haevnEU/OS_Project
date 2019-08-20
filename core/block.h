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
     * TODO write comment
     */
    friend std::ostream& operator<< (std::ostream& out, Block& block);

};
}
#endif // BLOCK_H
