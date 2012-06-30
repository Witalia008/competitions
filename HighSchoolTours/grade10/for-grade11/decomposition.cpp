#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define nmax 500

using namespace std;

int A[nmax + 1][nmax + 1], F[nmax + 1][nmax + 1], f[nmax + 1], queue[nmax * nmax], Sol[nmax * 5][nmax + 2];
int n, m, top;
bool fl;

int main()
{
    freopen("decomposition.in", "r", stdin);
    freopen("decomposition.out", "w", stdout);
    scanf("%d%d", &n, &m);
    memset(A, 0, sizeof(A));
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        A[a][b] = c;
    }
    top = 0;
    memset(F, 0, sizeof(F));
    while (true)
    {
        int H = 1, T = 2;
        queue[1] = 1;
        memset(f, -1, sizeof(f));
        f[1] = 0;
        while (H < T)
        {
            int v = queue[H];
            H++;
            for (int j = 1; j <= n; j++)
                if (f[j] == -1 && A[v][j] - F[v][j] > 0)
                {
                    queue[T] = j;
                    T++;
                    f[j] = v;
                }
        }
        if (f[n] == -1)
            break;
        top++;
        Sol[top][0] = 0;
        int c = n;
        int M = 1000000000;
        c = n;
        while (c > 1)
        {
            if (A[f[c]][c] - F[f[c]][c] < M)
                M = A[f[c]][c];
            c = f[c];
        }
        c = n;
        while (c > 1)
        {
            Sol[top][0]++;
            Sol[top][Sol[top][0]] = c;
            F[f[c]][c] += M;
            F[c][f[c]] -= M;
            c = f[c];
        }
        Sol[top][nmax + 1] = M;
    }
    /*long long ans=0;
	for (int i=1;i<=n;i++)
		ans+=F[1][i];
	printf("%lld\n",ans);*/
    printf("%d\n", top);
    for (int i = 1; i <= top; i++)
    {
        printf("%d", Sol[i][nmax + 1]);
        for (int j = Sol[i][0]; j >= 1; j--)
            printf(" %d", Sol[i][j]);
        printf("\n");
    }
    return 0;
}
