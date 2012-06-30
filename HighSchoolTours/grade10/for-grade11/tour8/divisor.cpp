#include <stdio.h>
#include <cstdlib>
#define For(i, a, b) for (int i = a; i <= b; i++)
#include <memory.h>

using namespace std;

int main()
{
    freopen("divisor.dat", "r", stdin);
    freopen("divisor.sol", "w", stdout);
    int n;
    scanf("%d", &n);
    int c[50];
    int pr[15] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};
    memset(c, 0, sizeof(c));
    For(i, 2, n)
    {
        int nn = i;
        For(j, 1, 15)
        {
            while (nn % pr[j] == 0)
            {
                nn /= pr[j];
                c[pr[j]]++;
            }
        }
    }
    int ans = 1;
    For(i, 1, 45)
        ans *= (c[i] + 1);
    printf("%d\n", ans);
    return 0;
}
