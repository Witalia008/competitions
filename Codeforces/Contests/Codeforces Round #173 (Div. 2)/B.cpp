#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>

//#include "list.h"

using namespace std;

#define Abs(a) (a < 0 ? (-(a)) : (a))

int n;
int a, g;
int sa, sg;
string res;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    res = "";
    for (int i = 0; i < n; i++)
    {
        cin >> a >> g;
        if (Abs(sa - sg + a) <= Abs(sg - sa + g))
        {
            sa += a;
            res += 'A';
        }
        else
        {
            sg += g;
            res += 'G';
        }
    }
    if (Abs(sa - sg) <= 500)
        cout << res << endl;
    else
        cout << -1 << endl;
    return 0;
}
