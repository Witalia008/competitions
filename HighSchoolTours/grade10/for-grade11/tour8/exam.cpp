#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

struct tmas
{
    int dest, next;
};

bool used[60];
int en, n, m;
tmas list[4000];
int mt[60], head[60];

bool try_kuhn(int v)
{
    if (used[v])
        return false;
    used[v] = true;
    int j = head[v];
    while (j != 0)
    {
        if ((mt[list[j].dest] == -1) || (try_kuhn(mt[list[j].dest])))
        {
            mt[list[j].dest] = v;
            return true;
        }
        j = list[j].next;
    }
    return false;
}

void add(int u, int v)
{
    en++;
    list[en].dest = v;
    list[en].next = head[u];
    head[u] = en;
}

int main()
{
    freopen("exam.dat", "r", stdin);
    freopen("exam.sol", "w", stdout);
    memset(head, 0, sizeof(head));
    en = 0;
    scanf("%d%d", &n, &m);
    For(i, 1, m)
    {
        int aaa, bbb;
        scanf("%d%d", &aaa, &bbb);
        add(aaa, bbb);
        add(bbb, aaa);
    }
    For(i, 1, 59) mt[i] = -1;
    For(v, 1, n)
    {
        memset(used, 0, sizeof(used));
        try_kuhn(v);
    }
    int nom = 1;
    while ((mt[nom] == -1) && (nom <= n))
        nom++;
    if (nom <= n)
        printf("%d", nom);
    For(i, 1, n) if ((mt[i] != -1) && (i != nom)) printf(" %d", i);
    printf("\n");
    return 0;
}
