#include <stdio.h>
#include <cstdlib>

#pragma comment(linker, "/STACK:20000000")

using namespace std;

#define Inf 2000000000
#define NMAX 100010

struct TList
{
    int dest, next, wei;
};

TList List[NMAX * 2];
int Head[NMAX], C[NMAX];
bool used[NMAX];
int N, en;
int sum, ans;

void Add(int u, int v, int w)
{
    en++;
    List[en].dest = v;
    List[en].wei = w;
    List[en].next = Head[u];
    Head[u] = en;
}

void dfs(int v, int cur)
{
    if (sum - cur + C[v] < ans)
        ans = sum - cur + C[v];
    used[v] = true;
    int j = Head[v];
    while (j)
    {
        if (!used[List[j].dest])
            dfs(List[j].dest, cur + List[j].wei);
        j = List[j].next;
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i <= N; i++)
        scanf("%d", &C[i]);
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        sum += 2 * c;
        Add(a, b, c);
        Add(b, a, c);
    }

    ans = Inf;
    dfs(0, 0);

    printf("%d\n", ans);
    return 0;
}
