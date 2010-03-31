/* GCC */
#include <stdio.h>
#include <cstdlib>

using namespace std;

int main()
{
    freopen("shares.in", "r", stdin);
    freopen("shares.out", "w", stdout);
    int n, s;
    scanf("%d%d", &n, &s);
    printf("%d\n", s / (n + 1));
    return 0;
}
