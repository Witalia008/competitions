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

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define CLR(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define mp make_pair
#define eps 10e-6
#define Inf 1000000000
#define Mi 1000000007
#define N 400005
#define p 31
#define debug

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
ll sqr(ll a) { return a * a; }
ld sqr(ld a) { return a * a; }

int d, n;
string s, ans;
ll L[N], R[N], P[N];

bool palin(int i, int l)
{
    if (++i < l)
        return false;
    ll hash1 = L[i] - L[i - l];
    ll hash2 = (R[i] - P[l] * R[i - l]) * P[i - l];
    return hash1 == hash2;
}

bool dfs(int i, bool eq)
{
    if (i == n)
        return true;
    for (ans[i] = (eq ? s[i] : 'a'); ans[i] <= 'z'; ans[i]++)
    {
        L[i + 1] = L[i] + P[i] * (ans[i] - 'a' + 1);
        R[i + 1] = R[i] * p + ans[i] - 'a' + 1;
        if (!palin(i, d) && !palin(i, d + 1) && dfs(i + 1, eq && (ans[i] == s[i])))
            return true;
    }
    return false;
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> d;
    cin >> s;
    ans = s;
    n = s.length();
    P[0] = 1;
    REP(i, n)
    if (i)
        P[i] = P[i - 1] * ll(p);
    int ii;
    for (ii = n - 1; ii >= 0 && s[ii] == 'z'; ii--)
        s[ii] = 'a';
    if (ii < 0)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    else
        s[ii]++;
    if (dfs(0, true))
        cout << ans << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}
