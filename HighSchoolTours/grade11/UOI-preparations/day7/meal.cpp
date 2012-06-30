#include <stdio.h>
#include <cstdlib>

using namespace std;

typedef unsigned long long ll;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define N 1000005

struct TList
{
    int next, dest;
};

struct Tree
{
    ll sum, D;
};

TList List[N];
int Head[N], L[N], R[N], A[N], order[N], stack[N];
Tree tree[N * 4];
int en, n, m, root, time;

void Add(int u, int v)
{
    en++;
    List[en].dest = v;
    List[en].next = Head[u];
    Head[u] = en;
}

void dfs()
{
    int top = 1, v;
    stack[1] = root;
    L[root] = 1;
    while (top)
    {
        v = stack[top];
        if (Head[v])
        {
            stack[++top] = List[Head[v]].dest;
            L[stack[top]] = time + 1;
            Head[v] = List[Head[v]].next;
        }
        else
        {
            order[++time] = v;
            R[v] = time;
            --top;
        }
    }
}

void build(int v, int l, int r)
{
    if (l == r)
        tree[v].sum = A[order[l]];
    else
    {
        int mid = (l + r) / 2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
        tree[v].sum = tree[v * 2].sum + tree[v * 2 + 1].sum;
    }
}

void AddTree(int v, int l, int r, int kl, int kr, ll val)
{
    if (kl == l && kr == r)
    {
        tree[v].D += val;
        tree[v].sum += (ll(r - l + 1)) * val;
        return;
    }
    int mid = (l + r) / 2;
    if (kr <= mid)
        AddTree(v * 2, l, mid, kl, kr, val);
    else if (kl > mid)
        AddTree(v * 2 + 1, mid + 1, r, kl, kr, val);
    else
    {
        AddTree(v * 2, l, mid, kl, mid, val);
        AddTree(v * 2 + 1, mid + 1, r, mid + 1, kr, val);
    }
    tree[v].sum = tree[v * 2].sum + tree[v * 2 + 1].sum + tree[v].D * (ll(r - l + 1));
}

ll GetSum(int v, int l, int r, int kl, int kr)
{
    if (kl == l && kr == r)
        return tree[v].sum;
    int mid = (l + r) / 2;
    ll ad = tree[v].D * (ll(kr - kl + 1));
    if (kr <= mid)
        return GetSum(v * 2, l, mid, kl, kr) + ad;
    if (kl > mid)
        return GetSum(v * 2 + 1, mid + 1, r, kl, kr) + ad;
    return GetSum(v * 2, l, mid, kl, mid) + GetSum(v * 2 + 1, mid + 1, r, mid + 1, kr) + ad;
}

char wh;
int a, d;

int main()
{
    freopen("meal.in", "r", stdin);
    freopen("meal.out", "w", stdout);
    scanf("%d%d\n", &n, &m);
    FOR(i, 1, n)
    {
        int p;
        scanf("%d%d\n", &p, &A[i]);
        if (p == -1)
            root = i;
        else
            Add(p, i);
    }
    dfs();
    build(1, 1, n);
    REP(i, m)
    {
        scanf("%c", &wh);
        if (wh == '+')
        {
            scanf("%d%d\n", &a, &d);
            AddTree(1, 1, n, L[a], R[a], ll(d));
        }
        else
        {
            scanf("%d\n", &a);
            printf("%I64d\n", GetSum(1, 1, n, L[a], R[a]));
        }
    }
    return 0;
}
