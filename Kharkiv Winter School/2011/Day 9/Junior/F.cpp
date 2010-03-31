#include <stdio.h>
#include <cstdlib>

using namespace std;

#define nmax 100000

struct TList
{
    int dest, next;
} List[nmax + 1];
struct TTime
{
    int in, out;
} Time[nmax + 1];
int Head[nmax + 1];
bool Used[nmax + 1];
int N, M, en, time, root;

void Add(int u, int v)
{
    en++;
    List[en].dest = v;
    List[en].next = Head[u];
    Head[u] = en;
}

void DFS(int i)
{
    Used[i] = true;
    Time[i].in = ++time;
    int j = Head[i];
    while (j)
    {
        if (!Used[List[j].dest])
            DFS(List[j].dest);
        j = List[j].next;
    }
    Time[i].out = ++time;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d\n", &N);
    for (int i = 1; i <= N; i++)
    {
        int parent;
        scanf("%d", &parent);
        if (parent)
            Add(parent, i);
        else
            root = i;
    }

    DFS(root);

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (Time[a].in < Time[b].in && Time[a].out > Time[b].out)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
