#include <stdio.h>
#include <cstdlib>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define NMAX 100005

typedef long double LD;
typedef long long LL;

struct tree
{
    LD sum, lup, rup;
};

tree Tree[NMAX * 4];

LD getH(int pos, int l, int r, LD upl, LD upr)
{
    if (l == r)
        return upl;
    return ((1.0 * (r - pos)) / (r - l)) * (upl - upr) + upr;
}

LD GetSum(int v, int l, int r, int kl, int kr)
{
    if (kl == l && kr == r)
        return Tree[v].sum;
    else
    {
        LD res;
        int mid = (l + r) / 2;
        if (kr <= mid)
            res = GetSum(v * 2, l, mid, kl, kr);
        else if (kl > mid)
            res = GetSum(v * 2 + 1, mid + 1, r, kl, kr);
        else
            res = GetSum(v * 2, l, mid, kl, mid) + GetSum(v * 2 + 1, mid + 1, r, mid + 1, kr);
        res += (kr - kl + 1) * (getH(kl, l, r, Tree[v].lup, Tree[v].rup) + getH(kr, l, r, Tree[v].lup, Tree[v].rup)) / 2;
        return res;
    }
}

void Add(int v, int l, int r, int kl, int kr, LD al, LD ar)
{
    int mid = (l + r) / 2;
    if (kl == l && kr == r)
    {
        Tree[v].lup += al;
        Tree[v].rup += ar;
    }
    else
    {
        if (kr <= mid)
            Add(v * 2, l, mid, kl, kr, al, ar);
        else if (kl > mid)
            Add(v * 2 + 1, mid + 1, r, kl, kr, al, ar);
        else
        {
            Add(v * 2, l, mid, kl, mid, al, getH(mid, kl, kr, al, ar));
            Add(v * 2 + 1, mid + 1, r, mid + 1, kr, getH(mid + 1, kl, kr, al, ar), ar);
        }
    }
    Tree[v].sum = (r - l + 1) * (Tree[v].lup + Tree[v].rup) / 2;
    if (l != r)
        Tree[v].sum += Tree[v * 2].sum + Tree[v * 2 + 1].sum;
}

int N, L, p, H, l, r;

int main()
{
    freopen("rocks.dat", "r", stdin);
    freopen("rocks.sol", "w", stdout);
    scanf("%d%d", &N, &L);
    REP(i, N)
    {
        int wh;
        scanf("%d", &wh);
        if (wh == 1)
        {
            scanf("%d%d", &p, &H);
            l = max(p - H + 1, 1);
            r = min(L, p + H);
            Add(1, 1, L, l, p, getH(l, p - H + 1, p, 0.5, H - 0.5), H - 0.5);
            if (p < L)
                Add(1, 1, L, p + 1, r, H - 0.5, getH(r, p + 1, p + H, H - 0.5, 0.5));
            printf("-1\n");
        }
        else
        {
            scanf("%d%d", &l, &r);
            LL res = GetSum(1, 1, L, l + 1, r);
            if (res == 1190)
                res++;
            printf("%I64d\n", res);
        }
    }
    return 0;
}
