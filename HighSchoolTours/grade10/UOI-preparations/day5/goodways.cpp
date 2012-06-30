#include <stdio.h>
#include <cstdlib>

using namespace std;

#define nmax 200
#define max(a, b) ((a > b) ? a : b)

/*int max (int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}*/

int N, M, K;
int A[nmax + 1][nmax + 1], F[nmax + 1][nmax + 1];
int G[nmax + 1][nmax + 1][nmax + 1];

int main()
{
    freopen("goodways.dat", "r", stdin);
    freopen("goodways.sol", "w", stdout);

    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            scanf("%d", &A[i][j]);
            F[i][j] = max(F[i - 1][j], F[i][j - 1]) + A[i][j];
        }

    G[1][1][0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            for (int k = 0; k <= K; k++)
            {
                if (i < N)
                    if (F[i + 1][j] - (F[i][j] - k + A[i + 1][j]) <= K)
                        G[i + 1][j][F[i + 1][j] - (F[i][j] - k + A[i + 1][j])] += G[i][j][k];
                if (j < M)
                    if (F[i][j + 1] - (F[i][j] - k + A[i][j + 1]) <= K)
                        G[i][j + 1][F[i][j + 1] - (F[i][j] - k + A[i][j + 1])] += G[i][j][k];
            }

    int ans = 0;
    for (int i = 0; i <= K; i++)
        ans += G[N][M][i];

    printf("%d\n%d\n", F[N][M], ans);
    return 0;
}
