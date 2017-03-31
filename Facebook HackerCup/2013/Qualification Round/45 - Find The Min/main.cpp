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
#include <assert.h>
using namespace std;

#define For(i, a, b, d) for (int i = (a); i != (b); i += d)
#define FORD(i, a, b) for (int i = (a); i >= b; i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REPD(i, n) for (int i = (n - 1); i >= 0; i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(a) (a).begin(), (a).end()
#define CLR(a, x) memset(a, x, sizeof(a))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define Abs(a) ((a < 0) ? -(a) : a)
#define sqr(a) ((a) * (a))
#define pb push_back
#define mp make_pair
#define eps 10e-9
#define Inf 1000000000
#define Mi 1000000007
#define N 100005
#define K 1000

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

inline ll gcd(ll a, ll b) { return (!b ? a : gcd(b, a % b)); }

ll maxx(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}

const ld PI = 2 * acos(0.0);
const ll InfLL = ll(Inf) * ll(Inf);

int rand15() { return rand() % (1 << 15); }
int rand30() { return (rand15() << 15) + rand15(); }
int rand(int L, int R)
{
    if (L > R)
        return R;
    return rand30() % (R - L + 1) + L;
}
ld random(ld L, ld R) { return rand(ceil((L - eps) * 100), floor((R + eps) * 100)) / 100.0; }

//#define DEBUG

int T, n, k;
ll a, b, c, r;
ll m[N * 2];
int used[N];
set<int> S;

//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "wb", stdout);
#endif
    scanf("%d\n", &T);
    REP(_t, T)
    {
        printf("Case #%d: ", _t + 1);
        cin >> n >> k;
        cin >> a >> b >> c >> r;
        m[0] = a;
        FOR(i, 1, k - 1)
        m[i] = (b * m[i - 1] + c) % r;
#ifdef DEBUG_MODE
        REP(i, k)
        cout << m[i] << " ";
        cout << endl;
#endif
        S.clear();
        CLR(used, 0);
        REP(i, k)
        if (m[i] <= k)
            used[m[i]]++;
        REP(i, k + 1)
        if (!used[i])
            S.insert(i);
        REP(i, k + 1)
        {
            m[i + k] = *(S.begin());
            S.erase(S.begin());
            if (m[i] <= k)
            {
                used[m[i]]--;
                if (!used[m[i]])
                    S.insert(m[i]);
            }
        }
#ifdef DEBUG_MODE
        REP(i, 2 * k + 1)
        cout << m[i] << " ";
        cout << endl;
#endif
        printf("%d\n", m[k + (n - k - 1) % (k + 1)]);
    }
    return 0;
}
