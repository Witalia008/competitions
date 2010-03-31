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
#define eps 10e-6
#define Inf 1000000000
#define Mi 1000000007
#define N 30001
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

int n, T;
int A[N];
int L[N], R[N];
ll ans;
stack<pii> st;

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &T);
    REP(t, T)
    {
        scanf("%d", &n);
        REP(i, n)
        scanf("%d", &A[i]);
        ans = 0;
        while (!st.empty())
            st.pop();
        REP(i, n)
        {
            while (!st.empty() && st.top().first >= A[i])
                st.pop();
            if (st.empty())
                L[i] = -1;
            else
                L[i] = st.top().second;
            st.push(mp(A[i], i));
        }
        while (!st.empty())
            st.pop();
        REPD(i, n)
        {
            while (!st.empty() && st.top().first >= A[i])
                st.pop();
            if (st.empty())
                R[i] = n;
            else
                R[i] = st.top().second;
            st.push(mp(A[i], i));
        }
        REP(i, n)
        {
            ll cur = ll(A[i]) * ll(R[i] - L[i] - 1);
            ans = max(ans, cur);
        }
        printf("Case %d: ", t + 1);
        cout << ans << endl;
    }
    return 0;
}
