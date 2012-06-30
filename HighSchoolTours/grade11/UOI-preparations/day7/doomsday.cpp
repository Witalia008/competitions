#include <stdio.h>
#include <cstdlib>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, n) FOR(i, 0, n - 1)
#define M 100005
#define N 30005
#define K 17

struct TList
{
    int dest, next, nom, c;
};

struct TEdge
{
    int u, v, c;
    bool us;
};

TList List[N * 2];
TEdge E[M];
int anc[N][K];
int Head[N], se[N], cntW[N], deph[N];
int n, m, en, cntB;

int dsu_get(int v)
{
    if (se[v] == -1)
        return v;
    return (se[v] = dsu_get(se[v]));
}

bool dsu_join(int u, int v)
{
    u = dsu_get(u);
    v = dsu_get(v);
    if (u == v)
        return false;
    if (rand() & 1)
        se[u] = v;
    else
        se[v] = u;
    return true;
}

void Add(int i)
{
    en++;
    List[en].nom = i;
    List[en].c = E[i].c;
    List[en].dest = E[i].v;
    List[en].next = Head[E[i].u];
    Head[E[i].u] = en;
    en++;
    List[en].nom = i;
    List[en].c = E[i].c;
    List[en].dest = E[i].u;
    List[en].next = Head[E[i].v];
    Head[E[i].v] = en;
}

void dfs1(int v, int p = -1, int cnt = 0)
{
    anc[v][0] = (p == -1 ? v : p);
    FOR(i, 1, K - 1)
    anc[v][i] = anc[anc[v][i - 1]][i - 1];
    cntW[v] = cnt;
    deph[v] = (p == -1 ? 0 : deph[p] + 1);
    for (int j = Head[v]; j; j = List[j].next)
        if (List[j].dest != p)
            dfs1(List[j].dest, v, cnt + (List[j].c == 1));
}

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int get_lca(int u, int v)
{
    if (deph[u] < deph[v])
        swap(u, v);
    if (deph[u] > deph[v])
    {
        FORD(i, K - 1, 0)
        if (deph[anc[u][i]] >= deph[v])
            u = anc[u][i];
    }
    if (u != v)
    {
        FORD(i, K - 1, 0)
        if (anc[u][i] != anc[v][i])
            u = anc[u][i], v = anc[v][i];
        u = anc[u][0];
    }
    return u;
}

bool del;
bool dfs2(int v, int f, int p = -1)
{
    if (v == f)
        return true;
    for (int j = Head[v]; j; j = List[j].next)
        if (List[j].dest != p)
            if (dfs2(List[j].dest, f, v))
            {
                if (!del && List[j].c == 1)
                {
                    del = true;
                    E[List[j].nom].us = false;
                }
                return true;
            }
    return false;
}

int edge;
void buildTree(int col)
{
    REP(i, m)
    if (E[i].c == col)
        if (dsu_join(E[i].u, E[i].v))
        {
            Add(i);
            E[i].us = true;
            cntB += (col == 2);
            edge++;
        }
}

int main()
{
    freopen("doomsday.in", "r", stdin);
    freopen("doomsday.out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i, 1, n)
    se[i] = -1;
    REP(i, m)
    scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].c);
    buildTree(1);
    if (edge != n - 1)
        buildTree(2);
    if (cntB & 1)
    {
        dfs1(1);
        REP(i, m)
        if (E[i].c == 2 && !E[i].us)
        {
            int a = E[i].u, b = E[i].v;
            int p = get_lca(a, b);
            int cw = cntW[a] + cntW[b] - 2 * cntW[p];
            if (cw)
            {
                E[i].us = true;
                dfs2(a, b);
                cntB++;
                break;
            }
        }
    }
    if (cntB & 1)
        printf("-1\n");
    else
    {
        REP(i, m)
        if (E[i].us)
            printf("%d\n", i + 1);
    }
    return 0;
}
