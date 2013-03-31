#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define N 100001
#define M 20

struct TList
{
    int dest, next;
};

int Head[N];
TList List[N * 2];
int anc[M][N];
int deph[N], A[N], B[N], Cnt[N];
int n, m, en;

void Add(int u, int v)
{
    en++;
    List[en].dest = v;
    List[en].next = Head[u];
    Head[u] = en;
}

void dfs(int v, int p = -1)
{
    deph[v] = 0;
    if (p != -1)
        deph[v] = deph[p] + 1;
    anc[0][v] = v;
    if (p != -1)
        anc[0][v] = p;
    for (int i = 1; i < M; i++)
        anc[i][v] = anc[i - 1][anc[i - 1][v]];
    for (int j = Head[v]; j; j = List[j].next)
        if (List[j].dest != p)
            dfs(List[j].dest, v);
}

int lca(int u, int v)
{
    if (deph[u] < deph[v])
        swap(u, v);
    if (deph[u] != deph[v])
        for (int i = M - 1; i >= 0; i--)
            if (deph[anc[i][u]] >= deph[v])
                u = anc[i][u];
    if (u == v)
        return u;
    for (int i = M - 1; i >= 0; i--)
        if (anc[i][u] != anc[i][v])
            u = anc[i][u], v = anc[i][v];
    return anc[0][u];
}

void dfs1(int v, int p = -1)
{
    for (int j = Head[v]; j; j = List[j].next)
        if (List[j].dest != p)
        {
            dfs1(List[j].dest, v);
            Cnt[v] += Cnt[List[j].dest];
        }
}

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &A[i], &B[i]);
        Add(A[i], B[i]);
        Add(B[i], A[i]);
    }
    dfs(1);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        int x = lca(u, v);
        Cnt[u]++;
        Cnt[v]++;
        Cnt[x] -= 2;
    }
    dfs1(1);
    for (int i = 1; i < n; i++)
    {
        if (i != 1)
            printf(" ");
        int nom = A[i];
        if (deph[B[i]] > deph[A[i]])
            nom = B[i];
        printf("%d", Cnt[nom]);
    }
    printf("\n");
    return 0;
}
