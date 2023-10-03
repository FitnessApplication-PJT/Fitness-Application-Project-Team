#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int calc(int n1, int n2, std::string op)
{
    if (op == "+")
    {
        return n1 + n2;
    }
    else if (op == "-")
    {
        return n1 - n2;
    }
    else if (op == "*")
    {
        return n1 * n2;
    }
    else if (op == "/")
    {
        return n1 / n2;
    }
    else
    {
        return -1;
    }
}

int main()
{
    std::vector<std::vector<std::string>> vs;
    int u;
    std::cin >> u;
    std::cin.ignore();

    for (int i = 0; i < u; i++)
    {
        std::string S, T;
        std::getline(std::cin, S);
        std::stringstream X(S);
        std::vector<std::string> v1;
        while (std::getline(X, T, ' '))
        {
            v1.push_back(T);
        }
        vs.push_back(v1);
    }

    std::vector<int> buff(u, -1);
    int i = 0;

    for (auto &v : vs)
    {
        if (std::isdigit(v[1][0]))
        {
            int n = std::stoi(v[1]);
            if (buff[n] != -1)
            {
                v[1] = "#" + std::to_string(buff[n]);
            }
        }
        if (std::isdigit(v[2][0]))
        {
            int n = std::stoi(v[2]);
            if (buff[n] != -1)
            {
                v[2] = "#" + std::to_string(buff[n]);
            }
        }
        if ((v[1].rfind("#", 0) == 0) && (v[2].rfind("#", 0) == 0))
        {
            v[1].erase(v[1].begin());
            v[2].erase(v[2].begin());
            buff[i] = calc(std::stoi(v[1]), std::stoi(v[2]), v[3]);
            std::cout << buff[i] << std::endl;
        }
        i++;
    }

    std::vector<std::vector<std::string>> cp;

    for (int i = 0; i < u; i++)
    {
        if (buff[i] == -1)
        {
            cp.push_back(vs[i]);
        }
    }

    for (auto v : cp)
    {
        for (auto v1 : v)
        {
            std::cout << v1 << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
