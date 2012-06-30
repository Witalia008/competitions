#include <stdio.h>
#include <cstdlib>
#include <fstream>

using namespace std;

#define nmax 100000

struct TList
{
    int dest, next, back, wei;
};

int N, M, w, b, g, en, flow, FL;
TList List[nmax];
int Head[nmax], f[nmax];

inline void Add(int u, int v, int wei, bool need)
{
    en++;
    List[en].dest = v;
    List[en].next = Head[u];
    List[en].wei = wei;
    List[en].back = -1;
    Head[u] = en;
    if (need)
    {
        List[en].back = en + 1;
        en++;
        List[en].dest = u;
        List[en].next = Head[v];
        List[en].wei = wei;
        List[en].back = en - 1;
        Head[v] = en;
    }
}

inline void New(int i, int j)
{
    int cur = (i - 1) * M + j;
    if (i < N)
        Add(cur, cur + M, g, true);
    if (j < M)
        Add(cur, cur + 1, g, true);
}

void DFS(int i, int C, int step)
{
    if (i == N * M + 1)
    {
        FL++;
        f[i] = step;
        return;
    }
    f[i] = step;
    int j = Head[i];
    while (j)
    {
        if (i == 0)
            f[N * M + 1] = 0;
        int x = f[N * M + 1];
        if (List[j].wei >= C && f[List[j].dest] != step && x != step)
            DFS(List[j].dest, C, step);
        if (x != step && f[N * M + 1] == step)
        {
            List[j].wei -= C;
            if (List[j].back != -1)
                List[List[j].back].wei += C;
        }
        j = List[j].next;
    }
}

int main()
{
    freopen("drawing.dat", "r", stdin);
    freopen("drawing.sol", "w", stdout);
    scanf("%d%d%d%d%d\n", &N, &M, &w, &b, &g);
    for (int i = 1; i <= N; i++)
    {
        char x[100];
        scanf("%s\n", x);
        for (int j = 1; j <= M; j++)
        {
            switch (x[j - 1])
            {
            case 'B':
                Add((i - 1) * M + j, N * M + 1, w, false);
                break;
            case 'W':
                Add(0, (i - 1) * M + j, b, false);
            }
            New(i, j);
        }
    }
    int C = max(max(w, b), g);
    int step = 0;
    while (C)
    {
        bool flag = true;
        while (flag)
        {
            step++;
            FL = 0;
            DFS(0, C, step);
            if (FL == 0)
                flag = false;
            else
                flow += FL * C;
        }
        C /= 2;
    }
    printf("%d\n", flow);
    return 0;
}
