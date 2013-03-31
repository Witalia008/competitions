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
#define InfL Inf *Inf
#define N 205

int n, k;

bool can_get(int cnt)
{
    ll s = 1, res = 0;
    while (cnt / s)
    {
        res += cnt / s;
        s *= ll(k);
    }
    return res >= n;
}

int bin_search(int l, int r)
{
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        if (can_get(mid))
            r = mid;
        else
            l = mid;
    }
    if (can_get(l))
        return l;
    return r;
}

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    printf("%d\n", bin_search(1, n));
    return 0;
}
