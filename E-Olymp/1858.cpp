#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "input.txt";
const char *outfile = "output.txt";

long long f[27];
long long g[27][27];

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    //ifstream fin (infile); ofstream fout (outfile);
    int N;
    scanf("%d", &N);
    for (int i = 0; i <= N; i++)
        g[i][i] = 1;
    for (int n = 1; n <= N; n++)
    {
        for (int k = 1; k < n; k++)
        {
            g[n][k] = 0;
            for (int j = k - 1; j < n; j++)
                g[n][k] += g[j][k - 1];
        }
    }

    f[0] = 1;
    for (int n = 1; n <= N; n++)
    {
        f[n] = 0;
        for (int j = 2; j <= n; j++)
            f[n] += f[n - j] * g[n][j];
    }
    printf("%lld\n", f[N]);
    return 0;
}
