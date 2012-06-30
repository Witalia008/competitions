#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <time.h>
#include <set>
#define nmax 100
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

struct tmas
{
    set<int> n;
};

tlist list[nmax * 2 + 1];
int head[nmax + 1], a[nmax + 1], a1[nmax + 1], is[nmax + 1], sol[nmax * nmax], ff[nmax + 1], help[nmax * nmax];
bool used[nmax + 1];
int n, m, s, f, k, en, top, cou, ans;
tqueue queue[nmax + 1];
tmas fa[nmax + 1];

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
        if (queue[i].wei > queue[i / 2].wei)
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
        if (queue[k].wei < queue[i * 2].wei)
            k = i * 2;
        if (i * 2 + 1 <= top && queue[i * 2 + 1].wei > queue[k].wei)
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
    freopen("floyd.in", "r", stdin);
    freopen("floyd.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    For(i, 1, m)
    {
        int si, fi, pi;
        scanf("%d%d%d", &si, &fi, &pi);
        add(si, fi, pi);
    }
    scanf("%d", &s);
    f = s;
    bool fl = false;
    ans = 0;
    For(i, 1, k)
    {
        scanf("%d", &f);
        top = 1;
        For(i, 1, n)
            fa[i]
                .n.clear();
        memset(a1, 0, sizeof(a1));
        For(i, 1, n)
            a[i] = -INF;
        a[s] = 0;
        queue[1].nom = s;
        queue[1].wei = 0;
        while (top)
        {
            tqueue v = queue[1];
            swap(queue[1].nom, queue[top].nom);
            swap(queue[1].wei, queue[top].wei);
            swap(is[queue[i].nom], is[queue[top].nom]);
            is[v.nom] = 0;
            top--;
            shiftdown(1);
            int j = head[v.nom];
            while (j)
            {
                if (v.wei + list[j].wei > a[list[j].dest] && fa[v.nom].n.find(list[j].dest) != fa[v.nom].n.end())
                {
                    fl = true;
                    break;
                }
                if (v.wei + list[j].wei > a[list[j].dest] && fa[v.nom].n.find(list[j].dest) == fa[v.nom].n.end())
                {
                    fa[list[j].dest] = fa[v.nom];
                    fa[list[j].dest].n.insert(v.nom);
                    ff[list[j].dest] = v.nom;
                    a[list[j].dest] = v.wei + list[j].wei;
                    a1[list[j].dest] = j;
                    if (is[list[j].dest] == 0)
                    {
                        top++;
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
            if (fl)
                break;
        }
        if (fl)
            break;
        int c = f;
        cou = 0;
        while (c != s)
        {
            cou++;
            help[cou] = a1[c];
            c = ff[c];
        }
        while (cou)
        {
            ans++;
            sol[ans] = help[cou];
            cou--;
        }
        s = f;
    }
    if (fl)
        printf("infinitely kind\n");
    else
    {
        printf("%d\n", ans);
        For(i, 1, ans - 1)
            printf("%d ", sol[i]);
        if (ans != 0)
            printf("%d\n", sol[ans]);
    }
    /*srand(time(NULL));
	For(i,1,10000)
		if (i%2==0) printf("%d %d %d\n",rand()%100+1,rand()%100+1,rand()); else printf("%d %d %d\n",rand()%100+1,rand()%100+1,-rand());
	For(i,1,10000)
		printf("%d ",rand()%100+1);*/
    return 0;
}
