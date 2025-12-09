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

term* Search::englishSearch(const wstring& term){
    //Add in korean, look up english
    auto s = englishMap.find(term);
    if(s != englishMap.end()) return &s->second;
    return nullptr;
}

term* Search::koreanSearch(const wstring& term){
    auto s = koreanMap.find(term);
    if (s != koreanMap.end()) return &s->second;
    return nullptr;
}

vector<term*> Search::partialSearch(const wstring& term){
    res.clear();//to remove previous storage

    for(auto& p : englishMap){
        if(p.first.find(term) != wstring::npos){
            res.push_back(&p.second);
        }
    }

    for(auto& p : koreanMap){
        if(p.first.find(term) != wstring::npos){
            res.push_back(&p.second);
        }
    }

    return res;
}