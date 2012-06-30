#include <cstdlib>
#include <stdio.h>
#include <memory.h>

using namespace std;

long long f[32];

int main(int argc, char *argv[])
{
    freopen("grig.in", "r", stdin);
    freopen("grig.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    memset(f, 0, sizeof(f));
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        int j = i - 1;
        while ((j > 0) && (i - j <= k))
        {
            f[i] += f[j];
            j--;
        }
    }
    printf("%lld\n", f[n]);
    /*for(int i=1;i<=n;i++)
            printf("%lld ",f[i]);*/
    fclose(stdin);
    fclose(stdout);
    return 0;
}
