#include <stdio.h>
#include <cstdlib>
#include <memory.h>

using namespace std;

#define nmax 10000

struct TList
{
    int dest, next, wei, back;
};

int T, R, C, en, flow;
int Head[nmax + 1];
TList List[nmax + 1];
bool used[nmax + 1];

void Add(int u, int v, bool need)
{
    en++;
    List[en].dest = v;
    List[en].next = Head[u];
    List[en].wei = 1;
    List[en].back = -1;
    Head[u] = en;
    if (need)
    {
        List[en].back = en + 1;
        en++;
        List[en].dest = u;
        List[en].next = Head[v];
        List[en].wei = 0;
        List[en].back = en - 1;
        Head[v] = en;
    }
}

void DFS(int i)
{
    used[i] = true;

    if (i == R + C + 1)
    {
        flow++;
        return;
    }

    int j = Head[i];
    while (j)
    {
        if (i == 0)
            used[R + C + 1] = false;
        bool x = used[R + C + 1];

        if (List[j].wei >= 1 && !x && !used[List[j].dest])
            DFS(List[j].dest);

        if (!x && used[R + C + 1])
        {
            List[j].wei--;
            if (List[j].back != -1)
                List[List[j].back].wei++;
        }

        j = List[j].next;
    }
    used[i] = false;
}

int main()
{
    freopen("sho.in", "r", stdin);
    freopen("sho.out", "w", stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        scanf("%d%d", &R, &C);
        memset(Head, 0, sizeof(Head));
        memset(used, 0, sizeof(used));
        en = 0;

        for (int i = 1; i <= C; i++)
            Add(0, i, false);

        for (int i = 1; i <= R; i++)
            Add(C + i, C + R + 1, false);

        for (int i = 1; i <= C; i++)
        {
            int n1, n2;
            scanf("%d%d", &n1, &n2);
            Add(i, C + n1, true);
            Add(i, C + n2, true);
        }

        flow = 0;
        DFS(0);

        if (flow != R)
            printf("NO\n");
        else
        //printf ("YES\n");
        {
            for (int i = 1; i <= C; i++)
            {
                if (List[Head[i]].wei == 0)
                    printf("%d", List[Head[i]].dest - C);
                else
                    printf("%d", List[List[Head[i]].next].dest - C);
                if (i != C)
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
