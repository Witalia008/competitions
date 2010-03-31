#include <stdio.h>
#include <cstdlib>

using namespace std;

typedef long long ll;

#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REPD(i, n) FORD(i, n - 1, 0)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define N 100000

struct TTree
{
    bool all;
    ll sum, val;
};

TTree Tree[4 * N];
int n, k;

void Add(int v, int l, int r, int kl, int kr, int val)
{
    if (kl == l && kr == r)
    {
        Tree[v].all = true;
        Tree[v].val = val;
        Tree[v].sum = ll(val) * ll(r - l + 1);
        return;
    }
    int mid = (l + r) / 2;
    if (Tree[v].all)
    {
        if (val == Tree[v].val)
            return;
        Tree[v * 2].all = Tree[v * 2 + 1].all = true;
        Tree[v * 2].val = Tree[v * 2 + 1].val = Tree[v].val;
        Tree[v * 2].sum = ll(mid - l + 1) * Tree[v].val;
        Tree[v * 2 + 1].sum = ll(r - mid) * Tree[v].val;
        Tree[v].all = false;
    }
    if (kr <= mid)
        Add(v * 2, l, mid, kl, kr, val);
    else if (kl > mid)
        Add(v * 2 + 1, mid + 1, r, kl, kr, val);
    else
    {
        Add(v * 2, l, mid, kl, mid, val);
        Add(v * 2 + 1, mid + 1, r, mid + 1, kr, val);
    }
    Tree[v].sum = Tree[v * 2].sum + Tree[v * 2 + 1].sum;
}

ll Get(int v, int l, int r, int kl, int kr)
{
    if (Tree[v].all)
        return Tree[v].val * ll(kr - kl + 1);
    if (kl == l && kr == r)
        return Tree[v].sum;
    int mid = (l + r) / 2;
    if (kr <= mid)
        return Get(v * 2, l, mid, kl, kr);
    if (kl > mid)
        return Get(v * 2 + 1, mid + 1, r, kl, kr);
    return Get(v * 2, l, mid, kl, mid) + Get(v * 2 + 1, mid + 1, r, mid + 1, kr);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d\n", &n, &k);
    for (int i = 0; i < k; i++)
    {
        char q;
        int l, r, val;
        scanf("%c%d%d", &q, &l, &r);
        if (q == 'A')
        {
            scanf("%d\n", &val);
            Add(1, 1, n, l, r, val);
        }
        else
        {
            scanf("\n");
            printf("%lld\n", Get(1, 1, n, l, r));
        }
    }
    return 0;
}
