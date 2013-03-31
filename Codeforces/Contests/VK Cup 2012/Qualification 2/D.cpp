#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long LL;

#define NMAX 2002

string s;
bool F[NMAX][NMAX];
LL end[NMAX], beg[NMAX];
LL ans;

int main()
{
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++)
        F[i][1] = F[i][0] = end[i] = beg[i] = 1;
    for (int l = 2; l <= len; l++)
        for (int i = 0; i <= len - l; i++)
            if (s[i] == s[i + l - 1] && F[i + 1][l - 2])
            {
                F[i][l] = true;
                beg[i]++;
                end[i + l - 1]++;
            }
    for (int i = 0; i < len; i++)
        for (int j = i + 1; j < len; j++)
            ans += end[i] * beg[j];
    cout << ans << endl;
    return 0;
}
