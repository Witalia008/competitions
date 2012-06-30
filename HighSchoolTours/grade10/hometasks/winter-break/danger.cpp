#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#define nmax 100
#define INF 1000000000
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

struct tlist
{
    int dest, next;
    double wei;
};

struct tqueue
{
    int nom;
    double wei;
};

tlist list[nmax * nmax];
int head[nmax], is[nmax + 1];
double a[nmax + 1];
int n, m, en, top, s, f;
tqueue queue[nmax + 1];

void add(int u, int v, double we)
{
    en++;
    list[en].dest = v;
    list[en].next = head[u];
    head[u] = en;
    list[en].wei = we;
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
    freopen("danger.in", "r", stdin);
    freopen("danger.out", "w", stdout);
    int n, m;
    scanf("%d%d%d%d", &n, &m, &s, &f);
    For(i, 1, m)
    {
        int si, fi, pi;
        scanf("%d%d%d", &si, &fi, &pi);
        add(si, fi, (double)pi / 100);
        add(fi, si, (double)pi / 100);
    }
    For(i, 1, n)
        a[i] = INF;
    a[s] = 0;
    top = 1;
    memset(queue, 0, sizeof(queue));
    memset(is, 0, sizeof(is));
    is[s] = 1;
    queue[1].nom = s;
    queue[1].wei = 0;
    while (top)
    {
        tqueue v = queue[1];
        swap(is[v.nom], is[queue[top].nom]);
        swap(queue[1].nom, queue[top].nom);
        swap(queue[1].wei, queue[top].wei);
        top--;
        shiftdown(1);
        int j = head[v.nom];
        while (j)
        {
            if (v.wei + list[j].wei - v.wei * list[j].wei < a[list[j].dest])
            {
                a[list[j].dest] = v.wei + list[j].wei - v.wei * list[j].wei;
                if (is[list[j].dest] == 0)
                {
                    top++;
                    queue[top].nom = list[j].dest;
                    queue[top].wei = a[list[j].dest];
                    is[list[j].dest] = top;
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
    printf("%0.6lf\n", a[f]);
    return 0;
}
