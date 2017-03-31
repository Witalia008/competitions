/* GCC */
#include <stdio.h>
#include <cstdlib>

using namespace std;

int main()
{
    freopen("kfc.in", "r", stdin);
    freopen("kfc.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int ans = 1;
    int pre = 1;
    n--;
    while (n > 0)
    {
        pre += 2;
        n -= pre;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
