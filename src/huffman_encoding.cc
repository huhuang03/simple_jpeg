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
    Node(int val, int index = -1, Node *left = nullptr, Node* right = nullptr)
    : val(val), index(index), left(left), right(right) {};

    void freeEntireTree() {
        if (this->left != nullptr) {
            this->left->freeEntireTree();
        }
        if (this->right != nullptr) {
            this->right->freeEntireTree();
        }
        delete this;
    }
};

static void encode(std::vector<unsigned char> level, HuffmanEncoding *output, Node* tree) {
    if (tree == nullptr) return;
    if (tree->index >= 0) {
        for (unsigned char & it : level) {
            (output + tree->index)->value.push_back(it);
        }
    } else {
        std::vector<unsigned char> leftLevel = level;
        leftLevel.push_back(0);
        encode(leftLevel, output, tree->left);

        std::vector<unsigned char> rightLevel = level;
        rightLevel.push_back(1);
        encode(rightLevel, output, tree->right);
    }
}

void huffmanEncode(unsigned int *times, int len, HuffmanEncoding *output, HuffmanStartsWith startsWith) {
    // ok, let's do the logic
    // How can we present the codes, and can delete from origin code?
    // A set is a good struct.

    std::vector<Node*> nodes;
    unsigned int *pItems = times;
    for (int i = 0; i < len; i++, pItems++) {
        nodes.push_back(new Node(*pItems, i));
    }

    Node *root = nullptr;

    while (nodes.size() > 1) {
        auto min1 = std::begin(nodes);
        for (auto it = std::begin(nodes); it != std::end(nodes); it++) {
            if ((*min1)->val > (*it)->val) {
                min1 = it;
            }
        }

        Node* nodeLeft = *min1;
        nodes.erase(min1);


        auto min2 = std::begin(nodes);
        for (auto it = std::begin(nodes); it != std::end(nodes); it++) {
            if ((*min2)->val > (*it)->val) {
                min2 = it;
            }
        }

        Node* nodeRight = *min2;
        nodes.erase(min2);

        Node* newRoot = new Node(nodeLeft->val + nodeRight->val, -1, nodeLeft, nodeRight);
        nodes.push_back(newRoot);
        root = newRoot;
    }
    encode(std::vector<unsigned char>(), output, root);
    root->freeEntireTree();
}

// f**, what we can do?
std::ostream &operator<<(std::ostream &os, const HuffmanEncoding &huffmanEncoding) {
    std::cout << "len: " << huffmanEncoding.value.size() << ", ";
    for (unsigned char i : huffmanEncoding.value) {
        os << (int)i;
    }
    return os;
}
