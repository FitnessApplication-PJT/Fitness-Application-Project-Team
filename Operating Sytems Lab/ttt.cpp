Lexical Analysis 


#include <iostream>
#include <string>
#include <ctype.h>
#include<set>
using namespace std;

int main() {
    int ic = 0, m, cc = 0, oc = 0;
    string b, operators, constants;
     set<string> printed_identifiers;


    cout << "Enter the string: ";
    getline(cin, b);

    for (int i = 0; i < b.length(); i++) {
        if (isspace(b[i])) {
            continue;
        }
        else if (isalpha(b[i])) {
            string identifier = "";
            while (isalpha(b[i]) || isdigit(b[i])) {
                identifier += b[i++];
            }

            if (identifier == "while" || identifier == "for" || 
                identifier == "int" || identifier == "void" ||
                identifier == "main" || identifier == "if") {
                // it's a keyword
                cout << identifier << " is a keyword\n";
            } else {
                // it's an identifier
                cout << identifier << " is an identifier\n";
            }
            i--;
        }
        else if (isdigit(b[i])) {
            m = (b[i] - '0');
            i = i + 1;
            while (isdigit(b[i])) {
                m = m * 10 + (b[i] - '0');
                i++;
            }
            i = i - 1;
            constants += to_string(m) + " ";
        }
        else {
            if (b[i] == '*') {
                operators += "* ";
            }
            else if (b[i] == '-') {
                operators += "- ";
            }
            else if (b[i] == '+') {
                operators += "+ ";
            }
            else if (b[i] == '=') {
                operators += "= ";
            }
        }
    }

    // printing
    cout << "identifiers : " << endl;
    cout << "constants : " << constants << endl;
    cout << "operators : " << operators << endl;

    return 0;
}
