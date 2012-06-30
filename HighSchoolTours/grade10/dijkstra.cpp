#include <stdio.h>
#include <cstdlib>
#define For(i, a, b) for (int i = a; i <= b; i++)
#include <memory.h>
#include <iostream>

using namespace std;

struct tmas
{
    int dest, next, wei;
};

struct q
{
    int wei, nom;
};

tmas list[20100];
int head[10000];
int en;

void add(int u, int v, int t)
{
    en++;
    list[en].dest = v;
    list[en].next = head[u];
    list[en].wei = t;
    head[u] = en;
}

q queue[1000];
int used[1000];
int way[1000];

void swap(q &a, q &b)
{
    q tt;
    tt = a;
    a = b;
    b = tt;
}

void shiftup(int i)
{
    while ((i > 1) && (queue[i / 2].wei > queue[i].wei))
    {
        swap(used[queue[i].nom], used[queue[i / 2].nom]);
        swap(queue[i], queue[i / 2]);
        i = i / 2;
    }
}

void shiftdown(int i, int n)
{
    while (2 * i <= n)
    {
        int s = 0;
        if (queue[2 * i].wei < queue[i].wei)
            s = 2 * i;
        if (2 * i < n)
            if (queue[2 * i + 1].wei < queue[s].wei)
                s = 2 * i + 1;
        if (s != 0)
        {
            swap(queue[i], queue[s]);
            swap(used[queue[i].nom], used[queue[s].nom]);
            i = s;
        }
        else
            break;
    }
}

int main()
{
    freopen("dijkstra.dat", "r", stdin);
    freopen("dijkstra.res", "w", stdout);
    int test;
    scanf("%d", &test);
    For(ttt, 1, test)
    {
        memset(head, 0, sizeof(head));
        memset(list, 0, sizeof(list));
        int n, m;
        scanf("%d%d", &n, &m);
        en = 0;
        For(i, 1, m)
        {
            int n1, n2, t;
            scanf("%d%d%d", &n1, &n2, &t);
            add(n1, n2, t);
            add(n2, n1, t);
        }
        int top = 1;
        queue[1].nom = 1;
        queue[1].wei = 0;
        memset(used, 0, sizeof(used));
        For(i, 1, n)
            way[i] = 1000000000;
        way[1] = 0;
        used[1] = 1;
        while (top > 0)
        {
            int v = queue[1].nom;
            used[v] = 0;
            int j = head[v];
            if (top != 1)
            {
                swap(queue[1], queue[top]);
                used[queue[1].nom] = 1;
                queue[top].nom = 0;
                queue[top].wei = 0;
                shiftdown(1, top - 1);
            }
            top--;
            while (j != 0)
            {
                if (way[v] + list[j].wei < way[list[j].dest])
                {
                    way[list[j].dest] = way[v] + list[j].wei;
                    if (used[list[j].dest] == 0)
                    {
                        top++;
                        queue[top].nom = list[j].dest;
                        queue[top].wei = way[list[j].dest];
                        used[list[j].dest] = top;
                        shiftup(top);
                    }
                    else
                    //if (queue[used[list[j].dest]].wei>way[list[j].dest])
                    {
                        queue[used[list[j].dest]].nom = list[j].dest;
                        queue[used[list[j].dest]].wei = way[list[j].dest];
                        shiftup(used[list[j].dest]);
                    }
                }
                j = list[j].next;
            }
        }
        For(i, 2, n - 1) if (way[i] != 1000000000) printf("%d ", way[i]);
        else printf("-1 ");
        if (way[n] != 1000000000)
            printf("%d\n", way[n]);
        else
            printf("-1\n");
    }
    return 0;
}
