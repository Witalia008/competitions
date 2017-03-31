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

#define For(i,a,b,d) for (int i = (a); i != (b); i += d)
#define FORD(i,a,b) for (int i = (a); i >= b; i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REPD(i,n) for (int i = (n - 1); i >= 0; i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
#define CLR(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define eps 10e-3
#define Inf 1000000000
#define Mi 29
#define N 101
#define K 11
//#define debug

typedef double ld;
typedef long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<double, char> pdc;
typedef enum {heavy, light} lbl;

ll max (ll a, ll b) {if (a>b) return a; return b;}
int min (int a, int b) {if (a < b) return a; return b;}
int Abs(int a) {if (a < 0) return -a; else return a;}
ld Abs (ld a) {if (a < 0) return -a; else return a;}
int sqr (int a) {return a*a;}

int power (int a, int k)
{
    if (!k) return 1;
    int res = power (a, k / 2);
    res = res * res;
    if (k & 1) res *= a;
    return res % Mi;
}

int func (int pr, int a)
{
    int x = (power (pr, a + 1) - 1 + Mi) % Mi;
    int b = power (pr - 1, Mi - 2);
    return (x * b) % Mi;
}

#define ONLINE_JUDGE
int main ()
{
    #ifndef ONLINE_JUDGE
        freopen ("input.txt", "r", stdin);
        freopen ("output.txt", "w", stdout);
    #endif
    while (true)
    {
        int x;
        scanf ("%d", &x);
        if (!x) break;
        int ans = func (2, 2 * x);
        ans = (ans * func (3, x)) % Mi;
        ans = (ans * func (167, x)) % Mi;
        printf ("%d\n", ans);
    }
    return 0;
}
