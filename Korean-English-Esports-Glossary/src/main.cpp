#include <iostream>
#include <windows.h>
#include <io.h>
#include <fcntl.h>

#include "Parser.hpp"
#include "Search.hpp"

//The conslole won't print Korean alphabets
wstring to_w(const string& utf8) {
    if (utf8.empty()) return L"";
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), (int)utf8.size(), nullptr, 0);
    wstring wstr(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), (int)utf8.size(), &wstr[0], size_needed);
    return wstr;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    _setmode(_fileno(stdout), _O_U8TEXT);

    std::wcout << L"한국어 <-> ENGLISH E-SPORTS TERMS HELPER\n";

    //Load the terms
    Parser parser;
    //TODO: Create the txt file with all LoL, Valorant terms
    auto terms = parser.loadFile("R:\\Esports Projects\\Esports-Projects\\Korean-English-Esports-Glossary\\Data\\Esports_gaming_terms.txt");

    wcout<< L"Loaded: " << terms.size() << L" terms" << endl;

    //Search index creation
    Search search;

    search.build(terms);
    wcout<< L"Type /help for commands"<<endl;

    string command;

    //The conslole won't print Korean alphabets
    //Helper to convert string to wstring
    // auto to_w = [](const std::string& s) {
    //     return std::wstring(s.begin(), s.end());
    // };

    while (true) {
        wcout << L"> ";
        getline(cin, command);

        if (command == "quit") {
            wcout << L"Exiting...\n";
            break;
        }

        if (command == "help") {
            wcout << L"Commands:\n";
            wcout << L" Menu - show this menu\n";
            wcout << L" Quit - exit program\n";
            wcout << L" Search <term> - find English or Korean term\n";
            continue;
        }

        if(command.rfind("Search", 0) == 0){
            string find;
            if (command.length() > 7)
                find = command.substr(7);
            else
                find = "";

            // trim leading/trailing whitespace
            find.erase(0, find.find_first_not_of(" \t\n\r"));
            find.erase(find.find_last_not_of(" \t\n\r") + 1);

            if (find.empty()) {
                wcout << L"Please enter a term after 'Search'\n";
                continue;
            }

            term* f = search.koreanSearch(find);
            if (!f) f = search.englishSearch(find);

            if (f) {
                std::wcout << to_w(f->english)
                           << L" → " << to_w(f->korean) << L"\n";
                continue;
            }

            auto results = search.partialSearch(find);
            if (!results.empty()) {
                wcout << results.size() << L" partial matches:\n";
                for (auto* f : results) {
                    wcout << L" - " << to_w(f->korean) << L" : " << to_w(f->english) << L"\n";
                }
            }

            else{
                wcout<< L"Not found"<<endl;
            }
            continue;
        }
        wcout << L"Unknown command. Type 'help'.\n";
    }
}
