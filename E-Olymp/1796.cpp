#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "input.txt";
const char *outfile = "output.txt";

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define max(a, b) ((a) > (b)) ? (a) : (b)
#define CLR(a, x) memset(a, x, sizeof(a))
#define all(a) (a.begin(), a.end())
#define MP make_pair
#define Inf 1000000000
#define NMAX 101

int N;
int D[NMAX][NMAX];

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &D[i][j]);
            if (D[i][j] == -1)
                D[i][j] = Inf;
        }
    FOR(k, 1, N)
    FOR(i, 1, N)
    FOR(j, 1, N)
    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    int d = 0;
    FOR(i, 1, N)
    FOR(j, 1, N)
    d = max(d, D[i][j]);
    int r = Inf;
    FOR(i, 1, N)
    {
        int ex = 0;
        FOR(j, 1, N)
        ex = max(ex, D[i][j]);
        r = min(r, ex);
    }
    printf("%d\n%d\n", d, r);
    return 0;
}
