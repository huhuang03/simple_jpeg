//
// Created by huhua on 2021/10/29.
//

#ifndef SIMPLE_JPEG_HUMAN_ENCODING_H
#define SIMPLE_JPEG_HUMAN_ENCODING_H

// ok, define the interface.

/**
 * What can I do if the leading is 0??
 * 1 01 110 000 is something that validate huffman encoding
 * So the byte is not a right encoding.
 *
 * bit is something good, but I don't think that I can have bit date.
 */
class HuffmanEncoding {
    unsigned char* value;
    // len is the bit len, not byte len
    int len;
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
 * Ok, let's do the coding.
 */
void huffmanEncode(int *codes, int len, HuffmanEncoding *output);

#endif //SIMPLE_JPEG_HUMAN_ENCODING_H
