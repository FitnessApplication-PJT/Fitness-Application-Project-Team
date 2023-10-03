#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;



int FindLocation(const vector<char> &vec, char x)
{
    auto it = find(vec.begin(), vec.end(), x);
    if (it != vec.end())
        return distance(vec.begin(), it);
    return -1;
}

bool IsChar123(char x)
{
    return find(Terminal.begin(), Terminal.end(), x) != Terminal.end();
}

string PrintStack(stack<char> x)
{
    string ans = ""; 
    while (!x.empty())
    {
        ans.push_back(x.top());
        x.pop();
    }
    reverse(ans.begin(), ans.end());

    return ans;
}
string printString(int c, string x)
{
    string ans = "";
    int n = x.size();
    for (int i = c; i < n; i++)
    {
        ans.push_back(x[i]);
    }
    return ans;
}

int main()
{
    cout << "Stack"
         << "\t"
         << "Input String"
         << "\tAction" << endl;

    stack<char> Data;
    Data.push('&');
    Data.push('S');
    string input = "acgfh";
    int sizeofInput = input.size();
    int counter = 0;

    while (true)
    {
        char NonT = Data.top();
        Data.pop();
        char Term = input[counter];

        string result1 = PrintStack(Data);
        string result2 = printString(counter, input);

        cout << result1 << "\t" << result2 << '\t';

        if (IsChar123(NonT))
        {
            if (NonT == Term)
            {
                cout << "match " << Term << endl;
                counter++;
                if (counter == sizeofInput)
                {
                    cout << "Accept the string" << endl;
                    break;
                }
            }
            else
            {
                cout << "Reject it" << endl;
            }
        }
        else
        {
            int loc1 = FindLocation(Nonterminal, NonT);
            int loc2 = FindLocation(Terminal, Term);

            if (loc1 == -1 || loc2 == -1)
            {
                cout << "Reject the string" << endl;
                break;
            }

            string x = parseTable[loc1][loc2];
            cout << x << endl;

            if (x == "#")
            {
                cout << "Reject the string" << endl;
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
