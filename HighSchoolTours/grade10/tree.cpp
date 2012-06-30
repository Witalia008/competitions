#include <stdio.h>
#include <cstdlib>
#include <iostream>

const int nmax = 1000;

using namespace std;

int N, M, K;
struct Tree
{
    int y[nmax * 7 / 2];
};

Tree tree[nmax * 4];

void addy(int val, int y, int l, int r, int v, int xv)
{
    if (l == r)
        tree[xv].y[v] += val;
    else
    {
        int mid = (l + r) / 2;
        if (y <= mid)
            addy(val, y, l, mid, v * 2, xv);
        else
            addy(val, y, mid + 1, r, v * 2 + 1, xv);
        tree[xv].y[v] = tree[xv].y[v * 2] + tree[xv].y[v * 2 + 1];
    }
}

void add(int val, int x, int y, int l, int r, int v)
{
    addy(val, y, 1, M, 1, v);
    if (l != r)
    {
        int mid = (l + r) / 2;
        if (x <= mid)
            add(val, x, y, l, mid, v * 2);
        else
            add(val, x, y, mid + 1, r, v * 2 + 1);
        tree[v].y[1] = tree[v * 2].y[1] + tree[v * 2 + 1].y[1];
    }
}

int sumy(int yl, int yr, int l, int r, int v, int xv)
{
    if (yl == l && yr == r)
        return tree[xv].y[v];
    int mid = (l + r) / 2;
    if (yr <= mid)
        return sumy(yl, yr, l, mid, v * 2, xv);
    if (yl > mid)
        return sumy(yl, yr, mid + 1, r, v * 2 + 1, xv);
    return sumy(yl, mid, l, mid, v * 2, xv) + sumy(mid + 1, yr, mid + 1, r, v * 2 + 1, xv);
}

int sum(int xl, int xr, int yl, int yr, int l, int r, int v)
{
    if (xl == l && xr == r)
        return sumy(yl, yr, 1, M, 1, v);
    int mid = (l + r) / 2;
    if (xr <= mid)
        return sum(xl, xr, yl, yr, l, mid, v * 2);
    if (xl > mid)
        return sum(xl, xr, yl, yr, mid + 1, r, v * 2 + 1);
    return sum(xl, mid, yl, yr, l, mid, v * 2) + sum(mid + 1, xr, yl, yr, mid + 1, r, v * 2 + 1);
}

int a[101][101][101];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &N, &M);
    memset(tree, 0, sizeof(tree));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            int a;
            scanf("%d", &a);
            add(a, i, j, 1, N, 1);
        }
    scanf("%d", &K);
    for (int i = 1; i <= K; i++)
    {
        int xl, xr, yl, yr;
        scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
        printf("%d\n", sum(xl, xr, yl, yr, 1, N, 1));
    }
    return 0;
}
