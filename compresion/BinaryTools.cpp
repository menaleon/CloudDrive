//
// Created by jose on 7/6/22.
//

#include "BinaryTools.hpp"


string BinaryTools::next_bin(string bin) {
    int k = bin.size() - 1;
    while(bin[k] == '1')
    {
        bin[k] = '0';
        k--;
    }
    if(k == -1)
        bin = "1" + bin;
    else
        bin[k] = '1';
    return bin;
}

int BinaryTools::bin_to_dec(string bin) {
    int dec = 0;
    int n = bin.size();
    int k = 1;
    for(int i = 0; i < n; i++)
    {
        if(bin[n-1-i] == '1')
            dec += k;
        k *= 2;
    }
    return dec;
}

string BinaryTools::dec_to_bin(int dec, int nb_bits) {
    string bin;
    while(dec != 0)
    {
        if(dec % 2 == 0)
        {
            bin = "0" + bin;
            dec /= 2;
        }
        else
        {
            bin = "1" + bin;
            dec = (dec - 1) / 2;
        }
    }

    if(nb_bits > 0 && bin.size() < nb_bits)
    {
        std::string fill(nb_bits - bin.size(), '0');
        return fill + bin;
    }
    return bin;
}




