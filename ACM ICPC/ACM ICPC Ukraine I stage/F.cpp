#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s, a, ra;
int cnt[300];
char x;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        cnt[s[i]]++;
    for (int i = 'a'; i <= 'z'; i++)
    {
        while (cnt[i] > 1)
            a += i, ra += i, cnt[i] -= 2;
        if (cnt[i] == 1 && !x)
            x = i;
    }
    cout << a;
    if (x)
        cout << x;
    reverse(ra.begin(), ra.end());
    cout << ra << endl;
    return 0;
}
