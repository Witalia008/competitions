#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef unsigned long long ll;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define InfL Inf *Inf
#define N 1000005

int k;
char a[N];

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    scanf("%d", &k);
    scanf("%s\n", &a);
    int l = 0, r = 0;
    int cnt = (a[0] == '1');
    int n = strlen(a);
    ll ans = 0;
    if (!k)
    {
        ll cnt = 0;
        REP(i, n)
        {
            if (a[i] == '0')
                cnt++;
            else
            {
                if (cnt)
                    ans += (cnt * (cnt + 1)) / 2;
                cnt = 0;
            }
        }
        if (cnt)
            ans += (cnt * (cnt + 1)) / 2;
        printf("%I64d\n", ans);
        return 0;
    }
    while (r < n)
    {
        while (r < n - 1 && cnt != k)
            r++, cnt += (a[r] == '1');
        if (r == n - 1 && cnt != k)
            break;
        int x, y;
        x = y = 1;
        while (a[l] == '0')
            l++, x++;
        while (r < n - 1 && a[r + 1] == '0')
            r++, y++;
        l++, cnt--;
        ans += ll(x) * ll(y);
    }
    printf("%I64d\n", ans);
    return 0;
}
