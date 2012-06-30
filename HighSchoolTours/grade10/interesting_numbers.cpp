#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, a, b) for (int i = a; i >= b; i--)
#define nmax 30

using namespace std;

int a[nmax + 1];

bool good()
{
    int b[nmax + 1], c[nmax + 1];
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    int i;
    i = 1;
    while (a[i] == 0)
        i++;
    b[i] = a[nmax];
    FOR(j, i + 1, nmax)
    b[j] = a[j - 1];
    int p;
    p = 0;
    REP(j, nmax, 1)
    {
        int s;
        s = a[j] * a[nmax] + p;
        p = s / 10;
        c[j] = s % 10;
    }
    i = 1;
    while ((b[i] == c[i]) && (i <= nmax))
        i++;
    if (i > nmax)
        return true;
    else
        return false;
}

int main()
{
    FILE *fi = fopen("input.txt", "r");
    FILE *fo = fopen("output.txt", "w");
    FOR(i, 2, 9)
    {
        memset(a, 0, sizeof(a));
        a[nmax] = i;
        int p;
        p = 0;
        int j;
        j = nmax - 1;
        while (j >= 1)
        {
            a[j] = (a[j + 1] * i + p) % 10;
            p = (a[j + 1] * i + p) / 10;
            if ((good()) && (p == 0))
                break;
        }
        p = 1;
        while (a[p] == 0)
            p++;
        FOR(j, p, nmax)
        fprintf(fo, "%d", a[j]);
        fprintf(fo, "\n");
    }
    fclose(fi);
    fclose(fo);
    return 0;
}
