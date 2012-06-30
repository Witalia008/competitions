#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define nmax 2010

using namespace std;

int S, R;
double F[nmax + 1][nmax + 1];

int main()
{
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    cin >> S >> R;
    if (S % 2 == 1)
        cout << "0.000000000\n";
    else
    {
        for (int j = 1; j <= R; j++)
            F[0][j] = 1;
        for (int i = 2; i <= S; i++)
            for (int j = 1; j <= R; j++)
            {
                int k1 = i * (i - 1) / 2, k2 = i * j;
                int k = k1 + k2;
                F[i][j] = F[i - 2][j] * ((double)k1 / k) + F[i][j - 1] * ((double)k2 / k);
            }
        printf("%0.10lf\n", F[S][R]);
    }
    return 0;
}
