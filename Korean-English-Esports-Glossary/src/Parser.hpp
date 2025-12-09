#ifndef PARSER_HPP
#define PARSER_HPP

using namespace std;
#include "Term.hpp"
#include <string>
#include <vector>

class Parser{
    private:
    //split string into tokens for maps by |
    vector<wstring> split(wstring line, wchar_t delimiter);
    //remove white spaces
    wstring trim(const wstring& s);

    public:
    vector<term> loadFile(const wstring& path);
};

#endif