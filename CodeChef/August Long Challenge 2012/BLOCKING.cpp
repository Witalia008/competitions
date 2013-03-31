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
#define Mi 1000000007
#define N 101
#define K 21
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
ll Abs(ll a) {if (a < 0) return -a; else return a;}
ld Abs (ld a) {if (a < 0) return -a; else return a;}
ll sqr (ll a) {return a*a;}

int n;
int A[N][N];
priority_queue<pii> Q[N];
int mx[N], my[N];

//#define ONLINE_JUDGE
int main ()
{
    #ifndef ONLINE_JUDGE
        freopen ("input.txt", "r", stdin);
        freopen ("output.txt", "w", stdout);
    #endif
    scanf ("%d", &n);
    REP(i, n)
        REP(j, n)
        {
            scanf ("%d", &A[i][j]);
            Q[i].push(mp(-A[i][j], j));
        }
    CLR(mx, -1);
    CLR(my, -1);
    int pairs = 0;
    while (pairs != n)
    {
        REP(i, n)
            while (mx[i] == -1)
            {
                int cur = -Q[i].top().first;
                int j = Q[i].top().second;
                if (my[j] == -1)
                {
                    my[j] = i;
                    mx[i] = j;
                    pairs++;
                } else
                if (A[i][j] > A[my[j]][j])
                {
                    mx[my[j]] = -1;
                    my[j] = i;
                    mx[i] = j;
                }
                Q[i].pop();
            }
    }
    REP(i, n)
    {
        if (i) printf (" ");
        printf ("%d", mx[i] + 1);
    }
    printf ("\n");
    return 0;
}
