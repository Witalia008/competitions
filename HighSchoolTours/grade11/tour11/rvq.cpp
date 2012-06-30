#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

const char *infile = "rvq.in";
const char *outfile = "rvq.out";

#define n_max 100001

int MaxT[n_max * 4], MinT[n_max * 4];

void Add(int l, int r, int v, int x, int val)
{
    if (l == r)
    {
        MaxT[v] = MinT[v] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
        Add(l, mid, v * 2, x, val);
    else
        Add(mid + 1, r, v * 2 + 1, x, val);
    MaxT[v] = max(MaxT[v * 2], MaxT[v * 2 + 1]);
    MinT[v] = min(MinT[v * 2], MinT[v * 2 + 1]);
}

int GetMax(int l, int r, int v, int kl, int kr)
{
    if (kl == l && kr == r)
        return MaxT[v];
    int mid = (l + r) / 2;
    if (kr <= mid)
        return GetMax(l, mid, v * 2, kl, kr);
    if (kl > mid)
        return GetMax(mid + 1, r, v * 2 + 1, kl, kr);
    return max(GetMax(l, mid, v * 2, kl, mid), GetMax(mid + 1, r, v * 2 + 1, mid + 1, kr));
}

int GetMin(int l, int r, int v, int kl, int kr)
{
    if (kl == l && kr == r)
        return MinT[v];
    int mid = (l + r) / 2;
    if (kr <= mid)
        return GetMin(l, mid, v * 2, kl, kr);
    if (kl > mid)
        return GetMin(mid + 1, r, v * 2 + 1, kl, kr);
    return min(GetMin(l, mid, v * 2, kl, mid), GetMin(mid + 1, r, v * 2 + 1, mid + 1, kr));
}

int k, x, y;

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d", &k);

    for (long long i = 1; i < n_max; i++)
        Add(1, n_max, 1, i, int((i * i) % 12345 + (i * i * i) % 23456));

    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &x, &y);
        if (x < 0)
            Add(1, n_max, 1, -x, y);
        else
            printf("%d\n", GetMax(1, n_max, 1, x, y) - GetMin(1, n_max, 1, x, y));
    }
    return 0;
}
