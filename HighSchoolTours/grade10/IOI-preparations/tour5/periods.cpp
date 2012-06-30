#include <stdio.h>
#include <cstdlib>

using namespace std;

#define Inf 100000000
#define N 1000005

int n, k;
char s[N];
int p[N];
long long res;

int main()
{
    freopen("periods.in", "r", stdin);
    freopen("periods.out", "w", stdout);
    scanf("%d\n", &n);
    scanf("%s", &s);
    for (int i = 1; i < n; i++)
    {
        while (k && s[i] != s[k])
            k = p[k];
        if (s[i] == s[k])
            k++;
        p[i + 1] = k;
    }
    for (int i = 1; i <= n; i++)
    {
        int prev = 0, now = p[i];
        while (now)
        {
            prev = now;
            now = p[now];
        }
        p[i] = prev;
        if (prev)
            res += i - prev;
    }
    printf("%lld\n", res);
    return 0;
}
