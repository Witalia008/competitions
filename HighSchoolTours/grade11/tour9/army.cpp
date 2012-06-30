#include <stdio.h>
#include <cstdlib>
#include <memory.h>

using namespace std;

const char *infile = "army.dat";
const char *outfile = "army.sol";
const int nmax = 100000;

int N, K;
int A[nmax];
long long Ans[2][nmax], t[nmax];

void Inc(int i, long long val)
{
    for (; i < N; i = i | (i + 1))
        t[i] += val;
}

long long Sum(int r)
{
    long long res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        res += t[r];
    return res;
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for (int i = 0; i < N; i++)
        Ans[0][i] = 1;

    for (int k = 1; k <= K; k++)
    {
        memset(t, 0, sizeof(t));
        Ans[(k & 1)][0] = 0;
        for (int i = 1; i < N; i++)
        {
            Inc(A[i - 1], Ans[!(k & 1)][i - 1]);
            Ans[(k & 1)][i] = Sum(A[i] - 1);
        }
    }
    long long ans = 0;
    for (int i = 0; i < N; i++)
        ans += Ans[(K & 1)][i];
    printf("%lld\n", ans);
    return 0;
}
