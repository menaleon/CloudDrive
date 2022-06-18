//
// Created by jose on 16/6/22.
//

#ifndef PROYECTO3_BASE64_H
#define PROYECTO3_BASE64_H
#include <vector>
#include <string>
typedef unsigned char BYTE;
using namespace std;

class base64 {
public:
    string base64_encode(BYTE const* buf, unsigned int bufLen);
    vector<BYTE> base64_decode(std::string const&);

private:

};


#endif //PROYECTO3_BASE64_H
