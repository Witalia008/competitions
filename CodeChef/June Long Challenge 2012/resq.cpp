#include <stdio.h>
#include <cstdlib>
#include <math.h>

using namespace std;

int Abs(int a)
{
    if (a < 0)
        return -a;
    return a;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int _t = 0; _t < t; _t++)
    {
        int n;
        scanf("%d", &n);
        int ans = n - 1;
        for (int i = 2; i <= int(sqrt(1.0 * n)); i++)
            if ((n % i == 0) && Abs(n / i - i) < ans)
                ans = abs(n / i - i);
        printf("%d\n", ans);
    }
    return 0;
}
