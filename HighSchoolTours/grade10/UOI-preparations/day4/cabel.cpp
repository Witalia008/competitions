#include <stdio.h>
#include <cstdlib>
#include <vector>

using namespace std;

#define nmax 100000

struct mas
{
    int n[8];
};

struct TTree
{
    mas stat;
};

TTree tree[nmax * 4];
int L, N;
mas M;

mas merge(mas &a, mas &b)
{
    mas x;
    if (a.n[0] == 0)
        for (int i = 0; i < 8; i++)
            a.n[i] = i + 1;
    if (b.n[0] == 0)
        for (int i = 0; i < 8; i++)
            b.n[i] = i + 1;
    for (int i = 0; i < 8; i++)
        x.n[i] = b.n[a.n[i] - 1];
    return x;
}

void replace(int x, int v, int l, int r)
{
    if (l == r)
        tree[v].stat = M;
    else
    {
        int mid = (l + r) / 2;
        if (x <= mid)
            replace(x, v * 2, l, mid);
        else
            replace(x, v * 2 + 1, mid + 1, r);
        tree[v].stat = merge(tree[v * 2].stat, tree[v * 2 + 1].stat);
    }
}

mas get(int kl, int kr, int l, int r, int v)
{
    if (kl == l && kr == r)
    {
        if (tree[v].stat.n[0] == 0)
            for (int i = 0; i < 8; i++)
                tree[v].stat.n[i] = i + 1;
        return tree[v].stat;
    }
    int mid = (l + r) / 2;
    if (kr <= mid)
        return get(kl, kr, l, mid, v * 2);
    if (kl > mid)
        return get(kl, kr, mid + 1, r, v * 2 + 1);
    mas a = get(kl, mid, l, mid, v * 2);
    mas b = get(mid + 1, kr, mid + 1, r, v * 2 + 1);
    return merge(a, b);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d\n", &L, &N);
    for (int i = 1; i <= N; i++)
    {
        char what;
        scanf("%c", &what);
        if (what == 'S')
        {
            int m;
            scanf("%d", &m);
            for (int j = 0; j < 8; j++)
                scanf("%d", &M.n[j]);
            scanf("\n");
            replace(m, 1, 1, L);
        }
        else
        {
            int p, q;
            scanf("%d%d\n", &p, &q);
            M = get(p + 1, q, 1, L, 1);
            for (int j = 0; j < 8; j++)
                for (int k = 0; k < 8; k++)
                    if (M.n[k] == j + 1)
                        printf("%d", k + 1);
            printf("\n");
        }
    }
    return 0;
}
