#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>

using namespace std;

#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REPD(i, n) FORD(i, n - 1, 0)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define N 55

int n;
int g[N][N];
bool in_a[N], exist[N];
int w[N];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    while (n)
    {
        CLR(g, 0);
        REP(i, n)
        {
            string s;
            cin >> s;
            REP(j, n)
            g[i][j] = s[j] - '0';
        }
        int best_cost = Inf;
        CLR(exist, true);
        REP(ph, n - 1)
        {
            CLR(w, 0);
            CLR(in_a, false);
            int prev;
            REP(it, n - ph)
            {
                int sel = -1;
                REP(i, n)
                if (exist[i] && !in_a[i] && (sel == -1 || w[sel] < w[i]))
                    sel = i;
                if (it == n - ph - 1)
                {
                    if (w[sel] < best_cost)
                        best_cost = w[sel];
                    REP(i, n)
                    g[prev][i] = g[i][prev] += g[i][sel];
                    exist[sel] = false;
                }
                else
                {
                    in_a[sel] = true;
                    REP(i, n)
                    w[i] += g[i][sel];
                    prev = sel;
                }
            }
        }
        printf("%d\n", best_cost);
        n = 0;
        cin >> n;
    }
    return 0;
}
