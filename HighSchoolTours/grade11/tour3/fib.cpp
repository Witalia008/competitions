#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "fib.in";
const char *outfile = "fib.out";
const int nmax = 45;

typedef long long LL;

int N;
LL f[nmax];
LL k;

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    f[0] = 1;
    f[1] = 2;
    scanf("%d%lld", &N, &k);
    for (int i = 2; i <= N; i++)
        f[i] = f[i - 1] + f[i - 2];
    for (int i = 1; i <= N; i++)
        if (f[N - i] >= k)
            printf("0");
        else
        {
            printf("1");
            k -= f[N - i];
        }
    printf("\n");
    return 0;
}
