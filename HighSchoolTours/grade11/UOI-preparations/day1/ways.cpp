#include <stdio.h>
#include <cstdlib>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define max(a, b) ((a) > (b)) ? (a) : (b)
#define CLR(a, x) memset(a, x, sizeof(a))
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define MP make_pair
#define Inf 1000000000
#define NMAX 1005

const char *infile = "ways.dat";
const char *outfile = "ways.sol";

int n, m, N, flow, cstep;
int F[NMAX][NMAX];
int step[NMAX];
bool was;

void dfs(int v)
{
    if (v == N + 1)
    {
        flow++;
        was = true;
        return;
    }
    FOR(i, 1, N + 1)
    {
        if (v == 0)
        {
            was = false;
            cstep++;
        }
        step[v] = cstep;
        if (F[v][i] && !was && step[i] != step[v])
        {
            dfs(i);
            if (was)
            {
                F[v][i]--;
                F[i][v]++;
            }
        }
    }
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d%d", &n, &m);
    N = n * m * 2;
    FOR(i, 1, n)
    F[0][i] = F[N - n + i][N + 1] = 1;

    FOR(i, 1, n)
    FOR(j, 1, m)
    F[(j - 1) * 2 * n + i][(j - 1) * 2 * n + i + n] = 1;
    FOR(j, 1, m - 1)
    {
        FOR(i, 1, n)
        {
            int x;
            scanf("%d", &x);
            REP(l, x)
            {
                int a;
                scanf("%d", &a);
                F[(j - 1) * 2 * n + i + n][j * 2 * n + a] = 1;
            }
        }
    }
    cstep = 1;
    dfs(0);
    printf("%d\n", flow);
    return 0;
}
