#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <list>
#include <fstream>
#include <time.h>
#include <iomanip>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define CLR(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define mp make_pair
#define eps 10e-6
#define Inf 1000000000
#define Mi 1000000007
#define N 1005

typedef double ld;
typedef unsigned long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<double, char> pdc;

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}
int Abs(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

struct TList
{
    int dest, next, wei;
};

int n, m, en;
TList List[1000];
int d[20], cnt[20], Head[20];
int queue[100000];

void add(int u, int v, int w)
{
    en++;
    List[en].dest = v;
    List[en].wei = w;
    List[en].next = Head[u];
    Head[u] = en;
}

void get(int v)
{
    if (cnt[v])
        return;
    if (v == 1)
    {
        cnt[v] = 1;
        return;
    }
    for (int j = Head[v]; j; j = List[j].next)
        if (d[List[j].dest] + List[j].wei == d[v])
        {
            get(List[j].dest);
            cnt[v] += cnt[List[j].dest];
        }
}

//#define debug
int main()
{
    // freopen ("input.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    REP(t, T)
    {
        CLR(cnt, 0);
        CLR(Head, 0);
        en = 0;
        scanf("%d%d", &n, &m);
        REP(i, m)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
            add(b, a, c);
        }
        FOR(i, 1, n)
        d[i] = Inf;
        d[1] = 0;
        int qt = 1, qh = 0;
        queue[0] = 1;
        while (qh < qt)
        {
            int v = queue[qh++];
            for (int j = Head[v]; j; j = List[j].next)
                if (List[j].wei + d[v] < d[List[j].dest])
                {
                    d[List[j].dest] = d[v] + List[j].wei;
                    queue[qt++] = List[j].dest;
                }
        }
#ifdef debug
        REP(i, n)
        cout << d[i + 1] << " ";
#endif
        get(n);
        printf("%d\n", cnt[n]);
    }
    return 0;
}
