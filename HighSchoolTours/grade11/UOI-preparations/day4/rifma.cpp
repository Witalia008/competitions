#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

const char *infile = "rifma.in";
const char *outfile = "rifma.out";

long long f[27], g[27][27];

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    int N;
    scanf("%d", &N);
    for (int i = 0; i <= N; i++)
        g[i][i] = 1;
    for (int n = 1; n <= N; n++)
        for (int k = 1; k < n; k++)
            for (int j = k - 1; j < n; j++)
                g[n][k] += g[j][k - 1];
    f[0] = 1;
    for (int n = 1; n <= N; n++)
        for (int j = 2; j <= n; j++)
            f[n] += f[n - j] * g[n][j];
    cout << f[N] << endl;
    return 0;
}
