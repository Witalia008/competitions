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

int n;
int m[N];
int x[N * 5], y[N * 5];
int cnt, ans;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    while (n)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &m[i]);
        if (n < 2)
        {
            if (!n)
                printf("0\n");
            else
                printf("%d\n%d\n", m[0], m[0]);
            goto label1;
        }
        cnt = -1;
        ans = 0;
        for (int i = 0; i < 5 * N; i++)
            x[i] = y[i] = -1;
        sort(m, m + n);
        while (n)
        {
            if (n > 3)
            {
                if (2 * m[0] + m[n - 1] + m[n - 2] < m[0] + 2 * m[1] + m[n - 1])
                {
                    ans += 2 * m[0] + m[n - 1] + m[n - 2];
                    cnt++;
                    x[cnt] = m[0];
                    y[cnt] = m[n - 1];
                    cnt++;
                    x[cnt] = m[0];
                    cnt++;
                    x[cnt] = m[0];
                    y[cnt] = m[n - 2];
                    cnt++;
                    x[cnt] = m[0];
                }
                else
                {
                    ans += m[0] + 2 * m[1] + m[n - 1];
                    cnt++;
                    x[cnt] = m[0];
                    y[cnt] = m[1];
                    cnt++;
                    x[cnt] = m[0];
                    cnt++;
                    x[cnt] = m[n - 2];
                    y[cnt] = m[n - 1];
                    cnt++;
                    x[cnt] = m[1];
                }
                n -= 2;
            }
            else
            {
                if (n == 2)
                {
                    ans += m[1];
                    cnt++;
                    x[cnt] = m[0];
                    y[cnt] = m[1];
                }
                else
                {
                    ans += m[0] + m[1] + m[2];
                    cnt++;
                    x[cnt] = m[0];
                    y[cnt] = m[1];
                    cnt++;
                    x[cnt] = m[0];
                    cnt++;
                    x[cnt] = m[0];
                    y[cnt] = m[2];
                }
                n = 0;
            }
        }
        printf("%d\n", ans);
        for (int i = 0; i <= cnt; i++)
        {
            printf("%d", x[i]);
            if (y[i] != -1)
                printf(" %d", y[i]);
            printf("\n");
        }
    label1:
        n = 0;
        scanf("%d", &n);
    }
    return 0;
}
