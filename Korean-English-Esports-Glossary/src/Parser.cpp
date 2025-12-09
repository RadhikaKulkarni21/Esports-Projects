#include <sstream>
#include <fstream>
#include <iostream>
#include <locale>
#include <codecvt>
#include <windows.h>
#include "Parser.hpp"

//Convert wstring to string encoded in UTF-8 - Stack Overflow https://share.google/BSKDg2ViSGltDG5p3 
string wstring_to_utf8(const wstring& w) {
    if (w.empty()) return {};
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, w.c_str(), (int)w.size(),
                                          nullptr, 0, nullptr, nullptr);
    string out(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, w.c_str(), (int)w.size(),
                        &out[0], size_needed, nullptr, nullptr);
    return out;
}

vector<term> Parser::loadFile(const wstring& path){
    vector<term> terms;

    string utf8_path = wstring_to_utf8(path);

    wifstream file(utf8_path);
    file.imbue(locale(file.getloc(), new codecvt_utf8_utf16<wchar_t>));
    if(!file.is_open()){
        wcerr<< L"File failed to open: " << path << endl;
        return terms;
    }

    wstring line;

    int lineNumber = 0;
    
    while(getline(file, line)){
        lineNumber++;

        //Skipping empty lines or irrelevant lines
        if(line.empty() || line[0] == L'#') continue;

        auto tokens = split(line, L'|');

        //making sure 4 values are present at any given moment
        if(tokens.size() < 4){
            wcerr << L"Invalid entry" << lineNumber << L", expected 4+ lines " << line << endl;
            continue;
        }

        term t;
        t.english = trim(tokens[0]);

        t.korean= trim(tokens[1]);

        t.category = trim(tokens[2]);
        t.defination = trim(tokens[3]);
        //since we are keeping notes optional, so they or may not be present in the file with terms
        t.notes = (tokens.size() >= 5 ? trim(tokens[4]):L"");

        /*parsing and storing
        format would be
        "English"| "Korean" | "Category" | "Definations" | "Note(OP)" |
        Example
        team fight | 한타 | Game Event | A fight involving multiple players from each team | Commonly used in League of Legends |*/
        
        terms.push_back(t);
    }
    return terms;
}

vector<wstring> Parser::split(wstring line, wchar_t delimiter) {
    vector<wstring> tokens;
    wstringstream ss(line);
    wstring item;

    while (getline(ss, item, delimiter)) {
        tokens.push_back(item);
    }//this should return "This", "is", "a","Token"

    return tokens;
}

wstring Parser::trim(const wstring& s){
    const wstring whitespace = L"\t\n\r ";
    size_t start = s.find_first_not_of(whitespace);
    if(start == string::npos)return L"";
    size_t end = s.find_last_not_of(whitespace);

    if (start == wstring::npos) return L"";
    return s.substr(start, end - start + 1);
}