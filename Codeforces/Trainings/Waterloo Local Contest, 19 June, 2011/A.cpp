#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <string>
#include <iostream>

using namespace std;

const char *infile = "input.txt";
const char *outfile = "output.txt";

#define f_c F[c[0]][c[1]][c[2]][c[3]][c[4]][c[5]]

char F[5][5][5][5][5][5];
char c[6];

char f(int cs)
{
    if (f_c != -1)
        return f_c;
    if (cs > 31)
        return (f_c = true);
    for (int i = 0; i < 6; i++)
        if (c[i] < 4 && cs + i + 1 <= 31)
        {
            c[i]++;
            if (!f(cs + i + 1))
            {
                c[i]--;
                return (f_c = true);
            }
            c[i]--;
        }
    return (f_c = false);
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    memset(F, -1, sizeof(F));
    while (!cin.eof())
    {
        string s;
        getline(cin, s);
        cout << s;
        memset(c, 0, sizeof(c));
        int ss = 0;
        for (int i = 0; i < s.length(); i++)
            c[s[i] - '0' - 1]++, ss += s[i] - '0';
        f(ss);
        if (s != "")
            cout << " ";
        cout << ((f_c ^ (s.length() % 2)) ? "A" : "B") << endl;
    }
    return 0;
}
