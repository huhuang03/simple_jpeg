//
// Created by huhua on 2021/10/29.
//

#include "../include/huffman_encoding.h"
#include <set>
#include <stdexcept>
#include <string>
#include <iostream>

// define the helper struct but put the operator in the end.

class Node {
public:
    unsigned int val;
    // < 0 means the fake node.
    int index;
    Node *left;
    Node *right;

public:
    Node(int val, int index = -1, Node *left = nullptr, Node* = nullptr)
    : val(val), index(index), left(left), right(right) {};
};

void huffmanEncode(unsigned int *times, int len, HuffmanEncoding *output, HuffmanStartsWith startsWith) {
    // ok, let's do the logic
    // How can we present the codes, and can delete from origin code?
    // A set is a good struct.

    std::vector<Node> nodes;
    unsigned int *pItems = times;
    for (int i = 0; i < len; i++, pItems++) {
        // push and (pop and assign) is ok, but we can't present the tree in stack.
        // we need a map, but we need free the tree when we done.
        // Ok, I don't know emplace_back for now.
        // If we don't new, will be deleted by the pop?
        nodes.emplace_back(*pItems, i);
    }

    Node *root = nullptr;

    while (nodes.size() > 2) {
        auto min1 = std::begin(nodes);
        auto min2 = min1 + 1;
        for (auto it = std::begin(nodes); it != std::end(nodes); it++) {
            auto out = it;
            if (min1->val > it->val) {
                min1 = it;
                out = min1;
            }

            if (out != min1 && out->val < min2->val) {
                min2 = out;
            }
        }

        std::cout << "min1: " << min1->val << ", min2: " << min2->val << std::endl;
        nodes.erase(min1);
//
//        if (root == nullptr) {
//            root = new Node(min->val, std::find(nodes.begin(), nodes.end(), min) - nodes.begin());
//        } else {
//            // create the new root.
//        }
    }
}

// f**, what we can do?
std::ostream &operator<<(std::ostream &os, const HuffmanEncoding &huffmanEncoding) {
    for (unsigned char i : huffmanEncoding.value) {
        os << i;
    }
    return os;
}
