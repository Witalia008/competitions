#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, a, b) for (int i = a; i >= b; i--)
#define nmax 30

using namespace std;

int sol[nmax], ans[nmax];
int n, d, h;
bool fl;

void srch(int i, int k, int c)
{
    if (i == h)
    {
        sol[i] = c;
        if ((k == c) && (!fl))
        {
            fl = true;
            FOR(j, 1, n)
            ans[j] = sol[j];
        }
    }
    else
    {
        if (!fl)
        {
            sol[i] = c;
            if (2 * c < k)
                srch(i + 1, k - c, c + 1);
            if ((c - 1 <= k - c) && (c > 1))
                srch(i + 1, k - c, c - 1);
        }
    }
}

int main()
{
    FILE *fi = fopen("input.txt", "r");
    FILE *fo = fopen("output.txt", "w");
    fscanf(fi, "%d %d %d", &n, &d, &h);
    fl = false;
    srch(1, n, d);
    if (!fl)
        fprintf(fo, "0\n");
    else
    {
        FOR(j, 1, h)
        fprintf(fo, "%d\n", ans[j]);
    }
    fclose(fi);
    fclose(fo);
    return 0;
}
