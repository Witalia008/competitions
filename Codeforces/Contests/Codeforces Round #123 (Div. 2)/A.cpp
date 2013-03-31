#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ll;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define N 100005

int a, b, c;

bool can(int t)
{
    for (int t0 = t; t0 <= t + c; t0++)
        if (t0 * b < (t0 - t) * a)
            return false;
    return true;
}

int bin_search(int l, int r)
{
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        if (can(mid))
            r = mid;
        else
            l = mid;
    }
    if (can(l))
        return l;
    return r;
}

int main()
{
    //freopen ("input.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", bin_search(1, 1000000));
    return 0;
}
