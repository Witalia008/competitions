#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "input.txt";
const char *outfile = "output.txt";

#define bit(x) (1 << x)
#define n_max 1001001
#define k_max 10

int A[n_max];
int p[k_max], n[k_max], d[k_max], L[k_max], R[k_max];
int _2k, K, i, Ans;

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d", &K);
    _2k = bit(K);
    for (i = 0; i < K; i++)
        scanf("%d", &n[K - 1 - i]);

    p[0] = 1;
    for (i = 0; i < K; i++)
        p[i + 1] = p[i] * n[i];

    for (int j = 0; j < p[K]; j++)
    {
        scanf("%d", &A[j]);
        for (i = 0; i < K; i++)
            d[i] = j / p[i] % n[i];

        for (int mask = 1; mask < _2k; mask++)
        {
            int sign = 1, jj = 0;
            for (i = 0; i < K; i++)
                if (!(mask & bit(i)))
                {
                    jj += d[i] * p[i];
                }
                else
                {
                    sign = -sign;
                    if (d[i] > 0)
                        jj += (d[i] - 1) * p[i];
                    else
                        break;
                }
            if (i == K)
                A[j] -= sign * A[jj];
        }
    }
    int q;
    scanf("%d", &q);
    for (int j = 0; j < q; j++)
    {
        for (i = 0; i < K; i++)
        {
            scanf("%d", &L[K - 1 - i]);
            L[K - 1 - i] -= 2;
        }
        for (i = 0; i < K; i++)
        {
            scanf("%d", &R[K - 1 - i]);
            R[K - 1 - i]--;
        }
        Ans = 0;
        for (int mask = 0; mask < _2k; mask++)
        {
            int jj = 0, sign = 1;
            for (i = 0; i < K; i++)
                if (!(mask & bit(i)))
                    jj += R[i] * p[i];
                else
                {
                    sign = -sign;
                    if (L[i] >= 0)
                        jj += L[i] * p[i];
                    else
                        break;
                }
            if (i == K)
                Ans += A[jj] * sign;
        }
        printf("%d\n", Ans);
    }
    return 0;
}
