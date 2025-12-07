using namespace std;
#include <iostream>
#include "Parser.hpp"
#include "Search.hpp"

int main(){
    cout<< "KOREAN <-> ENGLISH E-SPORTS TERMS HELPER" << endl;
    //Load the terms
    Parser parser;
    //TODO: Create the txt file with all LoL, Valorant terms
    auto terms = parser.loadFile("R:/Esports Projects/Esports-Projects/Korean-English-Esports-Glossary/Data/Esports_gaming_terms.txt");

    cout<< "Loaded: " << terms.size() << " terms" << endl;

    //Search index creation
    Search search;

    search.build(terms);
    cout<< "Type /help for commands"<<endl;

    string command;

    while (true) {
        cout << "> ";
        getline(cin, command);

        if (command == "quit") {
            cout << "Exiting...\n";
            break;
        }

        else if (command == "help") {
            cout << "Commands:\n";
            cout << " Menu - show this menu\n";
            cout << " Quit - exit program\n";
            cout << " Search <term> - find English or Korean term\n";
        }

        else if(command.rfind("Search", 0) == 0){
            string find = command.substr(7);

            if (auto* f = search.englishSearch(find)){
                cout<< "[EN]" << f->english << " -> [KR]" << f->korean << endl;
                continue;
            }

            if (auto* f = search.koreanSearch(find)){
                cout<< "[KR]" << f->korean << " -> [EN]" << f->english << endl;
                continue;
            }

            auto results = search.partialSearch(find);
            if (!results.empty()) {
                std::cout << results.size() << " partial matches:\n";
                for (auto* f : results) {
                    std::cout << " - " << f->korean << " : " << f->english << "\n";
                }
            }

            else{
                cout<<"Not found"<<endl;
            }
        }
        else {
            cout << "Unknown command. Type 'help'.\n";
        }
    }
}
