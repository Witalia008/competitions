#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define nmax 100000
#define INF 1000000000
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

struct tlist
{
    int dest, next;
};

struct tqueue
{
    int wei, nom;
};

tlist list[nmax * 2 + 1];
int head[nmax + 1], a[nmax + 1], who[nmax + 1], is[nmax + 1], f[nmax + 1], sol[nmax + 1];
int n, m, en, top;
tqueue queue[nmax + 1];

void add(int u, int v)
{
    en++;
    list[en].dest = v;
    list[en].next = head[u];
    head[u] = en;
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
    freopen("island2.in", "r", stdin);
    freopen("island2.out", "w", stdout);
    scanf("%d%d", &n, &m);
    For(i, 1, n)
        scanf("%d", &who[i]);
    For(i, 1, m)
    {
        int si, fi;
        scanf("%d%d", &si, &fi);
        add(si, fi);
        add(fi, si);
    }
    For(i, 1, n)
        a[i] = INF;
    a[1] = 0;
    top = 1;
    memset(queue, 0, sizeof(queue));
    memset(is, 0, sizeof(is));
    is[1] = 1;
    f[1] = 0;
    queue[1].nom = 1;
    while (top)
    {
        tqueue v = queue[1];
        swap(is[queue[1].nom], is[queue[top].nom]);
        swap(queue[1].nom, queue[top].nom);
        swap(queue[1].wei, queue[top].wei);
        is[v.nom] = 0;
        top--;
        shiftdown(1);
        int j = head[v.nom];
        while (j)
        {
            int k = 0;
            if (who[v.nom] != who[list[j].dest])
                k = 1;
            if (v.nom % 2 == 0)
                k *= 2;
            if (a[list[j].dest] > v.wei + k)
            {
                a[list[j].dest] = v.wei + k;
                f[list[j].dest] = v.nom;
                if (is[list[j].dest] == 0)
                {
                    top++;
                    is[list[j].dest] = top;
                    queue[top].wei = v.wei + k;
                    queue[top].nom = list[j].dest;
                    shiftup(top);
                }
                else
                {
                    queue[is[list[j].dest]].wei = v.wei + k;
                    shiftup(is[list[j].dest]);
                }
            }
            j = list[j].next;
        }
    }
    if (a[n] == INF)
        printf("impossible\n");
    else
    {
        printf("%d", a[n]);
        int cou = 0, c = n;
        while (c)
        {
            cou++;
            sol[cou] = c;
            c = f[c];
        }
        printf(" %d\n", cou);
        for (int i = cou; i > 1; i--)
            printf("%d ", sol[i]);
        printf("%d\n", sol[1]);
    }
    return 0;
}
