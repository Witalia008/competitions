#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <memory.h>
#define nmax 200001

using namespace std;

struct TTree
{
    int data, nom;
};

int n;
long long ans;
int A[nmax];
TTree Tree[nmax * 4];

void Add(int val, int pos, int v, int l, int r)
{
    if (l == r)
    {
        Tree[v].data = val;
        Tree[v].nom = pos;
        return;
    }
    if (Tree[v].data == -1 || val < Tree[v].data)
    {
        Tree[v].data = val;
        Tree[v].nom = pos;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        Add(val, pos, v * 2, l, mid);
    else
        Add(val, pos, v * 2 + 1, mid + 1, r);
}

int GetMin(int kl, int kr, int v, int l, int r)
{
    if (kl == l && kr == r)
        return Tree[v].nom;
    int mid = (l + r) / 2;
    if (kr <= mid)
        return GetMin(kl, kr, v * 2, l, mid);
    if (kl > mid)
        return GetMin(kl, kr, v * 2 + 1, mid + 1, r);
    int MinL = GetMin(kl, mid, v * 2, l, mid);
    int MinR = GetMin(mid + 1, kr, v * 2 + 1, mid + 1, r);
    if (A[MinL] < A[MinR])
        return MinL;
    else
        return MinR;
}

void Solve(int l, int r, int sub)
{
    if (l == r - 1)
    {
        ans += max(A[l], A[r]) - sub;
        return;
    }
    if (l == r)
    {
        ans += A[l] - sub;
        return;
    }
    int et = GetMin(l, r, 1, 1, n);
    ans += A[et] - sub;
    if (et > l)
        Solve(l, et - 1, A[et]);
    if (et < r)
        Solve(et + 1, r, A[et]);
}

int main()
{
    freopen("bricks.in", "r", stdin);
    freopen("bricks.out", "w", stdout);
    scanf("%d", &n);
    memset(Tree, -1, sizeof(Tree));
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &A[i]);
        Add(A[i], i, 1, 1, n);
    }
    ans = 0;
    Solve(1, n, 0);
    cout << ans << "\n";
    return 0;
}
