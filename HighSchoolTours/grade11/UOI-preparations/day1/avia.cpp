#include <stdio.h>
#include <cstdlib>
#include <memory.h>

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

const char *infile = "avia.in";
const char *outfile = "avia.out";

int N, V, cnt;
bool used[NMAX];
int M[NMAX][NMAX];

void dfs(int v, bool inv)
{
    used[v] = true;
    cnt++;
    REP(i, N)
    if (!used[i] && (inv ? M[i][v] : M[v][i]) <= V)
        dfs(i, inv);
}

bool pleasure(int vol)
{
    V = vol;
    CLR(used, 0);
    cnt = 0;
    dfs(0, false);
    if (cnt != N)
        return false;
    CLR(used, 0);
    cnt = 0;
    dfs(0, true);
    if (cnt != N)
        return false;
    return true;
}

int bin_search(int l, int r)
{
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        if (pleasure(mid))
            r = mid;
        else
            l = mid;
    }
    if (pleasure(l))
        return l;
    return r;
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d", &N);
    REP(i, N)
    REP(j, N)
    scanf("%d", &M[i][j]);
    printf("%d\n", bin_search(0, Inf));
    return 0;
}
