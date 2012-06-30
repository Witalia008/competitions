#include <stdio.h>
#include <cstdlib>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define Inf 1000000000
#define N 50005

struct TList
{
    int dest, next;
};

int n, k, en, cnt;
TList List[N * 2];
int Head[N], dist[N], P[N];
bool isHere[N], used[N];

void Add(int u, int v)
{
    en++;
    List[en].dest = v;
    List[en].next = Head[u];
    Head[u] = en;
}

void set_tree(int v, int p = -1)
{
    P[v] = p;
    for (int j = Head[v]; j; j = List[j].next)
        if (List[j].dest != p)
            set_tree(List[j].dest, v);
}

void bfs(int v, int ngo, int l)
{
    used[v] = true;
    if (!dist[v])
        dist[v] = -Inf;
    if (!l)
        return;
    dist[v] = -Inf;
    for (int j = Head[v]; j; j = List[j].next)
        if (List[j].dest != ngo)
        {
            bfs(List[j].dest, ngo, l - 1);
            if (List[j].dest != P[v])
                dist[v] = max(dist[v], dist[List[j].dest] + 1);
        }
}

void dfs(int v, int l)
{
    dist[v] = (used[v] ? -Inf : 0);
    for (int j = Head[v]; j; j = List[j].next)
        if (List[j].dest != P[v])
            dfs(List[j].dest, l);
    for (int j = Head[v]; j; j = List[j].next)
        if (List[j].dest != P[v])
            dist[v] = max(dist[v], dist[List[j].dest] + 1);
    if (dist[v] == l)
    {
        isHere[v] = true;
        dist[v] = -Inf;
        cnt++;
        if (P[v] != -1)
            bfs(P[v], v, l - 1);
    }
}

bool try_put(int l)
{
    cnt = 0;
    FOR(i, 1, n)
    {
        isHere[i] = used[i] = false;
        dist[i] = 0;
    }
    dfs(1, l);
    return (cnt <= k);
}

int bin_search(int l, int r)
{
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        if (try_put(mid))
            r = mid;
        else
            l = mid;
    }
    if (try_put(l))
        return l;
    return r;
}

int main()
{
    freopen("barns.in", "r", stdin);
    freopen("barns.out", "w", stdout);
    scanf("%d%d", &n, &k);
    REP(i, n - 1)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        Add(a, b);
        Add(b, a);
    }
    set_tree(1);
    int L = bin_search(0, n);
    printf("%d\n", L);
    try_put(L);
    FOR(i, 1, n)
    if (!isHere[i] && cnt < k)
    {
        isHere[i] = true;
        cnt++;
    }
    FOR(i, 1, n)
    if (isHere[i])
    {
        printf("%d", i);
        if (k)
            printf(" ");
        else
            printf("\n");
        --k;
    }
    return 0;
}
