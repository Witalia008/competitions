#include <stdio.h>
#include <cstdlib>
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
#define N 40005

int x[N], y[N];
int n, w, h;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &w, &h, &n);
    x[0] = y[0] = 0;
    x[1] = w + 1;
    y[1] = h + 1;
    for (int i = 0; i < n; i++)
        scanf("%d%d", &x[i + 2], &y[i + 2]);
    sort(x, x + n + 2);
    sort(y, y + n + 2);
    int maxx = 0, maxy = 0;
    for (int i = 0; i < n + 1; i++)
    {
        maxx = max(maxx, x[i + 1] - x[i]);
        maxy = max(maxy, y[i + 1] - y[i]);
    }
    maxx--;
    maxy--;
    printf("%d\n", maxx * maxy);
    return 0;
}
