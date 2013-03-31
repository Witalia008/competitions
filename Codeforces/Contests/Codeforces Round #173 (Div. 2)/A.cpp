#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>

//#include "list.h"

using namespace std;

int x, n;
string s;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "++X" || s == "X++")
        {
            x++;
        }
        else
        {
            x--;
        }
    }
    cout << x << endl;
    return 0;
}
