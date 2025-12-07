#pragma once
using namespace std;
#include <unordered_map>
#include <vector>
#include "Term.hpp"

class Search{
    public:
    unordered_map<string, term*> englishMap;//store english
    unordered_map<string, term*> koreanMap;//store Korean
    vector<term*> res;

    void build (const vector<term>& terms);
    
    //Lookup 한국어 <=> English
    term* englishSearch(const string& term);
    term* koreanSearch(const string& term);

    vector<term*> partialSearch(const string& term);
};