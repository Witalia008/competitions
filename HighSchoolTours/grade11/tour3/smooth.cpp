#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "smooth.in";
const char *outfile = "smooth.out";
const int nmax = 2001;
const int cyfr = 10;
const long long mod = 1000000007;

typedef long long LL;

int N;
LL F[nmax][cyfr];
LL ans;

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d", &N);
    for (int i = 1; i < cyfr; i++)
        F[1][i] = 1;
    for (int n = 1; n < N; n++)
        for (int i = 0; i < cyfr; i++)
        {
            F[n + 1][i] = (F[n + 1][i] + F[n][i]) % mod;
            if (i)
                F[n + 1][i - 1] = (F[n + 1][i - 1] + F[n][i]) % mod;
            if (i < cyfr - 1)
                F[n + 1][i + 1] = (F[n + 1][i + 1] + F[n][i]) % mod;
        }
    for (int i = 0; i < cyfr; i++)
        ans = (ans + F[N][i]) % mod;
    printf("%d\n", ans);
    return 0;
}
