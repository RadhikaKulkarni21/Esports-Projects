#pragma once
#include <unordered_map>
#include <vector>
#include "Term.hpp"

class Search{
    public:
    unordered_map<wstring, term> englishMap;//store english
    unordered_map<wstring, term> koreanMap;//store Korean
    vector<term*> res;

    void build (const vector<term>& terms);
    
    //Lookup 한국어 <=> English
    term* englishSearch(const wstring& term);
    term* koreanSearch(const wstring& term);

    vector<term*> partialSearch(const wstring& term);
};