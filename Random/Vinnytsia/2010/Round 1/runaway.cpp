#include <stdio.h>
#include <cstdlib>

using namespace std;

int min(int a, int b, int c, int d)
{
    int i, j;
    if (a < b)
        i = a;
    else
        i = b;
    if (i < c)
        j = i;
    else
        j = c;
    if (j < d)
        return j;
    else
        return d;
}

int main()
{
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    int len = min(n - x, x - 1, y - 1, m - y);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((abs(x - i) <= len) && (y - 1 == len))
            ans++;
        if ((abs(x - i) <= len) && (m - y == len))
            ans++;
    }
    for (int j = 2; j <= m - 1; j++)
    {
        if ((abs(y - j) <= len) && (x - 1 == len))
            ans++;
        if ((abs(y - j) <= len) && (n - x == len))
            ans++;
    }
    printf("%d\n", ans);
    //system("PAUSE");
    return 0;
}
