//
// Created by jose on 7/6/22.
//

#ifndef PROYECTO3_LZ77_HPP
#define PROYECTO3_LZ77_HPP
#include "BinaryTools.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;

class LZ77 {
public:
 string encode(string input);
 string decode(string input);
private:
    vector<string> split(string str, char delimiter);
};


#endif //PROYECTO3_LZ77_HPP
