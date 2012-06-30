#include <stdio.h>
#include <cstdlib>

using namespace std;

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int n, m, k;
    scanf("%d%d", &n, &k);
    while (n)
    {
        m = k % n;
        k = n + m;
        n = m;
    }
    printf("%d\n", k);
    return 0;
}
