#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int N;
string s;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] >= 'A' && s[j] <= 'Z')
                s[j] += 'a' - 'A';
            if (s[j] >= 'a' && s[j] <= 'c')
                s[j] = '2';
            if (s[j] >= 'd' && s[j] <= 'f')
                s[j] = '3';
            if (s[j] >= 'g' && s[j] <= 'i')
                s[j] = '4';
            if (s[j] >= 'j' && s[j] <= 'l')
                s[j] = '5';
            if (s[j] >= 'm' && s[j] <= 'o')
                s[j] = '6';
            if (s[j] >= 'p' && s[j] <= 's')
                s[j] = '7';
            if (s[j] >= 't' && s[j] <= 'v')
                s[j] = '8';
            if (s[j] >= 'w' && s[j] <= 'z')
                s[j] = '9';
        }
        bool fl = true;
        for (int j = 0; j < s.length(); j++)
            if (s[j] != s[s.length() - 1 - j])
                fl = false;
        if (fl)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
