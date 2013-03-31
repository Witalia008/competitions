#include <stdio.h>
#include <cstdlib>

#define max(a, b) (a > b) ? (a) : (b)

using namespace std;

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    if (!n)
    {
        if (m)
            printf("Impossible\n");
        else
            printf("0 0\n");
        return 0;
    }
    if (m)
        printf("%d %d\n", max(m, n), n + m - 1);
    else
        printf("%d %d\n", n, n);
    return 0;
}
