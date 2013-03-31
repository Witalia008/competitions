#include <stdio.h>
#include <cstdlib>

using namespace std;

#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define N 70

int n, m, r;
int W[N][N][N], ans[N][N][N];

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &r);
    for (int l = 0; l < m; l++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &W[i][j][l]);
    for (int l = 0; l < m; l++)
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    W[i][j][l] = min(W[i][j][l], W[i][k][l] + W[k][j][l]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k <= n; k++)
                ans[i][j][k] = Inf;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            ans[i][j][0] = Inf;
            for (int l = 0; l < m; l++)
                ans[i][j][0] = min(ans[i][j][0], W[i][j][l]);
        }
    for (int k = 1; k <= n; k++)
        for (int l = 0; l < n; l++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    ans[i][j][k] = min(ans[i][l][k - 1] + ans[l][j][0], ans[i][j][k]);
    for (int i = 0; i < r; i++)
    {
        int si, ti, ki;
        scanf("%d%d%d", &si, &ti, &ki);
        --si;
        --ti;
        if (ki > n)
            ki = n;
        printf("%d\n", ans[si][ti][ki]);
    }
    return 0;
}
