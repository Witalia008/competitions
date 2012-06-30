#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define nmax 200000
#define INF 1000000000
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

struct tlist
{
    int dest, wei, next;
};

struct tqueue
{
    int wei, nom;
};

tlist list[nmax * 2 + 1];
int head[nmax + 1], a[nmax + 1], is[nmax + 1];
int n, m, s, f, en, top;
tqueue queue[nmax + 1];

void add(int u, int v, int we)
{
    en++;
    list[en].dest = v;
    list[en].next = head[u];
    head[u] = en;
    list[en].wei = we;
}

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void shiftup(int i)
{
    while (i > 1)
        if (queue[i].wei < queue[i / 2].wei)
        {
            swap(is[queue[i].nom], is[queue[i / 2].nom]);
            swap(queue[i].nom, queue[i / 2].nom);
            swap(queue[i].wei, queue[i / 2].wei);
            i /= 2;
        }
        else
            i = 1;
}

void shiftdown(int i)
{
    while (i * 2 <= top)
    {
        int k = i;
        if (queue[k].wei > queue[i * 2].wei)
            k = i * 2;
        if (i * 2 + 1 <= top && queue[i * 2 + 1].wei < queue[k].wei)
            k = i * 2 + 1;
        if (k == i)
            i = top + 1;
        else
        {
            swap(queue[i].nom, queue[k].nom);
            swap(queue[i].wei, queue[k].wei);
            swap(is[queue[i].nom], is[queue[k].nom]);
            i = k;
        }
    }
}

int main()
{
    freopen("distance.in", "r", stdin);
    freopen("distance.out", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &s, &f);
    For(i, 1, m)
    {
        int si, fi, pi;
        scanf("%d%d%d", &si, &fi, &pi);
        add(si, fi, pi);
        add(fi, si, pi);
    }
    For(i, 1, n)
        a[i] = INF;
    a[s] = 0;
    top = 1;
    memset(is, 0, sizeof(is));
    memset(queue, 0, sizeof(queue));
    is[s] = 1;
    queue[1].nom = s;
    queue[1].wei = 0;
    while (top)
    {
        tqueue v = queue[1];
        swap(queue[1].wei, queue[top].wei);
        swap(queue[1].nom, queue[top].nom);
        is[queue[top].nom] = 1;
        is[v.nom] = 0;
        top--;
        shiftdown(1);
        int j = head[v.nom];
        while (j)
        {
            if (a[list[j].dest] > v.wei + list[j].wei)
            {
                a[list[j].dest] = v.wei + list[j].wei;
                if (is[list[j].dest] == 0)
                {
                    top++;
                    is[list[j].dest] = top;
                    queue[top].nom = list[j].dest;
                    queue[top].wei = a[list[j].dest];
                    shiftup(top);
                }
                else
                {
                    queue[is[list[j].dest]].wei = a[list[j].dest];
                    shiftup(is[list[j].dest]);
                }
            }
            j = list[j].next;
        }
    }
    if (a[f] == INF)
        printf("-1\n");
    else
        printf("%d\n", a[f]);
    return 0;
}
