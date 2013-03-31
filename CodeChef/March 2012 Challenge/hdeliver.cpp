#include <stdio.h>
#include <cstdlib>
#include <memory.h>

using namespace std;

const char *infile = "hdeliver.in";
const char *outfile = "hdeliver.out";

#define NMAX 101

int D[NMAX][NMAX];

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        int N, M;
        scanf("%d%d", &N, &M);
        memset(D, 0, sizeof(D));
        for (int i = 0; i < M; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            D[a][b] = D[b][a] = 1;
        }
        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    if (!D[i][j])
                        D[i][j] = (D[i][k] && D[k][j]);
        int Q;
        scanf("%d", &Q);
        for (int i = 0; i < Q; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x == y || D[x][y] || D[y][x])
                printf("YO\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
