#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;
int F, E, N, A;
int Max[100001], Min[100001];
int W[501], P[501];

int main()
{
    freopen("piggy.in", "r", stdin);
    freopen("piggy.out", "w", stdout);
    scanf("%d%d", &E, &F);
    A = F - E;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d%d", &P[i], &W[i]);
    for (int i = 1; i <= A; i++)
    {
        Max[i] = -1;
        Min[i] = -1;
    }
    Max[0] = 0;
    Min[0] = 0;
    for (int i = 1; i <= A; i++)
    {
        for (int j = 1; j <= N; j++)
            if (i - W[j] >= 0 && Max[i - W[j]] != -1)
            {
                if (Max[i] == -1 || Max[i] < Max[i - W[j]] + P[j])
                    Max[i] = Max[i - W[j]] + P[j];
                if (Min[i] == -1 || Min[i] > Min[i - W[j]] + P[j])
                    Min[i] = Min[i - W[j]] + P[j];
            }
    }
    if (Max[A] == -1)
        printf("This is impossible.\n");
    else
        printf("%d %d\n", Min[A], Max[A]);
    return 0;
}
