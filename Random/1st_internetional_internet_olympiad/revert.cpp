/* GCC */
#include <stdio.h>
#include <cstdlib>

using namespace std;

int main()
{
    freopen("revert.in", "r", stdin);
    freopen("revert.out", "w", stdout);
    int n;
    scanf("%d", &n);
    if (n == 0)
        printf("0");
    while (n)
    {
        printf("%d", n % 10);
        n /= 10;
    }
    printf("\n");
    return 0;
}
