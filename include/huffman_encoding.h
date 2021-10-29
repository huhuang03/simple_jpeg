//
// Created by huhua on 2021/10/29.
//

#ifndef SIMPLE_JPEG_HUMAN_ENCODING_H
#define SIMPLE_JPEG_HUMAN_ENCODING_H

// ok, define the interface.
#include <vector>

/**
 * What can I do if the leading is 0??
 * 1 01 110 000 is something that validate huffman encoding
 * So the byte is not a right encoding.
 *
 * bit is something good, but I don't think that I can have bit date.
 *
 * Should we use more space to simple code?
 * For now, let's do this?
 *
 * This is just a simple encoding, so we do the simple way.
 */
class HuffmanEncoding {
    std::vector<unsigned char> value;
    // big encoding, or little encoding?
//    unsigned char* value;
    // len is the bit len, not byte len
//    int len;
    // fuck, we still need provider the tostring
    friend std::ostream & operator<<(std::ostream &os, const HuffmanEncoding &huffmanEncoding);
};

enum HuffmanStartsWith {
    ZERO, ONE
};

/**
 * We need output the coding.
 *
 * But how can we define the coding, just use byte or something else?
 *
 * We need think about it.
 *
 * A byte is not good to use, and not good to determine it's length.
 *
 * So you have any other idea?
 *
 * If you don't have any greet idea, I will define an struct to present the Huffman encoding.
 *
 * *the output* size should same as the codes.
 *
 * Still I need decide how the param starsWith looks like.
 *
 * Ok, let's do the coding.
 */
void huffmanEncode(int *codes, int len, HuffmanEncoding *output, HuffmanStartsWith startsWith = HuffmanStartsWith::ONE);

#endif //SIMPLE_JPEG_HUMAN_ENCODING_H
