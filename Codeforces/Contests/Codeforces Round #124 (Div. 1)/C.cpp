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

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define CLR(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define mp make_pair
#define eps 10e-6
#define Inf 1000000000
#define Mi 1000000007
#define N 1505
//#define debug

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
ll sqr(ll a) { return a * a; }
ld sqr(ld a) { return a * a; }
struct TList
{
    int dest, next;
};

struct pt
{
    int nom;
    ll x, y;
    ld ang;
};

bool cmp_a(pt a, pt b) { return a.ang < b.ang; }
bool cmp_y(pt a, pt b) { return a.y < b.y || a.y == b.y && a.x < b.x; }

int n, en;
TList List[N * 2];
int Head[N];
pt A[N];
int Cnt[N], Ans[N];

void add(int u, int v)
{
    en++;
    List[en].dest = v;
    List[en].next = Head[u];
    Head[u] = en;
}

void dfs(int v, int p = -1)
{
    Cnt[v] = 1;
    for (int j = Head[v]; j; j = List[j].next)
        if (List[j].dest != p)
        {
            dfs(List[j].dest, v);
            Cnt[v] += Cnt[List[j].dest];
        }
}

void rec(int v, int l, int r, int p = -1)
{
    sort(A + l, A + r + 1, &cmp_y);
    Ans[A[l].nom] = v;
    FOR(i, l + 1, r)
    A[i].ang = atan2(ld(A[i].y - A[l].y), ld(A[i].x - A[l].x));
    sort(A + l + 1, A + r + 1, &cmp_a);
#ifdef debug
    cout << v << endl;
    FOR(i, l, r)
    {
        cout << A[i].x << " " << A[i].y << " " << A[i].nom;
        printf(" %.6lf\n", A[i].ang);
    }
    cout << endl;
#endif
    int ll = l + 1;
    for (int j = Head[v]; j; j = List[j].next)
        if (List[j].dest != p)
        {
            rec(List[j].dest, ll, ll + Cnt[List[j].dest] - 1, v);
            ll += Cnt[List[j].dest];
        }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    REP(i, n - 1)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    REP(i, n)
    {
        cin >> A[i].x >> A[i].y;
        A[i].nom = i;
    }
    dfs(1);
    rec(1, 0, n - 1);
    REP(i, n)
    {
        if (i)
            printf(" ");
        printf("%d", Ans[i]);
    }
    printf("\n");
    return 0;
}
