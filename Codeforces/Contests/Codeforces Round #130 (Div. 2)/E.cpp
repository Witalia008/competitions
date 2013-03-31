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
#define N 100005

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
TList List[N];
int Head[N], P[N];
int anc[N][20];
int deph[N], cnt[N];
vi level[N];
vi tops;
int tout[N];
bool used[N];

void add(int u, int v)
{
    en++;
    List[en].dest = v;
    List[en].next = Head[u];
    Head[u] = en;
}

void dfs(int v, int p = -1)
{
    deph[v] = (p == -1) ? (0) : (deph[p] + 1);
    anc[v][0] = p == -1 ? v : p;
    FOR(i, 1, 19)
    anc[v][i] = anc[anc[v][i - 1]][i - 1];
    cnt[v] = 1;
    for (int j = Head[v]; j; j = List[j].next)
    {
        dfs(List[j].dest, v);
        cnt[v] += cnt[List[j].dest];
    }
    tout[v] = tops.size();
    tops.pb(v);
}

int get_anc(int v, int p)
{
    if (deph[v] < p)
        return -1;
    for (int i = 19; i >= 0; i--)
        if (p >= (1 << i))
            p -= (1 << i), v = anc[v][i];
    return v;
}

int bin_search(int h, int wh)
{
    int l = 0, r = level[h].size() - 1;
    while (l < r - 1)
    {
        int mid = (l + r) >> 1;
        if (tout[level[h][mid]] >= tout[wh])
            r = mid;
        else
            l = mid;
    }
    if (tout[level[h][r]] < tout[wh])
        return r;
    if (tout[level[h][l]] < tout[wh])
        return l;
    return -1;
}

//#define debug
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n)
    {
        scanf("%d", &P[i]);
        if (P[i])
            add(P[i], i);
    }
    FOR(i, 1, n)
    if (!P[i])
        dfs(i);
#ifdef debug
    FOR(i, 1, n)
    {
        cout << i << " ->> ";
        for (int j = Head[i]; j; j = List[j].next)
            cout << List[j].dest << ", ";
        cout << endl;
    }
#endif
    REP(i, n)
    level[deph[tops[i]]].pb(tops[i]);
    scanf("%d", &m);
#ifdef debug
    REP(i, n)
    cout << tops[i] << " ";
    cout << endl;
#endif
    REP(i, m)
    {
        int v, p;
        scanf("%d%d", &v, &p);
        int u = get_anc(v, p);
#ifdef debug
        cout << u << " ";
#endif
        if (i)
            printf(" ");
        if (u == -1)
            printf("0");
        else
        {
            printf("%d", bin_search(deph[v], u) - bin_search(deph[v], tops[tout[u] - cnt[u] + 1]) - 1);
#ifdef debug
            cout << " " << bin_search(deph[v], u) << " " << bin_search(deph[v], tops[tout[u] - cnt[u] + 1]) << " ";
#endif
        }
#ifdef debug
        //cout << " " << u << " " << tops[tout[u] - cnt[u] + 1] << " " << cnt[u];
        cout << endl;
#endif
    }
    printf("\n");
    return 0;
}
