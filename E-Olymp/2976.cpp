#include <stdio.h>
#include <cstdlib>

using namespace std;

#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REPD(i, n) FORD(i, n - 1, 0)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define N 205
#define M 40002

struct TList
{
    int dest, next;
};

int n, m, cnt;
bool A[N][N], used[N];
int ans[M], step[N];

void dfs(int v)
{
    used[v] = true;
    FOR(i, 1, n)
    if (A[v][i])
    {
        A[v][i] = A[i][v] = false;
        dfs(i);
    }
    ans[cnt++] = v;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    REP(i, m)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        A[a][b] = A[b][a] = true;
        step[a]++;
        step[b]++;
    }
    int start = 1;
    FOR(i, 1, n)
    if (step[i] & 1)
        cnt++, start = i;
    if (cnt == 2 || cnt == 0)
    {
        cnt = 0;
        dfs(start);
        FOR(i, 1, n)
        if (!used[i])
        {
            printf("-1\n");
            return 0;
        }
        if (cnt == m + 1)
        {
            REP(i, cnt)
            {
                printf("%d", ans[i]);
                if (i == m)
                    printf("\n");
                else
                    printf(" ");
            }
        }
        else
            printf("-1\n");
    }
    else
        printf("-1\n");
    return 0;
}
