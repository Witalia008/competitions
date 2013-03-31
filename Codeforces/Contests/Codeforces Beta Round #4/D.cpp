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
#define eps 10e-3
#define Inf 1000000000
#define Mi 1000000007
#define N 5001
#define K 26
//#define debug

typedef double ld;
typedef unsigned long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<double, char> pdc;
typedef enum
{
    heavy,
    light
} lbl;

pair<pii, int> a[N];
vi Ans;
int prev[N];
int F[N];
int n;
pii st;

bool cmp(pair<pii, int> a, pair<pii, int> b)
{
    return a.first.first < b.first.first || a.first.first == b.first.first && a.first.second < b.first.second;
}

inline bool canIn(pii a, pii b)
{
    return a.first < b.first && a.second < b.second;
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &st.first, &st.second);
    REP(i, n)
    {
        a[i].second = i;
        scanf("%d%d", &a[i].first.first, &a[i].first.second);
    }
    sort(a, a + n, &cmp);
    int ans = 0;
    REP(i, n)
    {
        prev[i] = -1;
        if (canIn(st, a[i].first))
            F[i] = 1;
        REP(j, i)
        if (canIn(a[j].first, a[i].first) && F[j] + 1 > F[i] && F[j])
        {
            F[i] = F[j] + 1;
            prev[i] = j;
        }
        if (F[i] > F[ans])
            ans = i;
    }
    printf("%d\n", F[ans]);
    if (F[ans])
    {
        do
        {
            Ans.pb(a[ans].second + 1);
            ans = prev[ans];
        } while (ans != -1);
        reverse(Ans.begin(), Ans.end());
        REP(i, Ans.size())
        {
            if (i)
                printf(" ");
            printf("%d", Ans[i]);
        }
        printf("\n");
    }
    return 0;
}
