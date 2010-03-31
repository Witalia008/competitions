#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define INF 1000000000
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int A[560][560], n, S[560], s, a[560];
bool used[560];

void bfs(int i, int j, int sj)
{
    used[i] = true;
    if (i == n)
    {
        if (j == 0)
            j++;
        if (a[n] + sj + A[j][n] < s)
            s = a[n] + sj + A[j][n];
        return;
    }
    For(k, i + 1, n)
    {
        if (a[i] + A[i][k] < a[k])
        {
            a[k] = a[i] + A[i][k];
            bool fl = false;
            int x = j + 1;
            while (x <= k - 1)
            {
                if (!used[x])
                    fl = true;
                x++;
            }
            if (!fl)
                bfs(k, j, sj);
            else
            {
                if (j == 0)
                    j++;
                int x = j + 1;
                while (!used[x])
                    x++;
                x = A[j][x] + S[k - 1] - S[x];
                bfs(k, k - 1, sj + x);
            }
        }
    }
    used[i] = false;
}

int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    scanf("%d", &n);
    For(i, 1, n - 1)
        For(j, i + 1, n)
            scanf("%d", &A[i][j]);
    memset(S, 0, sizeof(S));
    For(i, 2, n)
        S[i] = S[i - 1] + A[i - 1][i];
    printf("%d ", S[n]);
    s = INF;
    For(i, 2, n)
        a[i] = INF;
    a[1] = 0;
    memset(used, 0, sizeof(used));
    bfs(1, 0, 0);
    printf("%d\n", s);
    return 0;
}
