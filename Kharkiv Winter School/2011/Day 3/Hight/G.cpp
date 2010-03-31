#include <stdio.h>
#include <cstdlib>

using namespace std;

typedef long long LL;
typedef unsigned long UL;

const char *infile = "input.txt";
const char *outfile = "output.txt";
const UL mm = 1 << 8;
const int mn = 17;

LL F[mm][mm][mn / 2][mn];
int N, M;

int main()
{
    //freopen (infile, "r", stdin); freopen (outfile, "w", stdout);
    scanf("%d%d", &N, &M);
    F[0][0][0][1] = 1;
    UL K1 = 1 << N, K2 = 1 << (N - 1);
    for (int j = 1; j <= M; j++)
    {
        for (int x = 0; x < N; x++)
        {
            for (UL gMask = 0; gMask < K1; gMask++)
            {
                for (UL vMask = 0; vMask < K2; vMask++)
                {
                    if (gMask & (1 << x))
                    {
                        F[gMask ^ (1 << x)][vMask][(x + 1) % N][j + (x + 1) / N] += F[gMask][vMask][x][j];
                    }
                    else
                    {
                        if (!(gMask == 0 && x == 0 && j > 1 && j <= M))
                        {
                            F[gMask | (1 << x)][vMask][(x + 1) % N][j + (x + 1) / N] += F[gMask][vMask][x][j];
                            if (!(gMask & (1 << (x + 1))) && x < N - 1)
                                F[gMask][vMask | (1 << x)][(x + 2) % N][j + (x + 2) / N] += F[gMask][vMask][x][j];
                        }
                    }
                }
            }
        }
    }
    printf("%lld\n", F[0][K2 - 1][0][M + 1]);
    return 0;
}
