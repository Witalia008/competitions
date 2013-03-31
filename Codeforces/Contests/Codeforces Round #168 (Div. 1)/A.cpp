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
#include <bitset>
//#include <assert.h>
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
#define K 155

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

int n, k;
int A[N];
int F[N][2];
map<int, int> M;

int bin_srch(int l, int r, int a)
{
    while (l < r - 1)
    {
        int mid = (l + r) >> 1;
        if (A[mid] > a)
            r = mid;
        else
            l = mid;
    }
    if (A[l] == a)
        return l;
    if (A[r] == a)
        return r;
    return -1;
}

//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main()
{
    std::ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "wb", stdout);
#endif
    scanf("%d%d", &n, &k);
    REP(i, n)
    scanf("%d", &A[i]);
    sort(A, A + n);
    REP(i, n)
    {
        int a = A[i];
        if (k != 1)
        {
            while (a % k == 0)
            {
                a /= k;
                int x = bin_srch(0, i - 1, a);
                if (x != -1)
                {
                    F[i][1] = max(F[x][0], F[i][1]);
                    if (a * k < A[i])
                        F[i][1] = max(F[i][1], F[x][1]);
                    F[i][0] = max(F[x][0], F[i][0]);
                    F[i][0] = max(F[x][1], F[i][0]);
                }
            }
        }
        F[i][1]++;
        if (!M[a])
            M[a] = 0;
        M[a] = max(M[a], max(F[i][0], F[i][1]));
    }
    int ans = 0;
    REP(i, n)
    {
        int a = A[i];
        if (k != 1)
            while (a % k == 0)
                a /= k;
        ans += M[a];
        M[a] = 0;
    }
    cout << ans << endl;
    return 0;
}
