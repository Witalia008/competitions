#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <memory.h>

using namespace std;

typedef unsigned long long ull;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define M 100000
#define N 1005
#define K 11

struct TList
{
    int dest, next, tim;
    bool plane;
};

struct TQ
{
    int ver, m;
};

int n, m, a, b, en, v, w;
TList List[M];
int Head[N], D[N][K];
TQ queue[N * K];
bool inq[N][K];

void Add(int u, int v, int t, bool pl)
{
    en++;
    List[en].dest = v;
    List[en].tim = t;
    List[en].next = Head[u];
    List[en].plane = pl;
    Head[u] = en;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &a, &b);
    scanf("%d", &v);
    for (int i = 0; i < v; i++)
    {
        int I, J, L;
        scanf("%d%d%d", &I, &J, &L);
        Add(I, J, L, false);
        Add(J, I, L, false);
    }
    scanf("%d", &w);
    for (int i = 0; i < w; i++)
    {
        int I, J, L;
        scanf("%d%d%d", &I, &J, &L);
        Add(I, J, L, true);
        Add(J, I, L, true);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            D[i][j] = Inf;
    D[a][0] = 0;
    inq[a][0] = true;
    int qt = 1, qh = 0;
    queue[0].ver = a;
    while (qh != qt)
    {
        TQ V = queue[qh];
        inq[V.ver][V.m] = false;
        qh = (qh + 1) % (K * N);
        for (int j = Head[V.ver]; j; j = List[j].next)
            if (V.m + List[j].plane <= m && D[List[j].dest][V.m + List[j].plane] > D[V.ver][V.m] + List[j].tim)
            {
                D[List[j].dest][V.m + List[j].plane] = D[V.ver][V.m] + List[j].tim;
                if (!inq[List[j].dest][V.m + List[j].plane])
                {
                    queue[qt].ver = List[j].dest;
                    queue[qt].m = V.m + List[j].plane;
                    qt = (qt + 1) % (K * N);
                    inq[List[j].dest][V.m + List[j].plane] = true;
                }
            }
    }
    int ans = Inf;
    for (int i = 0; i <= m; i++)
        if (D[b][i] < ans)
            ans = D[b][i];
    if (ans == Inf)
        ans = 0;
    printf("%d\n", ans);
    return 0;
}
