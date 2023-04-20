#ifndef ENCODING_H
#define ENCODING_H

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

class Encoding {
    static const inline string key = "aaaaabbbbbabbbaabbababbaaababaab";
    static bool stringValidation(string &str);
    static string makeABstring(string &initialMessage);
    static char getAlphabetLetter(string &substring);
public:
    static string encode(string &word, string &text);
    static string decode(string &str);
};


#endif
