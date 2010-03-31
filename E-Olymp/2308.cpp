#include <stdio.h>
#include <cstdlib>

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
#define N 130

int n;
int T[N][N][N];

void Add(int x, int y, int z, int val)
{
    for (int i = x; i < n; i = i | (i + 1))
        for (int j = y; j < n; j = j | (j + 1))
            for (int k = z; k < n; k = k | (k + 1))
                T[i][j][k] += val;
}

int Sum(int x, int y, int z)
{
    int res = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
            for (int k = z; k >= 0; k = (k & (k + 1)) - 1)
                res += T[i][j][k];
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int m;
    scanf("%d", &m);
    while (m != 3)
    {
        if (m == 1)
        {
            int x, y, z, k;
            scanf("%d%d%d%d", &x, &y, &z, &k);
            Add(x, y, z, k);
        }
        else
        {
            int x1, x2, y1, y2, z1, z2;
            scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
            printf("%d\n", Sum(x2, y2, z2) - Sum(x1 - 1, y2, z2) - Sum(x2, y1 - 1, z2) - Sum(x2, y2, z1 - 1) + Sum(x1 - 1, y1 - 1, z2) + Sum(x1 - 1, y2, z1 - 1) + Sum(x2, y1 - 1, z1 - 1) - Sum(x1 - 1, y1 - 1, z1 - 1));
        }
        scanf("%d", &m);
    }
    return 0;
}
