#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;
int a[10005];

int cou(long long c, int n)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += a[i] / c;
    return ans;
}

int main()
{
    freopen("ropes.in", "r", stdin);
    freopen("ropes.out", "w", stdout);
    int n, k;
    long long max = 0, s = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > max)
            max = a[i];
        s += a[i];
    }
    if (s < k)
        printf("0\n");
    else
    {
        long long l = 1, r = max;
        while (l != r - 1)
        {
            long long mid = (l + r) / 2;
            if (cou(mid, n) < k)
                r = mid;
            else
                l = mid;
        }
        if (cou(l, n) > cou(r, n))
            printf("%d\n", l);
        else
            printf("%d\n", r);
    }
    return 0;
}
