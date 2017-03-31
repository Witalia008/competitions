#include <iostream>
#include <set>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> dict;
string s, x;

int main()
{
    ifstream dct("dict.txt");
    ifstream ans("pal.txt");

    dict.clear();
    for (;;)
    {
        x = "";
        dct >> x;
        if (x == "")
            break;
        dict[x] = 1;
    }

    for (;;)
    {
        x = "";
        ans >> x;
        if (x == "")
            break;
        s += x;
        if (dict.find(x) == dict.end())
        {
            cout << "No such word in dictionary!\n";
            return 0;
        }
        if (dict[x] > 1)
        {
            cout << "Multiple usage of a word!\n";
            return 0;
        }
        dict[x]++;
    }

    if (s.size() < 1000)
    {
        cout << "String has lower length that necessary!\n";
        return 0;
    }

    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - 1 - i])
        {
            cout << "Not a palindrome!\n";
            return 0;
        }
    }
    cout << "Cool! You did it, man!\n";
    ofstream ouf("output.txt");
    ouf << "Length: " << s.size() << endl;
    ouf << s.substr(0, (s.size() + 1) / 2) << endl;
    s.erase(0, (s.size() + 1) / 2);
    reverse(s.begin(), s.end());
    ouf << s << endl;

    ouf.close();
    dct.close();
    ans.close();
    return 0;
}
