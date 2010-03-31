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

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define min(a, b) (a < b) ? a : b;
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 1000000007
#define N 60005

typedef long double ld;
typedef unsigned long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;

int Abs(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

struct xx
{
    string name;
    int a, b, c, v;
};

bool comp(xx a, xx b)
{
    return a.v < b.v;
}

xx A[105];

int main()
{
    //freopen ("input.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
    int T;
    cin >> T;
    REP(t, T)
    {
        int n;
        cin >> n;
        REP(i, n)
        {
            cin >> A[i].name >> A[i].a >> A[i].b >> A[i].c;
            A[i].v = A[i].a * A[i].b * A[i].c;
        }
        bool fl = false;
        REP(i, n)
        if (i && A[i].v != A[i - 1].v)
            fl = true;
        printf("Case %d: ", t + 1);
        if (!fl)
            printf("no thief\n");
        else
        {
            sort(A, A + n, &comp);
            cout << A[n - 1].name << " took chocolate from " << A[0].name << endl;
        }
    }
    return 0;
}
