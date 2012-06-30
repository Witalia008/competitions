#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <time.h>
#define nmax 500
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

struct tlist
{
    int dest, next, time, wei;
};

struct tqueue
{
    int nom, wei, time;
};

tlist list[nmax * nmax];
tqueue queue[nmax + 1];
int head[nmax + 1], is[nmax + 1], a[nmax + 1];
int n, m, en, ans;
bool used[nmax + 1];

void add(int u, int v, int wei, int time)
{
    en++;
    list[en].dest = v;
    list[en].next = head[u];
    list[en].time = time;
    list[en].wei = wei;
    head[u] = en;
}

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

void dfs(int i, int cou, int t)
{
    used[i] = true;
    if (i == n)
    {
        if (cou > ans)
            ans = cou;
        return;
    }
    int j = head[i];
    while (j)
    {
        if (!used[list[j].dest] && t + list[j].time < 1440 && min(cou, list[j].wei) > ans)
            dfs(list[j].dest, min(cou, list[j].wei), t + list[j].time);
        j = list[j].next;
    }
    used[i] = false;
}

int main()
{
    freopen("cups.in", "r", stdin);
    freopen("cups.out", "w", stdout);
    scanf("%d%d", &n, &m);
    For(i, 1, m)
    {
        int si, fi, ti, wi;
        scanf("%d%d%d%d", &si, &fi, &ti, &wi);
        if (wi <= 3000000)
            wi = 0;
        else
            wi -= 3000000;
        add(si, fi, wi / 100, ti);
        add(fi, si, wi / 100, ti);
    }
    ans = 0;
    memset(used, 0, sizeof(used));
    dfs(1, 10000000, 0);
    printf("%d\n", ans);
    /*srand(time(NULL));
	For(i,1,124750)
		printf("%d %d %d %d\n",rand()%500+1,rand()%500+1,rand()&1440+1,rand()*rand());*/
    return 0;
}
