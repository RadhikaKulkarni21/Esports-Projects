#include <sstream>
#include <fstream>
#include <iostream>
#include <locale>
#include <codecvt>
#include <windows.h>
#include "Parser.hpp"

wstring utf8_to_wstring(const string& utf8) {
    if (utf8.empty()) return L"";
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), (int)utf8.length(), NULL, 0);
    wstring wstr(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), (int)utf8.length(), &wstr[0], size_needed);
    return wstr;
}

vector<term> Parser::loadFile(const string& path){
    vector<term> terms;

    ifstream file(path, ios::binary);
    if(!file.is_open()){
        cerr<< "File failed to open: " << path << endl;
        return terms;
    }

    string line;

    int lineNumber = 0;
    
    while(getline(file, line)){
        lineNumber++;

        //Skipping empty lines or irrelevant lines
        if(line.empty() || line[0] == '#') continue;

        auto tokens = split(line, '|');

        //making sure 4 values are present at any given moment
        if(tokens.size() < 4){
            cerr << "Invalid entry" << lineNumber << ", expected 4+ lines " << line << endl;
            continue;
        }

        term t;
        t.english = trim(tokens[0]);

        t.korean= trim(tokens[1]);

        t.category = trim(tokens[2]);
        t.defination = trim(tokens[3]);
        //since we are keeping notes optional, so they or may not be present in the file with terms
        t.notes = (tokens.size() >= 5 ? trim(tokens[4]):"");

        //parsing and storing
        //format would be
        //"English" "Korean" "Category" "Definations" "Note(OP)"
        terms.push_back(t);
    }
    return terms;
}

vector<string> Parser::split(string line, char delimiter){
    vector<string> tokens;
    stringstream ss(line);
    string item;

    while(getline(ss, item, delimiter)){
        tokens.push_back(item);
    }//this should return "This", "is", "a","Token"

    return tokens;
} 

string Parser::trim(const string& s){
    static const char* whitespace = "\t\n\r ";
    size_t start = s.find_first_not_of(whitespace);
    if(start == string::npos)return "";
    size_t end = s.find_last_not_of(whitespace);

    return s.substr(start, end - start + 1);
}