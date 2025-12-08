#include "Search.hpp"
#include <string>
#include <algorithm>

//Building the dictionaries
void Search::build(const vector<term>& terms){
    englishMap.clear();
    koreanMap.clear();

    for (const auto& t : terms) {
        englishMap[t.english] = t;
        koreanMap[t.korean] = t;
    }
}

term* Search::englishSearch(const string& term){
    //Add in korean, look up english
    auto s = englishMap.find(term);
    if(s != englishMap.end()) return &s->second;
    return nullptr;
}

term* Search::koreanSearch(const string& term){
    //wstring w = wstring(term.begin(), term.end());
    auto s = koreanMap.find(term);
    if (s != koreanMap.end()) return &s->second;
    return nullptr;
}

vector<term*> Search::partialSearch(const string& term){
    res.clear();

    //Korean alphabets not getting read
    //wstring wterm(term.begin(), term.end());
    for(auto p : englishMap){
        if(p.first.find(term) != string::npos){
            res.push_back(&p.second);
        }
    }

    for(auto p : koreanMap){
        if(p.first.find(term) != string::npos){
            res.push_back(&p.second);
        }
    }

    return res;
}