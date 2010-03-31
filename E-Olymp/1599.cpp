#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REPD(i, n) FORD(i, n - 1, 0)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define max(a, b) (a > b) ? (a) : (b)
#define Inf 1000000000
#define N 1000

int a[N];
int n, s, cnt;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d\n", &t);
    for (int _t = 0; _t < t; _t++)
    {
        scanf("%d%d\n", &n, &s);
        cnt = 2;
        for (int i = 0; i < n; i++)
        {
            char q;
            int l;
            if (i)
                scanf(" ");
            scanf("%c-%d", &q, &l);
            a[cnt++] = l;
            if (q == 'B')
                a[cnt++] = l;
        }
        scanf("\n");
        a[cnt++] = s;
        a[cnt++] = s;
        sort(a, a + cnt);
        int ans = 0;
        for (int i = 0; i < cnt - 2; i++)
            ans = max(ans, a[i + 2] - a[i]);
        printf("Case %d: %d\n", _t + 1, ans);
    }
    return 0;
}
