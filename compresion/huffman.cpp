//
// Created by jose on 3/6/22.
//

#include "huffman.hpp"
#include "string"
#include "iostream"
#include <bits/stdc++.h>

#include <utility>
#define MAX_TREE_HT 256

using namespace std;


void huffman::storeCodes(struct MinHeapNode *root, string str) {
    if (root==NULL)
        return;
    if (root->data != '$')
        codes[root->data]=str;
    storeCodes(root->left, str + "0");
    storeCodes(root->right, str + "1");
}

void huffman::HuffmanCodes(int size) {
    struct MinHeapNode *left, *right, *top;
    for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++)
        minHeap.push(new MinHeapNode(v->first, v->second));
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    storeCodes(minHeap.top(), "");
}

void huffman::calcFreq(string str, int n) {
    for (int i=0; i<str.size(); i++)
        freq[str[i]]++;
}

string huffman::decode_file(huffman::MinHeapNode *root, string s) {
    string ans = "";
    struct MinHeapNode* curr = root;
    for (int i=0;i<s.size();i++)
    {
        if (s[i] == '0')
            curr = curr->left;
        else
            curr = curr->right;

        // reached leaf node
        if (curr->left==NULL and curr->right==NULL)
        {
            ans += curr->data;
            curr = root;
        }
    }
    // cout<<ans<<endl;
    return ans+'\0';
}

map<char, string> huffman::get_codes() {
    return codes;
}

void huffman::Character_Frequencies_and_codes() {
    for (auto v=codes.begin(); v!=codes.end(); v++)
        cout << v->first <<' ' <<freq[v->first]<< ' '<< v->second << endl;
}

string huffman::decode(string s) {
    return decode_file(minHeap.top(),std::move(s));
}

void huffman::create_three(char data[], int freq[], int size) {
    minHeap.pop();
    struct MinHeapNode *left, *right, *top;
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {

        // Extract the two minimum
        // freq items from min heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with
        // frequency equal to the sum of the
        // two nodes frequencies. Make the
        // two extracted node as left and right children
        // of this new node. Add this node
        // to the min heap '$' is a special value
        // for internal nodes, not used
        top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }


}











