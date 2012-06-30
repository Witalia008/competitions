#include <stdio.h>
#include <cstdlib>
#include <fstream>

using namespace std;

#define maxn 6
#define maxm 100
#define maxmask (1 << maxn)

ifstream cin("water.dat");
ofstream cout("water.sol");

int N, M, P;
bool A[maxn + 1][maxm + 1];
int F[2][maxn][maxmask];

void push(int &f, int val)
{
    f += val;
    f %= P;
}

int main()
{
    cin >> N >> M >> P;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> A[i][j];

    F[0][0][0] = 1;
    int K = (1 << N);
    for (int i = 0; i < M; i++)
    {
        memset(F[1 - i % 2], 0, sizeof(F[1 - i % 2]));
        for (int x = 0; x < N; x++)
            for (int mask = 0; mask < K; mask++)
            {
                bool fl = true;
                for (int X = 0; X < N; X++)
                    if ((mask >> X) % 2 && A[X + 1][i + 1])
                        fl = false;
                if (F[i % 2][x][mask] == 0)
                    fl = false;
                if (fl)
                {
                    //we put in current position only one funnel
                    if (!A[x + 1][i + 1])
                        if (!((mask >> x) % 2))
                            push(F[(i + (x + 1) / N) % 2][(x + 1) % N][mask], F[i % 2][x][mask]);
                    //we put funnel between two flowers vertical
                    if (x < N - 1 && !((mask >> x) % 2) && !((mask >> (x + 1)) % 2))
                        if (A[x + 1][i + 1] != 1 && A[x + 2][i + 1] != 1)
                            push(F[(i + (x + 1) / N) % 2][(x + 1) % N][mask + (1 << (x + 1))], F[i % 2][x][mask]);
                    //we put funnel between two fowers gorizontal
                    if (i < M - 1 && !((mask >> x) % 2))
                        if (!A[x + 1][i + 1] && !A[x + 1][i + 2])
                            push(F[(i + (x + 1) / N) % 2][(x + 1) % N][mask + (1 << x)], F[i % 2][x][mask]);
                    //we put between four flowers
                    if (i < M - 1 && x < N - 1 && !A[x + 1][i + 1] && !A[x + 1][i + 2] && !A[x + 2][i + 1] && !A[x + 2][i + 2])
                        if (!((mask >> x) % 2) && !((mask >> (x + 1)) % 2))
                            push(F[(i + (x + 2) / N) % 2][(x + 2) % N][mask + (1 << x) + (1 << (x + 1))], F[i % 2][x][mask]);
                    //if we must add funnel
                    if ((mask >> x) % 2)
                        push(F[(i + (x + 1) / N) % 2][(x + 1) % N][mask - (1 << x)], F[i % 2][x][mask]);
                    //if here is a platform
                    if (A[x + 1][i + 1])
                        push(F[(i + (x + 1) / N) % 2][(x + 1) % N][mask], F[i % 2][x][mask]);
                }
            }
    }

    cout << F[M % 2][0][0] << endl;
    return 0;
}
