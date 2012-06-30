#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int SG[105][105];
int f[105], a[105], b[105];

int main()
{
    freopen("choco.dat", "r", stdin);
    freopen("choco.res", "w", stdout);
    int n;
    scanf("%d", &n);
    memset(SG, 0, sizeof(SG));
    for (int i = 1; i <= 100; i++)
        for (int j = i; j <= 100; j++)
        {
            int k;
            memset(f, 0, sizeof(f));
            for (k = 1; k < j; k++)
                f[SG[i][k] ^ SG[i][j - k]] = 1;
            for (k = 1; k < i; k++)
                f[SG[k][j] ^ SG[i - k][j]] = 1;
            for (k = 1; k < j - 1; k++)
                f[SG[i][k] ^ SG[i][j - k - 1]] = 1;
            for (k = 1; k < i - 1; k++)
                f[SG[k][j] ^ SG[i - k - 1][j]] = 1;
            if (i > 2 && j > 2)
                f[SG[i - 2][j - 2]] = 1;
            for (k = 0; f[k] == 1; k++)
                ;
            SG[i][j] = k;
            SG[j][i] = k;
        }
    int res = 0;
    for (int c = 1; c <= n; c++)
    {
        scanf("%d%d", &a[c], &b[c]);
        res = res ^ SG[a[c]][b[c]];
    }
    int ans = 0;
    for (int c = 1; c <= n; c++)
    {
        int k;
        int i = a[c], j = b[c];
        for (k = 1; k < j; k++)
            if ((((res ^ SG[i][j]) ^ SG[i][k]) ^ SG[i][j - k]) == 0)
                ans++;
        for (k = 1; k < i; k++)
            if ((((res ^ SG[k][j]) ^ SG[i - k][j]) ^ SG[i][j]) == 0)
                ans++;
        for (k = 1; k < j - 1; k++)
            if ((((res ^ SG[i][k]) ^ SG[i][j - k - 1]) ^ SG[i][j]) == 0)
                ans++;
        for (k = 1; k < i - 1; k++)
            if ((((res ^ SG[k][j]) ^ SG[i - k - 1][j]) ^ SG[i][j]) == 0)
                ans++;
        if (i > 2 && j > 2)
            if (((res ^ SG[i - 2][j - 2]) ^ SG[i][j]) == 0)
                ans++;
    }
    printf("%d\n", ans);
    return 0;
}
