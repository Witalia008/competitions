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
int a1, a2, a3;
int mas[301][301];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    if (n == 1)
    {
        cin >> a1;
        if (a1)
        {
            cout << "BitLGM" << endl;
        }
        else
        {
            cout << "BitAryo" << endl;
        }
    }
    else if (n == 2)
    {
        cin >> a1 >> a2;
        for (int i = 0; i <= 300; i++)
            for (int j = 0; j <= 300; j++)
                for (int k = 1; k <= 300; k++)
                {
                    if (k <= i && k <= j && !mas[i - k][j - k])
                        mas[i][j] = 1;
                    if (k <= i && !mas[i - k][j])
                        mas[i][j] = 1;
                    if (k <= j && !mas[i][j - k])
                        mas[i][j] = 1;
                }
        if (mas[a1][a2])
        {
            cout << "BitLGM" << endl;
        }
        else
            cout << "BitAryo" << endl;
    }
    else
    {
        cin >> a1 >> a2 >> a3;
        if (a1 ^ a2 ^ a3)
        {
            cout << "BitLGM" << endl;
        }
        else
            cout << "BitAryo" << endl;
    }
    return 0;
}
