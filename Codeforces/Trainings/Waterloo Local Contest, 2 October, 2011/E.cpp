#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define Inf 2000000000
#define CMAX 25
#define TMAX 1000

int Abs(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

struct TEvent
{
    int pos, energy;
};

TEvent A[CMAX][TMAX];
int Ans[CMAX][TMAX];
int Z, C, T, L;

int main()
{
    scanf("%d", &Z);
    for (int z = 0; z < Z; z++)
    {
        scanf("%d%d%d", &C, &T, &L);
        for (int i = 0; i < C; i++)
            for (int j = 0; j < T; j++)
                scanf("%d%d", &A[i][j].pos, &A[i][j].energy);
        for (int j = 0; j < T; j++)
            Ans[0][j] = A[0][j].pos + A[0][j].energy;
        for (int i = 1; i < C; i++)
            for (int j = 0; j < T; j++)
            {
                Ans[i][j] = Inf;
                for (int k = 0; k < T; k++)
                    Ans[i][j] = min(Ans[i][j], Ans[i - 1][k] + Abs(A[i - 1][k].pos - A[i][j].pos));
                Ans[i][j] += A[i][j].energy;
            }
        int ans = Inf;
        for (int j = 0; j < T; j++)
            ans = min(ans, Ans[C - 1][j] + L - A[C - 1][j].pos);
        printf("%d\n", ans);
    }
    return 0;
}
