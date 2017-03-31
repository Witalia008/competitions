#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define NMAX 100010

struct TList
{
    int dest, next, wei;
};

struct TAns
{
    int ans, acnt, max, mcnt;
};

TList List[NMAX * 2];
bool used[NMAX];
int Head[NMAX];
TAns Ans[NMAX];
int N, en;

void Add(int u, int v, int w)
{
    en++;
    List[en].wei = w;
    List[en].dest = v;
    List[en].next = Head[u];
    Head[u] = en;
}

int dad[NMAX];
int stack[NMAX];
bool flag[NMAX];
int top, v, i, j;

int main()
{
    scanf("%d", &N);
    for (i = 1; i < N; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        Add(a, b, c);
        Add(b, a, c);
    }

    top = 1;
    stack[1] = 1;
    used[1] = true;
    while (top)
    {
        v = stack[top];
        for (j = Head[v]; j && used[List[j].dest]; j = List[j].next)
            ;
        if (j)
        {
            flag[v] = true;
            dad[List[j].dest] = v;
            used[List[j].dest] = true;
            stack[++top] = List[j].dest;
        }
        else
        {
            --top;
            for (j = Head[v]; j; j = List[j].next)
                if (dad[v] != List[j].dest)
                {
                    if (Ans[v].max == List[j].wei + Ans[List[j].dest].max)
                        Ans[v].mcnt += Ans[List[j].dest].mcnt;
                    if (Ans[v].max < List[j].wei + Ans[List[j].dest].max)
                    {
                        Ans[v].max = List[j].wei + Ans[List[j].dest].max;
                        Ans[v].mcnt = Ans[List[j].dest].mcnt;
                    }
                }
            if (!flag[v])
                Ans[v].acnt = Ans[v].mcnt = 1;
            else
            {
                Ans[v].ans = Ans[v].max;
                Ans[v].acnt = Ans[v].mcnt * 2;
                for (j = Head[v]; j; j = List[j].next)
                    for (i = Head[v]; i; i = List[i].next)
                        if (i != j && dad[v] != List[j].dest && dad[v] != List[i].dest)
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
    }

    TAns A = Ans[1];
    for (i = 2; i <= N; i++)
        if (Ans[i].ans > A.ans)
            A = Ans[i];

    printf("%d %d\n", A.ans, A.acnt);
    return 0;
}
