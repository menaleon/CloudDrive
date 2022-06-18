//
// Created by jose on 17/6/22.
//

#include "manipulador.h"
#include <iostream>
#include "huffman.hpp"
#include "string"
#include "LZ77.hpp"
#include "LZ78.hpp"
#include "LZW.h"
#include <fstream>
#include <string>
#include "base64.h"

using namespace std;

string manipulador::leer(string archivo) {
    base64 base64;
    vector<BYTE> data;
    ifstream input(archivo, ios::in | ios::binary);
    string base64_string;
    if(input){
        input.seekg(0,input.end);
        int length = input.tellg();
        input.seekg(0,input.beg);
        char * buffer=new char [length];
        input.read(buffer,length);
        for (int j = 0; j < length; ++j) {
            data.push_back(buffer[j]);
        }
        base64_string=base64.base64_encode(&data[0],data.size());
    }
    return base64_string;
}

void manipulador::cargar(string encode, string archivo) {
    vector<BYTE> salida;
    base64 base64;
    ofstream output(archivo);
    salida=base64.base64_decode(encode);
    for (int j = 0; j < salida.size(); ++j) {
        output<<salida[j];
    }

}


