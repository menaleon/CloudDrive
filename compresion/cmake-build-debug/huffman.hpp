//
// Created by jose on 3/6/22.
//

#ifndef PROYECTO3_HUFFMAN_HPP
#define PROYECTO3_HUFFMAN_HPP
#include <bits/stdc++.h>
#include "string"

using namespace std;

class huffman {
public:
    void HuffmanCodes(char data[], int freq[], int size);


private:
    struct MinHeapNode {

        // One of the input characters
        char data;

        // Frequency of the character
        unsigned freq;

        // Left and right child
        MinHeapNode *left, *right;

        MinHeapNode(char data, unsigned freq)

        {

            left = right = NULL;
            this->data = data;
            this->freq = freq;
        }
    };

    struct compare {

        bool operator()(MinHeapNode* l, MinHeapNode* r)

        {
            return (l->freq > r->freq);
        }
    };

    void printCodes(struct MinHeapNode* root, string str);
};


#endif //PROYECTO3_HUFFMAN_HPP
