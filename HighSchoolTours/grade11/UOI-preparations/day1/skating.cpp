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

const char *infile = "skating.in";
const char *outfile = "skating.out";

int S, P, p, s;
bool a[4][4], u[4][4];

void dfs(int ci, int cj)
{
    u[ci][cj] = true;
    s--;
    if (ci > 0 && !u[ci - 1][cj] && a[ci - 1][cj])
        dfs(ci - 1, cj);
    if (cj > 0 && !u[ci][cj - 1] && a[ci][cj - 1])
        dfs(ci, cj - 1);
    if (ci < 3 && !u[ci + 1][cj] && a[ci + 1][cj])
        dfs(ci + 1, cj);
    if (cj < 3 && !u[ci][cj + 1] && a[ci][cj + 1])
        dfs(ci, cj + 1);
    if (ci == 0 || !a[ci - 1][cj])
        p++;
    if (cj == 0 || !a[ci][cj - 1])
        p++;
    if (ci == 3 || !a[ci + 1][cj])
        p++;
    if (cj == 3 || !a[ci][cj + 1])
        p++;
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d%d", &P, &S);
    REP(mask, 1 << 16)
    {
        int si, sj;
        si = sj = -1;
        p = s = 0;
        REP(i, 4)
        REP(j, 4)
        {
            a[i][j] = mask & (1 << (i * 4 + j));
            s += a[i][j];
            if (a[i][j])
                si = i, sj = j;
            u[i][j] = false;
        }
        if (s != S)
            continue;
        if (si != -1)
            dfs(si, sj);
        if (s)
            continue;
        if (p == P)
        {
            REP(i, 4)
            {
                REP(j, 4)
                if (a[i][j])
                    printf("*");
                else
                    printf(".");
                printf("\n");
            }
            return 0;
        }
    }
    printf("Impossible\n");
    return 0;
}
