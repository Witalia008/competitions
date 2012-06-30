#include <stdio.h>
#include <cstdlib>
#include <memory.h>

using namespace std;

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int f[130][130];
int a[400];

int main()
{
    FILE *fi = fopen("crazy.dat", "r");
    FILE *fo = fopen("crazy.res", "w");
    int m, k;
    fscanf(fi, "%d%d", &m, &k);
    for (int i = 1; i <= 2 * k + m; i++)
        fscanf(fi, "%d", &a[i]);
    memset(f, 0, sizeof(f));
    bool fl;
    fl = true;
    for (int i = 1; i <= k; i++)
        if (a[2 * i] != 0)
            f[i][0] = f[i - 1][0] + a[2 * i];
        else
            break;
    for (int i = 1; i <= m; i++)
        if (a[i] != 0)
            f[0][i] = f[0][i - 1] + a[i];
        else
            break;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[2 * i + j] == 0)
                f[i][j] = 0;
            else
                f[i][j] = max(f[i - 1][j] + a[2 * i + j], f[i][j - 1] + a[2 * i + j]);
            if ((i > 0) && (j > 0) && (f[i - 1][j] == 0) && (f[i][j - 1] == 0))
                fl = false;
        }
    if (fl)
        fprintf(fo, "%d\n", f[k][m]);
    else
        fprintf(fo, "experiment failed\n");
    fclose(fi);
    fclose(fo);
    return 0;
}
