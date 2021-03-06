//
// Created by jose on 7/6/22.
//

#include "LZ77.hpp"
#include <string>
#include "iostream"
#include <sstream>
#include "vector"


string LZ77::encode(string input) {
    string result;
    int length, char_info_selc = 0;
    check_char:
    length = (int) input.length();    // Calculate input string length
    if (length <= 2) {
        cout << "enter at leaset 3 characters \n";
        getline(cin, input);        // Read input string
        goto check_char;
    }

    int **result_ary = new int *[3];
    for (int i = 0; i < length; ++i)
        result_ary[i] = new int[length];
    // Set result_ary elements value to 0 to prevent previous values
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < length; j++)
            result_ary[i][j] = 0;
    }

    int **char_info = new int *[3];
    for (int i = 0; i < length; ++i)
        char_info[i] = new int[length];
    // Set char_info elements value to 0 to prevent previous values
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < length; j++)
            char_info[i][j] = 0;
    }

    // Set first char info to (0,0,'<first char>')
    result_ary[0][0] = 0;
    result_ary[1][0] = 0;
    result_ary[2][0] = input[0];

    // Set result counter
    int result_count = 1;

    // A loop to perform some operations in every char in input string
    for (int i = 1; i < length; i++) {
        // A loop to check input char in position i is equal to any of
        // previous char in input and save this info in char_info array
        for (int j = 0; j < i; j++) {
            // Check position of previous view of element i
            if (input[i] == input[j]) {
                // Set position pointer
                char_info[0][char_info_selc] = i - j;

                // Increase char info array selector by 1
                char_info_selc++;
            }

        }

        // A loop to check length for every char position
        for (int j = 0; j < length; j++) {
            // Check current char info array position is not equal to 0
            if (char_info[0][j] != 0) {
                // Set start point
                int start = i - char_info[0][j];

                // Set count to calculate length for this char position
                int count = 1;

                // A loop to check length for this char position
                for (int k = 0; k < length; k++) {
                    // Check next element of start by next element of input
                    if (input[start + count] == input[i + count])
                        count++;    // Increase count by 1
                    else {
                        char_info[1][j] = count;    // Store count value in length

                        // Check if this input char is the last char
                        if (i != (length - 1)) {
                            // Store next char to char info
                            // Check this postion is equal to length
                            if (char_info[0][j] + count == length)
                                char_info[2][j] = 0;    // Set 0 in next char field
                            else
                                char_info[2][j] = input[char_info[0][j] + count];    // Set the next char
                        } else
                            char_info[2][j] = NULL;        // Set NULL in next char field

                        break;    // Stop loop
                    }
                }
            }
        }
        // Set large selector
        int large = 0;	// large selector equal 0

        // Loop to check the largest length for every char info
        for (int k = 1; k < length; k++)
        {
            // Check largest
            if (char_info[1][large] == char_info[1][k])
                large = k;	// Set largest
            else if (char_info[1][large] < char_info[1][k])
                large = k;	// Set largest
        }

        // Check largest length is equal to 0
        if (char_info[1][large] == 0)
            char_info[2][large] = input[i];		// Set char info
        else
        {
            i += char_info[1][large];		// increase loop counter by length of the largest char info element
            char_info[2][large] = input[i];		// Set char info
        }

        // Set final result info
        result_ary[0][result_count] = char_info[0][large];
        result_ary[1][result_count] = char_info[1][large];
        result_ary[2][result_count] = char_info[2][large];

        // Increase result counter
        result_count++;

        // Prepare char info array for next char by set it to 0
        for (int z = 0; z < 2; z++)
        {
            for (int j = 0; j < length; j++)
                char_info[z][j] = 0;	// Set every element in char info to 0
        }

        // Prepare char info selector for next char by set it to 0
        char_info_selc = 0;
    }

    // Display final results
    for (int j = 0; j < length; j++)
    {
        if (result_ary[0][j] == 0 && result_ary[1][j] == 0)
        {
            if (result_ary[2][j] != NULL || result_ary[2][j] != 0)
            {
                char z = result_ary[2][j];
                result += to_string(result_ary[0][j]) + "|" + to_string(result_ary[1][j]) + "|" + z + ";";
            }
        }
        else
        {
            char z = result_ary[2][j];
            result += to_string(result_ary[0][j]) + "|" + to_string(result_ary[1][j]) + "|" + z + ";";
        }
    }

    // Clean up memory
    //for (int i = 0; i < 3; ++i) {
    //	{
    //		delete[] result_ary[i];	delete[] char_info[i];
    //	}
    //}
    delete result_ary;
    delete char_info;

    return result;


    }

string LZ77::decode(string input) {
    vector<string> s_input = split(input, ';');
    string result;
    for (int i = 0; i < s_input.size(); ++i)
    {
        vector<string> ss_input = split(s_input[i], '|');

        int p = stoi(ss_input[0]),
                l = stoi(ss_input[1]);
        string ch;
        if (ss_input[2][0] == '0')
            ch = '0';
        else
            ch = ss_input[2];

        if (p != 0)
        {
            int result_len = (int)result.length();
            for (int x = 0; x < l; x++)
                result += result[result_len - p + x];
        }

        if (ch[0] != '0' || ch[0] != NULL)
            result += ch;
    }
    return result;
}

vector<string> LZ77::split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;

    while (getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }

    return internal;
}

