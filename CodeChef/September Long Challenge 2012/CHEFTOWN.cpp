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
#define N 400005
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

deque<int> qmin, qmax;
int A[N];
int n, k, ans;

#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    REP(i, n)
    {
        scanf("%d", &A[i]);
        while (!qmin.empty() && qmin.back() > A[i])
            qmin.pop_back();
        while (!qmax.empty() && qmax.back() < A[i])
            qmax.pop_back();
        qmin.push_back(A[i]);
        qmax.push_back(A[i]);
        if (i >= k)
        {
            if (A[i - k] == qmin.front())
                qmin.pop_front();
            if (A[i - k] == qmax.front())
                qmax.pop_front();
        }
        if (i >= k - 1)
        {
            int up = qmax.front();
            int low = qmin.front();
            if (up - low + 1 == k)
                ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
