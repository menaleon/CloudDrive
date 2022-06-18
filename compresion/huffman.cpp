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
        cout << v->first <<' ' <<freq[v->first]<< endl;
}

string huffman::encode(string mensaje,string archivo) {
    calcFreq(mensaje,mensaje.length());
    HuffmanCodes(mensaje.length());
    ofstream output(archivo);
    string code;
    for (auto v=codes.begin(); v!=codes.end(); v++)
        output << v->first <<' ' <<freq[v->first]<< endl;
    map<char,string> codes=get_codes();
    for(auto i:mensaje){
        code+=codes[i];
    }
    return code;
}




string huffman::decode(string s) {
    return decode_file(minHeap.top(),std::move(s));
}

void huffman::create_tree(char data[], int freq[], int size){
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

string huffman::descomprimir(string archivo,string huffcode) {
    ifstream input(archivo);
    char letra;
    int frecuencia;
    string mensaje="iniciar huffman";
    calcFreq(mensaje,mensaje.length());
    HuffmanCodes(mensaje.length());
    vector <char> arr1;
    vector <int> freq1;
    int size1 = arr1.size();
    do {
        input>>letra>>frecuencia;
        arr1.push_back(letra);
        freq1.push_back(frecuencia);
    } while(input);

    char arr[arr1.size()-1];
    int freq[freq1.size()-1];
    for (int i = 0; i < arr1.size()-1; ++i) {
        arr[i]=arr1[i];
        freq[i]=freq1[i];
    }
    int size = sizeof(arr) / sizeof(arr[0]);
    create_tree(arr,freq,size);
    return decode(std::move(huffcode));


}











