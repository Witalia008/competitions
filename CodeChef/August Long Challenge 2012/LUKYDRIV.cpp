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
#define eps 10e-10
#define Inf 1000000000
#define Mi 1000000007
#define N 10006
#define K 16
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
ll sqr (ll a) {return a*a;}
ld sqr (ld a) {return a*a;}

char s[N];
int n, T;
ll ans;
ll C[10];
ll cnt[10];

void search (int pos, ll cur, int nom, int last = 0)
{
    if (nom && nom % 9 == 0) ans = (ans + cur) % Mi;
    if (pos == 4) return;
    FOR(i, last, 9)
        if (C[i])
        {
            cur *= C[i];
            C[i]--;
            cnt[i]++;
            cur /= cnt[i];
            search (pos + 1, cur, nom * 10 + i, i);
            C[i]++;
            cur *= cnt[i];
            cnt[i]--;
            cur /= C[i];
        }
}

//#define ONLINE_JUDGE
int main ()
{
    #ifndef ONLINE_JUDGE
        freopen ("input.txt", "r", stdin);
        freopen ("output.txt", "w", stdout);
    #endif
    scanf ("%d\n", &T);
    REP(t, T)
    {
        scanf ("%s", &s);
        int n = strlen(s);
        CLR(C, 0);
        REP(i, n) C[s[i]-'0']++;
        ans = 0;
        search (0, 1, 0);
        printf ("%d\n", ans);
    }
    return 0;
}
