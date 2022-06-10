//
// Created by jose on 3/6/22.
//

#ifndef PROYECTO3_HUFFMAN_HPP
#define PROYECTO3_HUFFMAN_HPP
#include <bits/stdc++.h>
#include "string"
#include <bits/stdc++.h>
#define MAX_TREE_HT 256

using namespace std;

class huffman {
public:
    struct MinHeapNode {
        char data;             // One of the input characters
        int freq;             // Frequency of the character
        MinHeapNode *left, *right; // Left and right child

        MinHeapNode(char data, int freq) {
            left = right = NULL;
            this->data = data;
            this->freq = freq;
        }
    };

    struct compare {
        bool operator()(MinHeapNode *l, MinHeapNode *r) {
            return (l->freq > r->freq);
        }
    };
    void HuffmanCodes(int size);
    void calcFreq(string str, int n);
    string decode(string s);
    map<char, string> get_codes();
    void Character_Frequencies_and_codes();
    void create_three(char data[], int freq[], int size);

private:
    void storeCodes(struct MinHeapNode* root, string str);
    string decode_file(struct MinHeapNode* root, string s);
    map<char, string> codes;
    map<char, int> freq;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
};

#endif //PROYECTO3_HUFFMAN_HPP
