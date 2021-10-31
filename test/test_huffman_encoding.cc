//
// Created by huhua on 2021/10/29.
//
//
//TEST()

#include <gtest/gtest.h>
#include "huffman_encoding.h"
#include <iostream>


TEST(Hello, helloTest) {
    const unsigned int times[] = {1, 5, 3, 5, 11, 93, 2, 10};
    const unsigned int timesLen = sizeof(times) / sizeof(times[0]);
    // how can I define with size?
    std::cout << "timesLen: " << timesLen << std::endl;
    auto *encoding = new HuffmanEncoding[timesLen];
    for (int i = 0; i < timesLen; i++) {
        encoding[i] = HuffmanEncoding();
    }

    huffmanEncode((unsigned int *) times, timesLen, encoding);

    auto *pTimes = times;
    auto *pEncoding = encoding;
    // ok, now we need to see the encoding.
    for (int i = 0; i < timesLen; i++, pTimes++, pEncoding++) {
        std::cout << *pTimes << ", encoding: " << *pEncoding << std::endl;
    }
}