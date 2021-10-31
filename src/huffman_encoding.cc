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

static void encode(std::vector<unsigned char> level, HuffmanEncoding *output, Node* tree) {
    if (tree == nullptr) return;
    if (tree->index > 0) {
        // why throw at here?
        std::cout << "size: " << (output + tree->index)->value.size() << std::endl;
        (output + tree->index)->value.push_back(0);
//        for (auto it = level.begin(); it != level.end(); it++) {
//            (output + tree->index)->value.push_back(*it);
//        }
//        (output + tree->index)->value.insert((output + tree->index)->value.end(), level.begin(), level.end());
    } else {
        std::vector<unsigned char> leftLevel = level;
        leftLevel.push_back(0);
        encode(leftLevel, output, tree->left);

        std::vector<unsigned char> rightLevel = level;
        rightLevel.push_back(0);
        encode(rightLevel, output, tree->right);
    }
}

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

    // TODO how to struct the node?
    // we need care about the release.
    Node *root = nullptr;

    while (nodes.size() > 2) {
        auto min1 = std::begin(nodes);
        for (auto it = std::begin(nodes); it != std::end(nodes); it++) {
            if (min1->val > it->val) {
                min1 = it;
            }
        }

        Node* nodeLeft = new Node(min1->val, min1->index, min1->left, min1->right);
        nodes.erase(min1);


        auto min2 = std::begin(nodes);
        for (auto it = std::begin(nodes); it != std::end(nodes); it++) {
            if (min2->val > it->val) {
                min2 = it;
            }
        }

        Node* nodeRight = new Node(min2->val, min2->index, min2->left, min2->right);
        nodes.erase(min2);

        std::cout << "min1: " << nodeLeft->val << ", min2: " << nodeRight->val << std::endl;


        // looks we can't erase after change the nodes.

        // ok, how to do next?
        // how to do the min1, and min2?
        // For now, I discard the free issue, can I do it?
        Node* newRoot = new Node(nodeLeft->val + nodeRight->val, -1, nodeLeft, nodeRight);
        nodes.push_back(*newRoot);
        root = newRoot;
    }
    std::cout << "root: " << root->val << std::endl;
    // ok, now we encode.
    encode(std::vector<unsigned char>(), output, root);
}

// f**, what we can do?
std::ostream &operator<<(std::ostream &os, const HuffmanEncoding &huffmanEncoding) {
    for (unsigned char i : huffmanEncoding.value) {
        os << i;
    }
    return os;
}
