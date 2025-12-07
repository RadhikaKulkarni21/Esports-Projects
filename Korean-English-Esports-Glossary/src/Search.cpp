#include "Search.hpp"
#include "Term.hpp"
#include <algorithm>

//Building the dictionaries
void Search::build(const vector<term>& terms){
    englishMap.clear();
    koreanMap.clear();

    for(auto t : terms){
        string en = t.english;
        string kr = t.korean;

        englishMap[en] = const_cast<term*>(&t);
        koreanMap[kr] = const_cast<term*>(&t);
    }
}

term* Search::englishSearch(const string& term){
    //Add in korean, look up english
    auto s = englishMap.find(term);
    if(s != englishMap.end()) return s->second;
    return nullptr;
}

term* Search::koreanSearch(const string& term){
    //Add in english, look up Korean
    auto s = koreanMap.find(term);
    if(s != koreanMap.end()) return s->second;
    return nullptr;
}

vector<term*> Search::partialSearch(const string& term){
    
    for(auto p : englishMap){
        if(p.first.find(term) != string::npos){
            res.push_back(p.second);
        }
    }

    for(auto p : koreanMap){
        if(p.first.find(term) != string::npos){
            res.push_back(p.second);
        }
    }

    return res;
}