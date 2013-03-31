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
#define N 105
#define M 100000

typedef double ld;
typedef long long ll;
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
int sqr(int a) { return a * a; }

struct TList
{
    int dest, next;
};

int n, m, en;
TList List[M];
int Head[N], d[N];
int queue[M];
bool used[N], us[N];
ll Cnt[N], Cc[N];
vector<int> From[N];

void add(int u, int v)
{
    en++;
    List[en].dest = v;
    List[en].next = Head[u];
    Head[u] = en;
}

void findIn(int v)
{
    if (v == 1)
        Cnt[v] = 1;
    if (used[v])
        return;
    used[v] = true;
    for (int j = Head[v]; j; j = List[j].next)
        if (d[List[j].dest] == d[v] - 1)
        {
            findIn(List[j].dest);
            Cnt[v] += Cnt[List[j].dest];
            From[v].pb(List[j].dest);
        }
}

void findOut(int v)
{
    if (v == n)
        Cc[v] = 1;
    if (us[v])
        return;
    us[v] = true;
    for (int j = Head[v]; j; j = List[j].next)
        if (used[List[j].dest] && d[List[j].dest] == d[v] + 1)
        {
            findOut(List[j].dest);
            Cc[v] += Cc[List[j].dest];
        }
}

//#define debug
int main()
{
    // freopen ("input.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    REP(i, m)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    int qh = 0, qt = 1;
    queue[0] = 1;
    FOR(i, 2, n)
    d[i] = Inf;
    d[1] = 0;
    while (qh < qt)
    {
        int c = queue[qh++];
        for (int j = Head[c]; j; j = List[j].next)
            if (d[List[j].dest] > d[c] + 1)
            {
                d[List[j].dest] = d[c] + 1;
                queue[qt++] = List[j].dest;
            }
    }
    findIn(n);
    findOut(1);
    ld ans = 0;
#ifdef debug
    FOR(i, 1, n)
    {
        REP(j, From[i].size())
        cout << From[i][j] << " ";
        cout << endl;
    }
#endif
    FOR(v, 1, n)
    {
        ld prob = 1 / ld(Cnt[n]);
        ll cc = 0;
        FOR(i, 1, n)
        {
            REP(j, From[i].size())
            {
                int x = 0;
                if (i == v || From[i][j] == v)
                    x = 1;
#ifdef debug
                cout << i << " " << From[i][j] << " " << x << " " << Cnt[From[i][j]] << endl;
#endif
                cc += ll(x) * Cnt[From[i][j]] * Cc[i];
            }
        }
        prob *= ld(cc);
#ifdef debug
        cout << v << " " << cc << " " << prob << endl;
#endif
        if (prob > ans)
            ans = prob;
    }
    printf("%.7lf\n", ans);
    return 0;
}
