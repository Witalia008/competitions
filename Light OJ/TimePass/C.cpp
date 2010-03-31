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
#include <queue>
#include <stack>

using namespace std;

#define For(i, a, b, d) for (int i = (a); i != (b); i += d)
#define FORD(i, a, b) for (int i = (a); i >= b; i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REPD(i, n) for (int i = (n - 1); i >= 0; i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define CLR(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define mp make_pair
#define eps 10e-10
#define Inf 1000000000
#define Mi 1000000007
#define N 33000
//#define debug

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
ld Abs(ld a)
{
    if (a < 0)
        return -a;
    else
        return a;
}
ll sqr(ll a) { return a * a; }
ld sqr(ld a) { return a * a; }

struct TList
{
    int dest, next, wei;
};

int n, m, en, s;
TList List[N];
int Head[N];
int Q[N], d[N];

void add(int u, int v, int w)
{
    en++;
    List[en].dest = v;
    List[en].wei = w;
    List[en].next = Head[u];
    Head[u] = en;
}

int main()
{
    int T;
    scanf("%d", &T);
    REP(t, T)
    {
        scanf("%d%d", &n, &m);
        en = 0;
        CLR(Head, 0);
        printf("Case %d:\n", t + 1);
        REP(i, m)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a++;
            b++;
            add(a, b, c);
            add(b, a, c);
        }
        FOR(i, 1, n)
        d[i] = Inf;
        scanf("%d", &s);
        d[++s] = 0;
        int qh = 0, qt = 1;
        Q[0] = s;
        while (qh < qt)
        {
            int v = Q[qh++];
            for (int j = Head[v]; j; j = List[j].next)
                if (d[List[j].dest] > max(d[v], List[j].wei))
                {
                    Q[qt++] = List[j].dest;
                    d[List[j].dest] = max(d[v], List[j].wei);
                }
        }
        FOR(i, 1, n)
        if (d[i] == Inf)
            printf("Impossible\n");
        else
            printf("%d\n", d[i]);
    }
    return 0;
}
