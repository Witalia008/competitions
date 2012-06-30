#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "game.dat";
const char *outfile = "game.sol";

#define n_max 100

int c[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int ADD[2][8] = {{-1, -1, -1, 0, 1, 1, 1, 0}, {-1, 0, 1, 1, 1, 0, -1, -1}};

int A[n_max][n_max], Ans[n_max][n_max];
int N;

bool good(int x, int y, int ad)
{
    for (int p = 0; p < 8; p++)
        if (A[x + ADD[0][p]][y + ADD[1][p]] % c[(p + ad) % 8] != 0)
            return false;
    return true;
}

void divide(int x, int y, int ad)
{
    for (int p = 0; p < 8; p++)
        A[x + ADD[0][p]][y + ADD[1][p]] /= c[(p + ad) % 8];
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);

    for (int i = 1; i < N - 1; i++)
        for (int j = 1; j < N - 1; j++)
            for (int k = 3; k >= 0; k--)
                while (good(i, j, k * 2))
                    divide(i, j, k * 2), Ans[i][j]++;

    for (int i = 0; i < N; i++)
    {
        printf("%d", Ans[i][0]);
        for (int j = 1; j < N; j++)
            printf(" %d", Ans[i][j]);
        printf("\n");
    }

    return 0;
}
