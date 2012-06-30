#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "pasture.in";
const char *outfile = "pasture.out";
const int nmax = 100000;

struct TList
{
    int dest, next;
};

TList list[nmax * 2];
int head[nmax], step[nmax], f[nmax];
bool is[nmax];
int N, en;

void add(int u, int v)
{
    en++;
    list[en].dest = v;
    list[en].next = head[u];
    head[u] = en;
    step[u]++;
}

void dfs2(int i)
{
    is[i] = !is[i];
    int j = head[i];
    while (j)
    {
        if (list[j].dest != f[i])
            dfs2(list[j].dest);
        j = list[j].next;
    }
}

void dfs(int i)
{
    if (step[i] == 1)
    {
        is[i] = false;
        return;
    }
    int j = head[i];
    is[i] = true;
    while (j)
    {
        if (list[j].dest != f[i])
        {
            f[list[j].dest] = i;
            dfs(list[j].dest);
            if (is[list[j].dest])
                is[i] = false;
        }
        j = list[j].next;
    }
    if (!is[i])
    {
        j = head[i];
        while (j)
        {
            if (list[j].dest != f[i] && !is[list[j].dest])
                dfs2(list[j].dest);
            j = list[j].next;
        }
    }
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d", &N);
    for (int i = 1; i < N; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        add(a, b);
        add(b, a);
    }
    for (int i = 0; i < N; i++)
        f[i] = -1;
    int start = 1;
    for (int i = 0; i < N; i++)
        if (step[i] != 1)
            start = i;
    dfs(start);
    int ans = 0;
    for (int i = 0; i < N; i++)
        ans += is[i];
    if (N <= 2)
        printf("1\n");
    else
        printf("%d\n", ans);
    return 0;
}
