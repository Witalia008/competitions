#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

long long f[70], g[70];

int main()
{
    freopen("ones.in", "r", stdin);
    freopen("ones.out", "w", stdout);
    int n;
    scanf("%d", &n);
    f[1] = 1;
    f[2] = 2;
    g[1] = 1;
    g[2] = 2;
    FOR(i, 3, n)
    {
        g[i] = f[i - 1] + g[i - 1];
        f[i] = 2 * g[i - 2] + f[i - 2];
    }
    printf("%lld\n", f[n] + g[n]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
