#include <stdio.h>
#include <cstdlib>
#include <math.h>

using namespace std;

#define k_max 98
#define m_max 9876
#define n_max 987654
#define rn_max 1000
#define Inf 1000000

int K, M, a, nm, krN;
int A[m_max], pows[rn_max];
int F[n_max + 1];

int main()
{
    scanf("%d%d", &K, &M);
    if (K == 1)
    {
        for (int i = 1; i < M; i++)
            printf("1 ");
        printf("1\n");
        return 0;
    }

    nm = 1;
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &A[i]);
        if (A[i] > nm)
            nm = A[i];
    }

    krN = int(pow(double(nm), 1.0 / K));
    for (int i = 1; i <= krN; i++)
        pows[i] = int(pow(double(i), K));

    for (int n = 1; n <= nm; n++)
    {
        F[n] = Inf;
        for (int j = 1; j <= krN && pows[j] <= n; j++)
            if (F[n - pows[j]] < F[n])
                F[n] = F[n - pows[j]];
        F[n]++;
    }

    for (int i = 0; i < M; i++)
    {
        printf("%d", F[A[i]]);
        if (i == M - 1)
            printf("\n");
        else
            printf(" ");
    }
    return 0;
}
