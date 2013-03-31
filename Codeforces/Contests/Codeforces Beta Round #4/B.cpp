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
#define N 200001
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

pii a[50];
int ans[50];
int n, st;

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> st;
    REP(i, n)
    cin >> a[i].first >> a[i].second;
    int smin, smax;
    smin = smax = 0;
    REP(i, n)
    {
        smin += a[i].first;
        smax += a[i].second;
    }
    if (st < smin || st > smax)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    REP(i, n)
    {
        st -= a[i].first;
        ans[i] = a[i].first;
    }
    while (st)
    {
        int i = 0;
        while (ans[i] == a[i].second)
            i++;
        ans[i]++;
        st--;
    }
    REP(i, n)
    {
        if (i)
            printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
