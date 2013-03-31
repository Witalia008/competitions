#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>

using namespace std;

const char *infile = "input.txt";
const char *outfile = "output.txt";

typedef set<string> TS;

TS S;
string a, b;

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    while (!cin.eof())
    {
        cin >> a;
        //if (cin.eof()) break;
        S.insert(a);
    }
    for (TS::iterator it = S.begin(); it != S.end(); it++)
    {
        a = "";
        b = *it;
        while (b.length() != 1)
        {
            a += b[0];
            b.erase(0, 1);
            if (S.find(a) != S.end() && S.find(b) != S.end())
            {
                cout << a + b << endl;
                break;
            }
        }
    }
    return 0;
}
