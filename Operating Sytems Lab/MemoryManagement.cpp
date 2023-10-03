#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

vector<char> NonTerminal = {'S', 'A', 'D', 'E', 'B', 'C'};
vector<char> Terminals = {'a', 'b', 'd', 'e', 'f', 'h', 'i', '$'};
vector<vector<string>> parsetable = {
    {"aAC", "bB", "#", "#", "#", "#", "#", "#"},
    {"#", "#", "#", "eD", "#", "#", "#", "#"},
    {"#", "bE", "#", "#", "#", "&", "&", "#"},
    {"#", "#", "dD", "eD", "#", "#", "#"},
    {"#", "#", "#", "#", "f", "g", "#", "#", "#"},
    {"#", "#", "#", "#", "#", "h", "i", "#"}};

bool IsChar123(char x)
{
    for (int i = 0; i < Terminals.size(); i++)
    {
        if (Terminals[i] == x)
        {
            return true;
        }
    }
    return false;
}

int FindLocation(vector<char> heelo, char b)
{
    for (int i = 0; i < heelo.size(); i++)
    {
        if (heelo[i] == b)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    stack<char> Data;
    Data.push('$');
    Data.push('S');
    string input = "aebdh";
    int size = input.size();
    int counter = 0;
    while (true)
    {
        char NonT = Data.top();
        Data.pop();
        char Term = input[counter];

        cout << NonT << "  " << Term << endl;
        if (IsChar123(NonT))
        {

            if (NonT == Term)
            {
                printf("Match\n");
                counter++;
            }
            else
            {
                printf("Reject the string\n");
                break;
            }
            if (counter == input.size())
            {
                cout << "Accepted" << endl;
                break;
            }
        }
        else
        {

            int loc1 = FindLocation(NonTerminal, NonT);
            int loc2 = FindLocation(Terminals, Term);

            if (loc1 == -1 || loc2 == -1)
            {
                printf("Rejected string\n");
                break;
            }
            string x = parsetable[loc1][loc2];
            if (x == "#")
            {
                cout << "Rejected string\n"
                     << endl;
                break;
            }
            else if (x == "&")
            {
                continue;
            }
            else
            {
                for (int i = x.size() - 1; i >= 0; i--)
                {
                    Data.push(x[i]);
                }
            }
        }
    }

    return 0;
}
