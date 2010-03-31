#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define nmax 100001

struct TList
{
    int dest, next, wei;
};

struct TAns
{
    int ans, acnt, max, mcnt;
};

TList List[nmax * 2];
bool used[nmax];
int Head[nmax];
TAns Ans[nmax];
int N, en;

void Add(int u, int v, int w)
{
    en++;
    List[en].wei = w;
    List[en].dest = v;
    List[en].next = Head[u];
    Head[u] = en;
}

void dfs(int v)
{
    used[v] = true;
    int j = Head[v];
    bool fl = false;
    while (j)
    {
        if (!used[List[j].dest])
        {
            dfs(List[j].dest);

            if (Ans[v].max == List[j].wei + Ans[List[j].dest].max)
                Ans[v].mcnt += Ans[List[j].dest].mcnt;
            if (Ans[v].max < List[j].wei + Ans[List[j].dest].max)
            {
                Ans[v].max = List[j].wei + Ans[List[j].dest].max;
                Ans[v].mcnt = Ans[List[j].dest].mcnt;
            }

            fl = true;
        }
        j = List[j].next;
    }
    if (!fl)
        Ans[v].acnt = Ans[v].mcnt = 1;
    else
    {
        Ans[v].ans = Ans[v].max;
        Ans[v].acnt = Ans[v].mcnt * 2;
        for (j = Head[v]; j; j = List[j].next)
            for (int i = Head[v]; i; i = List[i].next)
                if (i != j)
                {
                    if (Ans[v].ans == Ans[List[j].dest].max + Ans[List[i].dest].max + List[j].wei + List[i].wei)
                        Ans[v].acnt += Ans[List[i].dest].mcnt * Ans[List[j].dest].mcnt;

                    if (Ans[v].ans < Ans[List[j].dest].max + Ans[List[i].dest].max + List[j].wei + List[i].wei)
                    {
                        Ans[v].ans = Ans[List[j].dest].max + Ans[List[i].dest].max + List[j].wei + List[i].wei;
                        Ans[v].acnt = Ans[List[i].dest].mcnt * Ans[List[j].dest].mcnt;
                    }
                }
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i < N; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        Add(a, b, c);
        Add(b, a, c);
    }

    dfs(1);

    TAns A = Ans[1];
    for (int i = 2; i <= N; i++)
        if (Ans[i].ans > A.ans)
            A = Ans[i];

    printf("%d %d\n", A.ans, A.acnt);
    return 0;
}
