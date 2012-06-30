#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

unsigned long long f[50];
int n, m;

int main()
{
    freopen("domino.in", "r", stdin);
    freopen("domino.out", "w", stdout);
    cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        f[i] = f[i - 1];
        if (i - n >= 0)
            f[i] += f[i - n];
    }
    cout << f[m] << endl;
    return 0;
}
