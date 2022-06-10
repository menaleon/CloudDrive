#include <iostream>
#include "huffman.hpp"
#include "string"
#include "LZ77.hpp"
#include "LZ78.hpp"

using namespace std;

int main() {
    huffman huffman;
    LZ77 lz77;
    LZ78 lz78;
    string mensaje="Paco compró copas. Como pocas copas compró, pocas copas pagó.";
    string code;
    huffman.calcFreq(mensaje,mensaje.length());
    huffman.HuffmanCodes(mensaje.length());
    huffman.Character_Frequencies_and_codes();
    map<char, string> codes=huffman.get_codes();
    for (auto i: mensaje)
        code+=codes[i];

    cout<<code<<endl;
    char arr[] = { 'e', 'f', 'g', 'k', 'o', 'r','s' };
    int freq[] = { 4,1 ,2 ,2 ,1 ,1,2  };
    int size = sizeof(arr) / sizeof(arr[0]);

    //huffman.create_three(arr,freq,size);
    //cout<<huffman.decode("01110100011111000101101011101000111")<<endl;
    //cout<<lz77.encode(mensaje)<<endl;
    //cout<<lz77.decode(lz77.encode(mensaje));
    return 0;
}
