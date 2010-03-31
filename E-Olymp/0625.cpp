#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REPD(i, n) FORD(i, n - 1, 0)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define N 5005
#define M 100001

struct TList
{
    int dest, next, wei;
};

TList List[M * 2];
int Head[N], d[N], wh[N], from[N], Ans[N];
int n, m, s, f, en, top;
int queue[N];

void Add(int u, int v, int w)
{
    en++;
    List[en].dest = v;
    List[en].wei = w;
    List[en].next = Head[u];
    Head[u] = en;
}

void ShiftUp(int i)
{
    while (i > 1 && d[queue[i]] < d[queue[i / 2]])
    {
        swap(queue[i], queue[i / 2]);
        swap(wh[queue[i]], wh[queue[i / 2]]);
        i /= 2;
    }
}

void ShiftDown(int i)
{
    while (i * 2 <= top)
    {
        int k = i;
        if (d[queue[i * 2]] < d[queue[k]])
            k = i * 2;
        if (i * 2 + 1 <= top && d[queue[i * 2 + 1]] < d[queue[k]])
            k = i * 2 + 1;
        if (k == i)
            i = top;
        else
        {
            swap(queue[i], queue[k]);
            swap(wh[queue[i]], wh[queue[k]]);
            i = k;
        }
    }
}

void push(int v)
{
    queue[++top] = v;
    wh[v] = top;
    ShiftUp(top);
}

int pop()
{
    if (top)
    {
        swap(queue[1], queue[top]);
        wh[queue[1]] = wh[queue[top]];
        wh[queue[top]] = -1;
        --top;
        ShiftDown(1);
        return queue[top + 1];
    }
    return -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &s, &f);
    REP(i, m)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        Add(a, b, c);
        Add(b, a, c);
    }
    FOR(i, 1, n)
    d[i] = Inf,
    wh[i] = -1;
    d[s] = 0;
    wh[s] = 1;
    push(s);
    int v;
    while ((v = pop()) != -1)
    {
        if (v == f)
            break;
        int j = Head[v];
        while (j)
        {
            if (d[List[j].dest] > d[v] + List[j].wei)
            {
                d[List[j].dest] = d[v] + List[j].wei;
                from[List[j].dest] = v;
                if (wh[List[j].dest] == -1)
                    push(List[j].dest);
                else
                    ShiftUp(wh[List[j].dest]);
            }
            j = List[j].next;
        }
    }
    printf("%d\n", d[f]);
    int ans = 0;
    while (f)
    {
        Ans[ans++] = f;
        f = from[f];
    }
    REPD(i, ans)
    {
        printf("%d", Ans[i]);
        if (i)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}
