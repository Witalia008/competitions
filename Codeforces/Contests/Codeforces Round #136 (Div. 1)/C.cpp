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
#define N 100005
#define K 3
//#define debug

typedef double ld;
typedef long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<double, char> pdc;
typedef enum {heavy, light} lbl;

multiset<int> s;
int b[N], pos[N];
int n;

//#define ONLINE_JUDGE
int main ()
{
    #ifndef ONLINE_JUDGE
        freopen ("input.txt", "r", stdin);
        freopen ("output.txt", "w", stdout);
    #endif
    scanf ("%d", &n);
    REP(i, n)
    {
        scanf ("%d", b + i);
        pos[b[i]] = i;
    }
    s.clear();
    REP(i, n)
    {
        scanf ("%d", b + i);
        s.insert (i - pos[b[i]]);
    }
    REP(i, n)
    {
        multiset<int> ::iterator it;
        it = s.lower_bound(i);
        int ans = Inf;
        if (it != s.end()) ans = min (ans, *it - i);
        if (it != s.begin()) ans = min (ans, i - *(--it));
        printf ("%d\n", ans);
        s.erase (s.find(i - pos[b[i]]));
        s.insert (i + n - pos[b[i]]);
    }
    return 0;
}
