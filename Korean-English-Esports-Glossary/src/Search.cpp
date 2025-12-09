#include "Search.hpp"
#include <string>
#include <algorithm>

// Helper: convert English string to lowercase
wstring Search::to_lower(const wstring& s) {
    wstring out = s;
    transform(out.begin(), out.end(), out.begin(),
        [](wchar_t c){ return towlower(c); });
    return out;
}

//Building the dictionaries
void Search::build(const vector<term>& terms){
    englishMap.clear();
    koreanMap.clear();

    for (const auto& t : terms) {
        englishMap[to_lower(t.english)] = t;
        koreanMap[t.korean] = t;
    }
}

term* Search::englishSearch(const wstring& term){
    auto s = englishMap.find(term);
    if(s != englishMap.end()) return &s->second;
    return nullptr;
}

term* Search::koreanSearch(const wstring& term){
    auto s = koreanMap.find(term);
    if (s != koreanMap.end()) return &s->second;
    return nullptr;
}

//this will return all the matching terms present in the file
vector<term*> Search::partialSearch(const wstring& term){
    res.clear();//to remove previous storage

    wstring lowerTerm = to_lower(term);
    for(auto& p : englishMap){
        if(p.first.find(lowerTerm) != wstring::npos){
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