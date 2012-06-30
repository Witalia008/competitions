#include <stdio.h>
#include <cstdlib>
#include <fstream>

using namespace std;

typedef unsigned long long ULL;

const char *infile = "filing.in";
const char *outfile = "filing.out";
const int mm = 1 << 8;
const int mn = 17;

ULL F[mm][mm][mn / 2][mn];
int N, M;

int main()
{
    //freopen (infile, "r", stdin); freopen (outfile, "w", stdout);
    ifstream fin(infile);
    ofstream fout(outfile);
    //scanf ("%d%d", &N, &M);
    fin >> N >> M;
    F[0][0][0][1] = 1;
    int K1 = 1 << N, K2 = 1 << (N - 1);
    for (int j = 1; j <= M; j++)
    {
        for (int x = 0; x < N; x++)
        {
            for (int gMask = 0; gMask < K1; gMask++)
            {
                for (int vMask = 0; vMask < K2; vMask++)
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
    //printf ("%d\n", F[0][K2 - 1][0][M + 1]);
    fout << F[0][K2 - 1][0][M + 1] << endl;
    return 0;
}
