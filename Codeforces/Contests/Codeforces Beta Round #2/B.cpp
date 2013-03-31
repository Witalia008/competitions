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
#include <complex>
//#include <assert.h>

using namespace std;

#define For(i, a, b, d) for (int i = (a); i != (b); i += d)
#define FORD(i, a, b) for (int i = (a); i >= b; i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REPD(i, n) for (int i = (n - 1); i >= 0; i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(a) (a).begin(), (a).end()
#define CLR(a, x) memset(a, x, sizeof(a))
#define debug(x) cout << #x << "=" << x << endl;
#define pb push_back
#define mp make_pair

typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
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

const int Inf = 1e9;
const int Mi = Inf + 7;
const int N = 1005;
const int K = 32;
const ld eps = 10e-6;
const ld PI = 2 * acos(0.0);
const ll InfLL = ll(Inf) * ll(Inf);

inline ll gcd(ll a, ll b) { return (!b ? a : gcd(b, a % b)); }

int rand15() { return rand() % (1 << 15); }
int rand30() { return (rand15() << 15) + rand15(); }
int rand(int L, int R)
{
    if (L > R)
        return R;
    return rand30() % (R - L + 1) + L;
}
ld random(ld L, ld R) { return rand(ceil((L - eps) * 100), floor((R + eps) * 100)) / 100.0; }

template <typename __T>
__T Abs(__T a)
{
    return a < 0 ? -a : a;
}

template <typename __T>
__T sqr(__T a)
{
    return a * a;
}

//#define DEBUG

int n;
int A[N][N];
int F[N][N][2];
int fr[N][N][2];

//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main()
{
    std::ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    string zero = "";
    REP(i, n)
    {
        REP(j, n)
        {
            scanf("%d", &A[i][j]);
            if (A[i][j] == 0 && zero == "")
            {
                REP(k, i)
                zero += 'D';
                REP(k, n - 1)
                zero += 'R';
                REP(k, n - i - 1)
                zero += 'D';
            }
            F[i][j][0] = F[i][j][1] = Inf;
            REP(k, 2)
            {
                if (i && F[i][j][k] > F[i - 1][j][k])
                {
                    F[i][j][k] = F[i - 1][j][k];
                    fr[i][j][k] = 1;
                }
                if (j && F[i][j][k] > F[i][j - 1][k])
                {
                    F[i][j][k] = F[i][j - 1][k];
                    fr[i][j][k] = 2;
                }
            }
            int cnt[2];
            CLR(cnt, 0);
            for (int k = 2; k <= 5; k += 3)
            {
                if (F[i][j][k / 5] == Inf)
                    F[i][j][k / 5] = 0;
                while (A[i][j] && A[i][j] % k == 0)
                {
                    cnt[k / 5]++;
                    A[i][j] /= k;
                }
                if (!A[i][j])
                    cnt[0] = cnt[1] = 1;
                F[i][j][k / 5] += cnt[k / 5];
            }
        }
    }
    int r_k = 0;
    if (F[n - 1][n - 1][1] < F[n - 1][n - 1][0])
    {
        r_k = 1;
    }
    if (F[n - 1][n - 1][r_k] > 1 && zero != "")
    {
        cout << 1 << endl;
        cout << zero << endl;
        return 0;
    }
    cout << F[n - 1][n - 1][r_k] << endl;
    string ans = "";
    int i = n - 1, j = n - 1;
    while (i > 0 || j > 0)
    {
        if (fr[i][j][r_k] == 1)
        {
            ans += 'D';
            i--;
        }
        else
        {
            ans += 'R';
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
