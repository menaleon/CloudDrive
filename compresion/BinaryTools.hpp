//
// Created by jose on 7/6/22.
//

#ifndef PROYECTO3_BINARYTOOLS_HPP
#define PROYECTO3_BINARYTOOLS_HPP
#include <string>

using namespace std;

class BinaryTools {
public:
    string next_bin(string bin);
    int bin_to_dec(string bin);
    string dec_to_bin(int dec, int nb_bits=-1);

};


#endif //PROYECTO3_BINARYTOOLS_HPP
