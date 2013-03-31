#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const char *infile = "input.txt";
const char *outfile = "output.txt";

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

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPI;
typedef unsigned long long LL;

#define NMAX 50005
#define KMAX 505

struct TList
{
    int dest, next;
};

LL deph[NMAX][KMAX];
TList List[NMAX * 2];
int Head[NMAX];
int N, K, en;
LL ans;

void Add(int u, int v)
{
    en++;
    List[en].dest = v;
    List[en].next = Head[u];
    Head[u] = en;
}

void dfs(int v, int p = -1)
{
    deph[v][0] = 1;
    for (int j = Head[v]; j; j = List[j].next)
    {
        if (List[j].dest != p)
        {
            dfs(List[j].dest, v);
            FOR(i, 1, K)
            deph[v][i] += deph[List[j].dest][i - 1];
        }
    }
    ans += deph[v][K];
    LL cnt = 0;
    for (int j = Head[v]; j; j = List[j].next)
        if (List[j].dest != p)
            FOR(i, 1, K - 1)
    cnt += deph[List[j].dest][i - 1] * (deph[v][K - i] - deph[List[j].dest][K - i - 1]);
    ans += cnt / 2;
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d%d", &N, &K);
    REP(i, N - 1)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        Add(a, b);
        Add(b, a);
    }
    dfs(1);
    printf("%I64d\n", ans);
    return 0;
}
