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

#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define REP(i,n) for (int i = 0; i < (n); i++)
#define CLR(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define eps 10e-6
#define Inf 1000000000
#define Mi 1000000007
#define N 55
#define M 100000

typedef double ld;
typedef long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<double, char> pdc;

int min (int a, int b) {if (a < b) return a; return b;}
int Abs(int a) {if (a < 0) return -a; else return a;}
int sqr (int a) {return a*a;}

string a[N];
int n;
int mi[N][N][N][N];

bool can (string a, string b)
{
    return (a[0] == b[0] || a[1] == b[1]);
}

bool eq (pii x, pii y)
{
    return (a[x.first] == a[y.first] && a[x.second] == a[y.second]);
}

bool find (int n, int a1, int a2, int a3)
{
    if (n == 1) return true;
    if (a2 >= 0 && a3 >= 0 && mi[n][a1][a2][a3] != -1) return mi[n][a1][a2][a3];
    bool f1, f2;
    f1 = f2 = false;
    if (can(a[a1], a[a2]))
        f1 = find (n - 1, a1, a3, n - 4);
    if (n >= 4 && can (a[a1], a[n - 4]) && !eq(mp(a1, n-4), mp(a2, a1)))
        f2 = find (n - 1, a2, a3, a1);
    return mi[n][a1][a2][a3] = f1 || f2;
}

//#define debug
int main ()
{
   // freopen ("input.txt", "r", stdin);
   // freopen ("output.txt", "w", stdout);
    cin >> n;
    CLR(mi, -1);
    REP(i, n)
        cin >> a[i];
    if (find(n, n-1, n-2, n-3))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
