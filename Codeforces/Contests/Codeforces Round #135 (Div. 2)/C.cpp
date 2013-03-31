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
#define N 1000001
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

int n, k;
string s, ans;

int get(string a)
{
    int res = 0;
    REP(i, s.length())
    if (a[i] != s[i])
        res++;
    return res;
}

string c1, c2;

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> k;
    cin >> s;
    if (k == 2)
    {
        c1 = c2 = "";
        REP(i, n)
        if (i & 1)
            c1 += 'A', c2 += 'B';
        else
            c1 += 'B', c2 += 'A';
        if (get(c1) < get(c2))
            cout << get(c1) << endl
                 << c1 << endl;
        else
            cout << get(c2) << endl
                 << c2 << endl;
        return 0;
    }
    ans = s;
    REP(i, n)
    if (i && ans[i] == ans[i - 1])
    {
        ans[i] = 'A';
        while (ans[i] == ans[i - 1] || (i + 1 < n && ans[i] == ans[i + 1]))
            ans[i]++;
    }
    cout << get(ans) << endl
         << ans << endl;
    return 0;
}
