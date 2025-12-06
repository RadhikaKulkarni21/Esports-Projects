#include <iostream>
#include <string>
using namespace std;

int main(){
    cout<< "KOREAN <-> ENGLISH E-SPORTS TERMS DICTIONARY" << endl;
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
            cout << "  help - show this menu\n";
            cout << "  quit - exit program\n";
        }
        else {
            cout << "Unknown command. Type 'help'.\n";
        }
    }
}
