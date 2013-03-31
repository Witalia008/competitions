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
#define N 1015
#define K 15
//#define debug

typedef double ld;
typedef long long ll;
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

const int mx[4] = {1, -1, 0, 0};
const int my[4] = {0, 0, 1, -1};

inline ll Abs(ll x) { return x < 0 ? -x : x; }
inline ll sqr(ll a) { return a * a; }
inline ll gcd(ll a, ll b) { return (!b ? a : gcd(b, a % b)); }

int A[30], B[30];

void count(string a, string b)
{
    CLR(A, 0);
    CLR(B, 0);
    REP(i, a.length())
    A[a[i] - 'a']++;
    REP(i, b.length())
    B[b[i] - 'a']++;
}

bool chef_check(string a, string b)
{
    count(a, b);
    REP(i, 30)
    if (A[i] * B[i] == 0 && A[i] + B[i] != 0)
        return false;
    return true;
}

bool my_check(string a, string b)
{
    count(a, b);
    REP(i, 30)
    if (A[i] != B[i])
        return false;
    return true;
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int _t;
    cin >> _t;
    REP(i, _t)
    {
        string a, b;
        cin >> a >> b;
        cout << (my_check(a, b) != chef_check(a, b) ? "NO" : "YES") << endl;
    }
    return 0;
}
