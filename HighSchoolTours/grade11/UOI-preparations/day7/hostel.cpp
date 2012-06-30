#include <stdio.h>
#include <cstdlib>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define N 20005
#define M 200005

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}
ll sqr(ll a) { return a * a; }

struct TList
{
    int dest, next;
};

TList List[M * 2];
int Head[N], tin[N], fup[N];
ll Ans[N];
bool used[N], cutp[N];
int n, m, en, time, sons;

void Add(int u, int v)
{
    en++;
    List[en].dest = v;
    List[en].next = Head[u];
    Head[u] = en;
}

void dfs(int v, int p = -1)
{
    used[v] = true;
    fup[v] = tin[v] = ++time;
    Ans[v] = sqr(ll(n - 1));
    int cc = 0;
    for (int j = Head[v]; j; j = List[j].next)
    {
        int to = List[j].dest;
        if (!used[to])
        {
            if (p == -1)
                sons++;
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] >= tin[v])
            {
                cc += time - tin[to] + 1;
                Ans[v] -= sqr(ll(time - tin[to] + 1));
                if (p != -1)
                    cutp[v] = true;
            }
        }
        else if (to != p)
            fup[v] = min(fup[v], tin[to]);
    }
    if (p != -1)
        Ans[v] -= sqr(ll(n - cc - 1));
    if (p == -1 && sons > 1)
        cutp[v] = true;
    if (!cutp[v])
        Ans[v] = 0;
    else
        Ans[v] /= 2;
}

int main()
{
    freopen("hostel.in", "r", stdin);
    freopen("hostel.out", "w", stdout);
    scanf("%d%d", &n, &m);
    REP(i, m)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        Add(u, v);
        Add(v, u);
    }
    dfs(1);
    FOR(i, 1, n)
    printf("%I64d\n", Ans[i] + ll(n - 1));
    return 0;
}
