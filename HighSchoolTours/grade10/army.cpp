#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define nmax 100000

using namespace std;

long long f[12][nmax];
long a[nmax];
long long tree[nmax * 3];

void add(long x, long long val, long l, long r, long v)
{
    if (l == r)
        tree[v] += val;
    else
    {
        int mid = (l + r) / 2;
        tree[v] += val;
        if (x <= mid)
            add(x, val, l, mid, v * 2);
        else
            add(x, val, mid + 1, r, v * 2 + 1);
    }
}

long long sum(long kl, long kr, long l, long r, long v)
{
    if ((kl == l) && (kr == r))
        return tree[v];
    else
    {
        long mid = (l + r) / 2;
        if (kr <= mid)
            return sum(kl, kr, l, mid, v * 2);
        else if (kl > mid)
            return sum(kl, kr, mid + 1, r, v * 2 + 1);
        else
            /*if ((kl<=mid)&&(kr>mid)) */ return sum(kl, mid, l, mid, v * 2) + sum(mid + 1, kr, mid + 1, r, v * 2 + 1);
    }
}

int main()
{
    FILE *fi = fopen("army.dat", "r");
    FILE *fo = fopen("army.sol", "w");
    long n, k;
    fscanf(fi, "%ld %ld", &n, &k);
    memset(f, 0, sizeof(f));
    for (long i = 1; i <= n; i++)
    {
        fscanf(fi, "%ld", &a[i]);
        f[0][i] = 1;
    }
    for (long i = 1; i <= k; i++)
    {
        memset(tree, 0, sizeof(tree));
        for (long j = 1; j <= n; j++)
        {
            add(a[j], f[i - 1][j], 1, n, 1);
            if (a[j] > 1)
                f[i][j] = sum(1, a[j] - 1, 1, n, 1);
            else
                f[i][j] = 0;
        }
    }
    long long s;
    s = 0;
    for (long i = 1; i <= n; i++)
        s += f[k][i];
    fprintf(fo, "%lld\n", s);
    fclose(fi);
    fclose(fo);
    return 0;
}
