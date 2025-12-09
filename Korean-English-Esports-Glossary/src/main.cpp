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
    SetConsoleCP(CP_UTF8);
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    std::wcout << L"한국어 <-> ENGLISH E-SPORTS TERMS HELPER\n";

    //Load the terms
    Parser parser;
    
    auto terms = parser.loadFile(L"R:\\Esports Projects\\Esports-Projects\\Korean-English-Esports-Glossary\\Data\\Esports_gaming_terms.txt");

    wcout<< L"Loaded: " << terms.size() << L" terms" << endl;

    //Search index creation
    Search search;

    search.build(terms);
    wcout<< L"Type /help for commands"<<endl;

    wstring command;

    while (true) {
        wcout << L"> ";
        getline(wcin, command);

        command.erase(0, command.find_first_not_of(L" \t\n\r"));
        command.erase(command.find_last_not_of(L" \t\n\r") + 1);

        if (command.empty()) continue;

        if (command == L"quit") {
            wcout << L"Exiting...\n";
            break;
        }

        if (command == L"help") {
            wcout << L"Commands:\n";
            wcout << L" Menu - show this menu\n";
            wcout << L" Quit - exit program\n";
            wcout << L" Search <term> - find English or Korean term\n";
            continue;
        }

        if(command.rfind(L"Search", 0) == 0){
            wstring query = command.substr(7);

            query.erase(0, query.find_first_not_of(L" \t\n\r"));
            query.erase(query.find_last_not_of(L" \t\n\r") + 1);

            if (query.empty()) {
                wcout << L"Please enter a term after 'Search'\n";
            continue;
        }

            term* f = search.englishSearch(query);
            if (!f) f = search.koreanSearch(query);

            if (f) {
                std::wcout << wstring(f->english.begin(), f->english.end()) << L" -> "
                           << wstring(f->korean.begin(), f->korean.end()) 
                           << L"\n";
                continue;
            }

            auto results = search.partialSearch(query);
             if (!results.empty()) {
                wcout << results.size() << L" partial matches:\n";
                for (auto* f : results) {
                    wcout << f->korean << L" : " << f->english << L"\n";
                }
            }
            else{
                wcout<< L"Not found"<<endl;
            }
            continue;
        }
        else{
            wcout << L"Unknown command. Type 'help'.\n";
        }
    }
}
