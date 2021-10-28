//
// Created by huhua on 2021/10/29.
//

#include "../include/huffman_encoding.h"
#include <set>
#include <stdexcept>
#include <string>

// define the helper struct but put the operator in the end.

class Node {
public:
    int val;
    bool isData;
    Node *left;
    Node *right;

public:
    Node(int val, bool isData, Node *left, Node* right)
    : val(val), isData(isData), left(left), right(right) {};
};

void huffmanEncode(unsigned int *times, int len, HuffmanEncoding *output) {
    // ok, let's do the logic
    // How can we present the codes, and can delete from origin code?
    // A set is a good struct.

    std::set<unsigned int> datas;
    // how to think that you are not initialed??

    // it's good to let the negative as present to not initial?
    Node current(-1, false, nullptr, nullptr);

    // ok, wait for me to continue do this.
    // and should we write some test. first??
    // haha, I think so.
    for (int i = 0; i < len; i++) {
        if (datas.find(times[i]) != datas.end()) {
            throw std::invalid_argument("same data: " + std::to_string(times[i]));
        }
        // maybe the result value can be used to the check, but I don't care for now
        datas.insert(times[i]);

        // should we sort??

//        if (current.val == -1) {
//            // ok, current is not initialed.
//            current.left = Node();
//        }
    }
}
