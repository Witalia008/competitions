#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define REP(i, n) for (int i = 1; i <= n; i++)

using namespace std;

int f[101][101], a[101][101];
int sol[101];

int main()
{
    FILE *fi = fopen("profit.dat", "r");
    FILE *fo = fopen("profit.res", "w");
    int n, m;
    fscanf(fi, "%d%d", &m, &n);
    REP(i, m)
    REP(j, n)
    fscanf(fi, "%d", &a[i][j]);
    memset(f, 0, sizeof(f));
    memset(sol, 0, sizeof(sol));
    int max;
    REP(i, m)
    REP(j, n)
    {
        max = 0;
        REP(k, n)
        if ((f[m - i][k] > max) && (k != j))
            max = f[m - i][k];
        f[i][j] = max + a[i][j];
        if (f[i][j] < f[i - 1][j])
            f[i][j] = f[i - 1][j];
        if (f[i][j] < f[i][j - 1])
            f[i][j] = f[i][j - 1];
    }
    fprintf(fo, "%d\n", f[m][n]);
    /*REP(i,m)
    {
        REP(j,n)
            fprintf(fo,"%d ",f[i][j]);
        fprintf(fo,"\n");
    }*/
    int ii, jj;
    ii = m;
    jj = n;
    while (f[ii][jj - 1] == f[ii][jj])
        jj--;
    while (f[ii - 1][jj] == f[ii][jj])
        ii--;
    sol[jj] = ii;
    ii = m - ii;
    jj = n;
    while (f[ii][jj - 1] == f[ii][jj])
        jj--;
    while (f[ii - 1][jj] == f[ii][jj])
        ii--;
    sol[jj] += ii;
    REP(i, n - 1)
    fprintf(fo, "%d ", sol[i]);
    fprintf(fo, "%d\n", sol[n]);
    fclose(fi);
    fclose(fo);
    return 0;
}
