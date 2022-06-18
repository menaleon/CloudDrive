//
// Created by jose on 17/6/22.
//

#include <fstream>
#include "LZW.h"
#include "iostream"
#include "unordered_map"

vector<int> LZW::encoding(string s1)
{

    unordered_map<string, int> table;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);
        table[ch] = i;
    }

    string p = "", c = "";
    p += s1[0];
    int code = 256;
    vector<int> output_code;
    for (int i = 0; i < s1.length(); i++) {
        if (i != s1.length() - 1)
            c += s1[i + 1];
        if (table.find(p + c) != table.end()) {
            p = p + c;
        }
        else {
            output_code.push_back(table[p]);
            table[p + c] = code;
            code++;
            p = c;
        }
        c = "";
    }
    output_code.push_back(table[p]);
    return output_code;
}

string LZW::decoding(vector<int> op)
{
    string result;
    unordered_map<int, string> table;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);
        table[i] = ch;
    }
    int old = op[0], n;
    string s = table[old];
    string c = "";
    c += s[0];
    result+=s;
    //cout << s;
    int count = 256;
    for (int i = 0; i < op.size() - 1; i++) {
        n = op[i + 1];
        if (table.find(n) == table.end()) {
            s = table[old];
            s = s + c;
        }
        else {
            s = table[n];
        }
        result+=s;
        //cout << s;
        c = "";
        c += s[0];
        table[count] = table[old] + c;
        count++;
        old = n;
    }
    return result;
}

void LZW::save(string archivo,vector<int> op) {
    vector<int> output_code = op;
    ofstream output(archivo);
    for (int i = 0; i < output_code.size(); i++) {
        output << output_code[i] << " ";
    }
}

string LZW::decode(string archivo) {
    ifstream input(archivo);
    vector<int> output_code;
    int x;
    do{
        input>>x;
        output_code.push_back(x);

    } while (input);
    output_code.pop_back();
    return decoding(output_code);
}


