#include <stdio.h>
#include <cstdlib>

using namespace std;

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    long long k, l;
    scanf("%I64d%I64d", &k, &l);
    long long x = k;
    int ans = 0;
    while (x < l)
    {
        x *= k;
        ans++;
    }
    if (x == l)
        printf("YES\n%d\n", ans);
    else
        printf("NO\n");
    return 0;
}
