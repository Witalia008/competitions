#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <time.h>
#define INF 1000000000
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

struct tlist
{
    int dest, next, wei;
};

struct tqueue
{
    int wei, nom, k;
};

tlist list[200001];
int head[101], a[101]; //,is[101];
int n, m, k, s, f, en, top;
tqueue queue[100001];

void add(int u, int v, int we)
{
    en++;
    list[en].dest = v;
    list[en].next = head[u];
    head[u] = en;
    list[en].wei = we;
}

void swap(tqueue &a, tqueue &b)
{
    tqueue t = a;
    a = b;
    b = t;
}

void shiftup(int i)
{
    while (i > 1)
        if (queue[i].wei < queue[i / 2].wei || (queue[i].wei == queue[i / 2].wei && queue[i].k > queue[i / 2].k))
        {
            swap(queue[i], queue[i / 2]);
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
        if (queue[k].wei == queue[i * 2].wei && queue[k].k < queue[i * 2].k)
            k = i * 2;
        if (i * 2 + 1 <= top)
        {
            if (queue[i * 2 + 1].wei < queue[k].wei)
                k = i * 2 + 1;
            if (queue[k].wei == queue[i * 2 + 1].wei && queue[k].k < queue[i * 2 + 1].k)
                k = i * 2 + 1;
        }
        if (k == i)
            i = top + 1;
        else
        {
            swap(queue[i], queue[k]);
            i = k;
        }
    }
}

int main()
{
    freopen("avia.in", "r", stdin);
    freopen("avia.out", "w", stdout);
    scanf("%d%d%d%d%d", &n, &m, &k, &s, &f);
    en = 0;
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
    //memset(is,0,sizeof(is));
    //is[s]=1;
    top = 1;
    queue[1].k = k;
    queue[1].nom = s;
    while (top)
    {
        tqueue v = queue[1];
        swap(queue[1], queue[top]);
        top--;
        shiftdown(1);
        int j = head[v.nom];
        if (v.k != 0)
            while (j)
            {
                if (a[list[j].dest] > v.wei + list[j].wei)
                {
                    /*if (is[list[j].dest]==0 || queue[is[list[j].dest]].k>v.k-1)
				{*/
                    top++;
                    queue[top].k = v.k - 1;
                    queue[top].nom = list[j].dest;
                    queue[top].wei = v.wei + list[j].wei;
                    a[list[j].dest] = queue[top].wei;
                    //is[list[j].dest]=top;
                    shiftup(top);
                    /*} else
				{
					queue[is[list[j].dest]].k=v.k-1;
					queue[is[list[j].dest]].wei=v.wei+list[j].wei;
				}*/
                }
                j = list[j].next;
            }
    }
    if (a[f] == INF)
        printf("-1\n");
    else
        printf("%d\n", a[f]);
    /*printf("100 100000 63 1 100\n");
	srand(time(NULL));
	For(i,1,100000)
		printf("%d %d %d\n",rand()%100+1,rand()%100+1,rand());*/
    return 0;
}
