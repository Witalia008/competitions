#include <stdio.h>
#include <cstdlib>
#include <memory.h>

using namespace std;

int n, m;
long long a[55][55];

int main()
{
    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout);
    scanf("%d%d", &n, &m);
    memset(a, 0, sizeof(a));
    a[1][1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= m; j++)
            a[i][j] = a[i - 1][j - 2] + a[i - 2][j - 1];
    printf("%lld\n", a[n][m]);
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }*/
    fclose(stdin);
    fclose(stdout);
    return 0;
}
