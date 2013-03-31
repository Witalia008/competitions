#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define P 1000000007
#define N 100005

typedef long long ll;

int n, k;
ll ans;
bool used[N];
ll deph[N];
int p[N], anc[N];

int dsu_get(int v)
{
    if (v == p[v])
        return v;
    int x = dsu_get(p[v]);
    deph[v] = (deph[v] + deph[p[v]]) % P;
    return (p[v] = x);
}

void get(int v)
{
    while (!used[v])
    {
        used[v] = true;
        ans = (ans + deph[v] - deph[anc[v]]) % P;
        v = anc[v];
    }
}

int main()
{
    // freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        p[i] = anc[i] = i;
        for (int j = 0; j < k; j++)
        {
            int v, x;
            scanf("%d%d", &v, &x);
            int root = dsu_get(v);
            p[root] = i;
            anc[root] = i;
            deph[root] = (deph[v] + ll(x)) % P;
        }
    }
    for (int i = 1; i <= n; i++)
        dsu_get(i);
    for (int i = 1; i <= n; i++)
        get(i);
    if (ans < 0)
        ans += P;
    printf("%I64d\n", ans % P);
    return 0;
}
