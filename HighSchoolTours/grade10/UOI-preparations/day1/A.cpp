#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define sqr(a) ((a) * (a))

using namespace std;

long long min(long long a, long long b)
{
    if (a < b)
        return a;
    else
        return b;
}

int y[100001];
long long f[100001];

int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &y[i]);
    f[1] = 0;
    f[2] = sqr(y[2] - y[1]);
    f[3] = min(f[2] + sqr(y[3] - y[2]), f[1] + 3 * sqr(y[3] - y[1]));
    for (int i = 4; i <= n; i++)
        f[i] = min(
            f[i - 1] + sqr(y[i] - y[i - 1]), min(
                                                 f[i - 2] + 3 * sqr(y[i] - y[i - 2]),
                                                 f[i - 3] + 3 * sqr(y[i - 1] - y[i - 3]) + sqr(y[i - 1] - y[i - 2]) + 3 * sqr(y[i] - y[i - 2])));
    cout << f[n] << endl;
    return 0;
}
