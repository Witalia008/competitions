#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1000000], b[1000000];

int main()
{
    FILE *fi = fopen("input.txt", "r");
    FILE *fo = fopen("output.txt", "w");
    int n, m, l, r;
    fscanf(fi, "%d\n", &n);
    for (int i = 1; i <= n; i++)
    {
        fscanf(fi, "%d", &a[i]);
    }
    fscanf(fi, "%d\n", &m);
    b[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        b[i] = a[i] + b[i - 1];
    }
    for (int i = 1; i <= m; i++)
    {
        fscanf(fi, "%d%d\n", &l, &r);
        fprintf(fo, "%d\n", b[r] - b[l] + a[l]);
    }
    fclose(fi);
    fclose(fo);
    return 0;
}
