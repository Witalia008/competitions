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
#define N 1000005
#define K 100
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

ll Abs(ll x) { return x < 0 ? -x : x; }

bool prime[N];
ll step[K][K];
vi pr, st;
vector<ll> fa;
ll n, k;
int T, Q;

int bin_srch(int pos, ll a)
{
    int l = 0, r = st[pos];
    while (l < r - 1)
    {
        int mid = (l + r) >> 1;
        if (a % step[pos][mid] == 0)
            l = mid;
        else
            r = mid;
    }
    if (a % step[pos][r] == 0)
        return r;
    return l;
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //---------------FIND PRIME NIMBERS--------------//
    CLR(prime, true);
    for (int i = 2; i <= N; i++)
        if (prime[i])
        {
            pr.pb(i);
            if (i <= 1000)
                for (int j = i * i; j < N; j += i)
                    prime[j] = false;
        }
    //---------------FIND PRIME NIMBERS--------------//

    scanf("%lld%d", &n, &Q);

    //---------------FACTORISE N---------------------//
    REP(i, pr.size())
    if (n % pr[i] == 0)
    {
        fa.pb(pr[i]);
        st.pb(0);
        while (n % pr[i] == 0)
        {
            st[st.size() - 1]++;
            n /= pr[i];
        }
    }
    if (n != 1)
    {
        fa.pb(n);
        st.pb(1);
    }
    REP(i, fa.size())
    {
        step[i][0] = 1;
        FOR(j, 1, st[i])
        step[i][j] = step[i][j - 1] * fa[i];
    }
    //---------------FACTORISE N---------------------//

    REP(q, Q)
    {
        scanf("%d%lld", &T, &k);
        ll ans = 1, all = 1;
        REP(i, fa.size())
        {
            all *= ll(st[i] + 1);
            int x = bin_srch(i, k);
            k /= step[i][x];
            if (T == 1)
                ans *= ll(x + 1);
            else
                ans *= ll(st[i] - x + 1);
        }
        if (k != 1 && T != 1)
            ans = 0;
        if (T == 3)
            ans = all - ans;
        printf("%lld\n", ans);
    }
    return 0;
}
