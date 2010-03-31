#include <stdio.h>
#include <cstdlib>
#include <memory.h>

using namespace std;

const char *infile = "input.txt";
const char *outfile = "output.txt";
const int nmax = 3001;
const int mmax = 100001;

struct TList
{
    int dest, next;
};

TList List[mmax], list[mmax];
int Head[nmax], head[nmax], order[nmax], Comp[nmax], Ans[nmax];
bool used[nmax], is_out[nmax];
int N, M, en, tout, comp, ans;

void Add(int u, int v)
{
    en++;
    List[en].dest = v;
    List[en].next = Head[u];
    Head[u] = en;

    list[en].dest = u;
    list[en].next = head[v];
    head[v] = en;
}

void dfs1(int i)
{
    used[i] = true;
    int j = Head[i];
    while (j)
    {
        if (!used[List[j].dest])
            dfs1(List[j].dest);
        j = List[j].next;
    }
    order[++tout] = i;
}

void dfs2(int i)
{
    Comp[i] = comp;
    used[i] = true;
    int j = head[i];
    while (j)
    {
        if (!used[list[j].dest])
            dfs2(list[j].dest);
        j = list[j].next;
    }
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);

    scanf("%d%d", &N, &M);
    int a, b;
    en = 0;
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d", &a, &b);
        Add(a, b);
    }

    tout = 0;
    memset(used, 0, sizeof(used));
    for (int i = 1; i <= N; i++)
        if (!used[i])
            dfs1(i);

    comp = 0;
    memset(used, 0, sizeof(used));
    for (int i = N; i > 0; i--)
        if (!used[order[i]])
        {
            comp++;
            dfs2(order[i]);
        }

    for (int i = 1; i <= N; i++)
    {
        int j = Head[i];
        while (j)
        {
            if (Comp[i] != Comp[List[j].dest])
                is_out[Comp[i]] = true;
            j = List[j].next;
        }
    }

    ans = 0;
    for (int i = 1; i <= comp; i++)
        if (!is_out[i])
        {
            ans++;
            int j = 1;
            while (Comp[j] != i)
                j++;
            Ans[ans] = j;
        }

    printf("%d\n", ans);
    for (int i = 1; i < ans; i++)
        printf("%d ", Ans[i]);
    printf("%d\n", Ans[ans]);
    return 0;
}
