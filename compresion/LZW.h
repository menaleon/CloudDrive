//
// Created by jose on 17/6/22.
//

#ifndef PROYECTO3_LZW_H
#define PROYECTO3_LZW_H
#include "vector"
#include "string"

using namespace std;

class LZW {
public:
    vector<int> encoding(string s1);
    string decoding(vector<int> op);
    void save(string archivo, vector<int> op);
    string decode(string archivo);
};


#endif //PROYECTO3_LZW_H
