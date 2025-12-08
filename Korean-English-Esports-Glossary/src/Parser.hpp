#ifndef PARSER_HPP
#define PARSER_HPP

using namespace std;
#include "Term.hpp"
#include <string>
#include <vector>

class Parser{
    private:
    //split string into tokens for maps by |
    vector<string> split(string line, char delimiter);
    //remove white spaces
    string trim(const string& s);

    public:
    vector<term> loadFile(const string& path);
};

#endif