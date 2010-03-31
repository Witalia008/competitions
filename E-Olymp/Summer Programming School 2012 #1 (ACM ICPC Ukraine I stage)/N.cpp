#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

set<string> A, S, B;
set<string>::iterator it;
int n, m;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        A.insert(s);
    }
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        B.insert(s);
    }
    for (it = A.begin(); it != A.end(); it++)
        if (B.find(*it) != B.end())
            S.insert(*it);
    cout << S.size() << endl;
    return 0;
}
