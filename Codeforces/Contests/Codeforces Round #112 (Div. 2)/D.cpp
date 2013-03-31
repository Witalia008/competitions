#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef unsigned long long ll;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define InfL Inf *Inf
#define N 1000005

struct TList
{
    int dest, next;
};

struct Tree
{
    Tree *l, *r;
    int sum;
    Tree(int x) : l(0), r(0), sum(x) {}
    Tree(Tree *ll, Tree *rr)
    {
        l = ll;
        r = rr;
        sum = l->sum + r->sum;
    }
};

Tree *xtree[N * 4];
int n, en, pp, cc, start, m;
TList List[N * 2];
bool used[N];
int Head[N], part[N], deph[N], Num[N], step[N], cou[N];

void Add(int u, int v)
{
    en++;
    List[en].dest = v;
    List[en].next = Head[u];
    Head[u] = en;
    step[u]++;
}

Tree *build(int l, int r)
{
    if (l == r)
        return new Tree(1);
    int mid = (l + r) / 2;
    return new Tree(build(l, mid), build(mid + 1, r));
}

void dfs(int v, int p = -1)
{
    used[v] = true;
    part[v] = pp;
    deph[v] = p == -1 ? 0 : deph[p] + 1;
    for (int j = Head[v]; j; j = List[j].next)
        if (!used[List[j].dest])
        {
            if (p == -1)
                pp++, cc = 0;
            Num[List[j].dest] = ++cc;
            dfs(List[j].dest, v);
            if (p == -1)
                xtree[pp] = build(1, cc);
            cou[pp] = cc;
        }
}

void add(Tree *t, int l, int r, int x, int val)
{
    t->sum += val;
    if (l == r)
        return;
    int mid = (l + r) / 2;
    if (x <= mid)
        add(t->l, l, mid, x, val);
    else
        add(t->r, mid + 1, r, x, val);
}

int get(Tree *t, int l, int r, int kl, int kr)
{
    if (kl == l && kr == r)
        return t->sum;
    int mid = (l + r) / 2;
    if (kr <= mid)
        return get(t->l, l, mid, kl, kr);
    if (kl > mid)
        return get(t->r, mid + 1, r, kl, kr);
    return get(t->l, l, mid, kl, mid) + get(t->r, mid + 1, r, mid + 1, kr);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    start = 1;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        Add(a, b);
        Add(b, a);
    }
    FOR(i, 1, n)
    if (step[i] > 2)
        start = i;
    dfs(start);
    scanf("%d", &m);
    REP(i, m)
    {
        int t, a, b;
        scanf("%d", &t);
        if (t == 1)
        {
            scanf("%d", &a);
            a = (a * 2) - 1;
            int v = List[a].dest;
            if (deph[List[a + 1].dest] > deph[v])
                v = List[a + 1].dest;
            add(xtree[part[v]], 1, cou[part[v]], max(Num[v], 1), 1);
        }
        if (t == 2)
        {
            scanf("%d", &a);
            a = (a * 2) - 1;
            int v = List[a].dest;
            if (deph[List[a + 1].dest] > deph[v])
                v = List[a + 1].dest;
            add(xtree[part[v]], 1, cou[part[v]], max(Num[v], 1), -1);
        }
        if (t == 3)
        {
            scanf("%d%d", &a, &b);
            if (a == b)
            {
                printf("0\n");
                continue;
            }
            if (a == start)
                part[a] = part[b];
            if (b == start)
                part[b] = part[a];
            if (part[a] == part[b])
            {
                if (deph[a] > deph[b])
                    swap(a, b);
                int l = deph[b] - deph[a];
                if (get(xtree[part[a]], 1, cou[part[a]], Num[a] + 1, Num[b]) == l)
                    printf("%d\n", l);
                else
                    printf("-1\n");
            }
            else
            {
                int l = deph[a] + deph[b];
                if (get(xtree[part[a]], 1, cou[part[a]], 1, Num[a]) + get(xtree[part[b]], 1, cou[part[b]], 1, Num[b]) == l)
                    printf("%d\n", l);
                else
                    printf("-1\n");
            }
        }
    }
    return 0;
}
