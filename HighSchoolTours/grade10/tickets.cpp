#include <stdio.h>
#include <cstdlib>
#include <memory.h>

using namespace std;

long long min(long long a, long long b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    FILE *fi = fopen("tickets.in", "r");
    FILE *fo = fopen("tickets.out", "w");
    long n;
    long long a[5000], b[5000], c[5000];
    long long f[5000];
    fscanf(fi, "%ld", &n);
    for (long i = 1; i <= n; i++)
        fscanf(fi, "%lld%lld%lld", &a[i], &b[i], &c[i]);
    memset(f, 0, sizeof(f));
    f[1] = a[1];
    f[2] = min(f[1] + a[2], b[1]);
    for (long i = 3; i <= n; i++)
        f[i] = min(min(f[i - 1] + a[i], f[i - 2] + b[i - 1]), f[i - 3] + c[i - 2]);
    fprintf(fo, "%lld\n", f[n]);
    fclose(fi);
    fclose(fo);
    return 0;
}
