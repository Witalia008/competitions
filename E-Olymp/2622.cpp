#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "input.txt";
const char *outfile = "output.txt";

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define Inf 1000000000
#define NMAX 22

struct Edge
{
    int s, f, c;
};

int N, M, cnt, time;
Edge edge[NMAX];
int a[NMAX], tin[NMAX], tout[NMAX];
bool used[NMAX];
bool flag;

void dfs(int v, int p = -1)
{
    used[v] = true;
    cnt++;
    tout[v] = tin[v] = ++time;
    FOR(i, 1, M)
    if (a[i])
    {
        int to = 0;
        if (edge[i].f == v)
            to = edge[i].s;
        if (edge[i].s == v)
            to = edge[i].f;
        if (to)
        {
            if (used[to])
            {
                if (i != p)
                    tout[v] = min(tout[v], tin[to]);
            }
            else
            {
                dfs(to, i);
                tout[v] = min(tout[v], tout[to]);
                if (tout[to] > tin[v])
                    flag = false;
            }
        }
    }
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d%d", &N, &M);
    int nom = 0;
    while (N || M)
    {
        nom++;
        FOR(i, 1, M)
        scanf("%d%d%d", &edge[i].s, &edge[i].f, &edge[i].c);

        flag = true;
        cnt = 0;
        time = 0;
        FOR(i, 1, N)
        used[i] = false;
        FOR(i, 1, M)
        a[i] = 1;
        dfs(1);
        if (!flag || cnt != N)
        {
            printf("There is no reliable net possible for test case %d.\n", nom);
            goto label1;
        }
        FOR(i, 1, M)
        a[i] = 0;

        int ans = Inf;
        while (true)
        {
            int j = M;
            while (j && a[j] == 1)
                a[j--] = 0;
            if (!j)
                break;
            else
            {
                a[j] = 1;
                flag = true;
                cnt = 0;
                FOR(i, 1, N)
                used[i] = false;
                time = 0;
                dfs(1);
                if (flag && cnt == N)
                {
                    int cost = 0;
                    FOR(i, 1, M)
                    if (a[i])
                        cost += edge[i].c;
                    ans = min(ans, cost);
                }
            }
        }
        if (ans == Inf)
            ans = 0;
        printf("The minimal cost for test case %d is %d.\n", nom, ans);
    label1:
        scanf("%d%d", &N, &M);
    }
    return 0;
}
