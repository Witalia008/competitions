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
#define K 105

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

struct pt
{
    int x, y;
};

int get_pos_coord(int C[], int l, int r, int x)
{
    while (l < r - 1)
    {
        int mid = (l + r) >> 1;
        if (x == C[mid])
            return mid;
        if (x < C[mid])
            r = mid;
        else
            l = mid;
    }
    if (C[l] == x)
        return l;
    return r;
}

typedef pair<int, char> my_struct;

bool cmp(my_struct a, my_struct b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int count_len(vector<my_struct> &cur, int len)
{
    int ans, prev, bal;
    prev = ans = bal = 0;
    REP(i, cur.size())
    {
        if (cur[i].first > len)
            break;
        if (cur[i].second == 'l')
        {
            if (!bal)
                prev = cur[i].first;
            bal++;
        }
        else
        {
            bal--;
            if (!bal)
                ans += cur[i].first - prev;
        }
    }
    if (bal)
        ans += len - prev;
    return len - ans;
}

int get_max_coord(vector<my_struct> &cur, int l, int r, int cnt)
{
    while (l < r - 1)
    {
        int mid = (l + r) >> 1;
        if (count_len(cur, mid) >= cnt)
            r = mid;
        else
            l = mid;
    }
    if (count_len(cur, l) == cnt)
        return l;
    return r;
}

int n, m, k;
vector<my_struct> gor[N], ver[N];
int len_x[N], len_y[N];
pair<pt, pt> A[N];
int X[N], Y[N];
int nX[N], nY[N];
int cx, cy;

//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main()
{
    std::ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "wb", stdout);
#endif
    scanf("%d%d%d", &n, &m, &k);
    REP(i, k)
    {
        pt s, f;
        scanf("%d%d%d%d", &s.x, &s.y, &f.x, &f.y);
        A[i] = mp(s, f);
        if (s.x == f.x)
            X[cx++] = s.x;
        else
            Y[cy++] = s.y;
    }
    sort(X, X + cx);
    sort(Y, Y + cy);
    FOR(i, 1, cx - 1)
    nX[i] = nX[i - 1] + (X[i] != X[i - 1]);
    FOR(i, 1, cy - 1)
    nY[i] = nY[i - 1] + (Y[i] != Y[i - 1]);
    int used_x = (cx ? nX[cx - 1] + 1 : 0), used_y = (cy ? nY[cy - 1] + 1 : 0);
    int not_used_x = n + 1 - used_x, not_used_y = m + 1 - used_y;
    int res_x = (not_used_x & 1) ? m : 0;
    int res_y = (not_used_y & 1) ? n : 0;
    REP(i, k)
    {
        if (A[i].first.x == A[i].second.x)
        {
            A[i].first.x = nX[get_pos_coord(X, 0, cx - 1, A[i].first.x)];
            if (A[i].first.y > A[i].second.y)
                swap(A[i].first.y, A[i].second.y);
            ver[A[i].first.x].push_back(mp(A[i].first.y, 'l'));
            ver[A[i].first.x].push_back(mp(A[i].second.y, 'r'));
        }
        else
        {
            A[i].first.y = nY[get_pos_coord(Y, 0, cy - 1, A[i].first.y)];
            if (A[i].first.x > A[i].second.x)
                swap(A[i].first.x, A[i].second.x);
            gor[A[i].first.y].push_back(mp(A[i].first.x, 'l'));
            gor[A[i].first.y].push_back(mp(A[i].second.x, 'r'));
        }
    }
    REP(i, used_x)
    {
        sort(ver[i].begin(), ver[i].end(), &cmp);
        len_x[i] = m - count_len(ver[i], m);
        res_x ^= (m - len_x[i]);
    }
    REP(i, used_y)
    {
        sort(gor[i].begin(), gor[i].end(), &cmp);
        len_y[i] = n - count_len(gor[i], n);
        res_y ^= (n - len_y[i]);
    }
    int ans = res_x ^ res_y;
    if (ans)
    {
        cout << "FIRST" << endl;
        REP(i, used_x)
        {
            int poss = m - len_x[i];
            if ((ans ^ poss) <= poss)
            {
                int cur = poss - (ans ^ poss);
                int ccx = X[get_pos_coord(nX, 0, cx - 1, i)];
                cout << ccx << " 0 ";
                cout << ccx << " " << get_max_coord(ver[i], 0, m, cur) << endl;
                return 0;
            }
        }
        REP(i, used_y)
        {
            int poss = n - len_y[i];
            if ((ans ^ poss) <= poss)
            {
                int cur = poss - (ans ^ poss);
                int ccy = Y[get_pos_coord(nY, 0, cy - 1, i)];
                cout << "0 " << ccy;
                cout << " " << get_max_coord(gor[i], 0, n, cur) << " " << ccy << endl;
                return 0;
            }
        }
        if (not_used_x > 2)
        {
            if ((ans ^ m) <= m)
            {
                ans = m - (ans ^ m);
                if (!cx || X[0] > 1)
                {
                    cout << "1 0 1 " << ans << endl;
                    return 0;
                }
                else
                {
                    int wh = 0;
                    while (wh + 1 < cx && X[wh + 1] <= X[wh] + 1)
                        wh++;
                    cout << X[wh] + 1 << " 0 " << X[wh] + 1 << " " << ans << endl;
                    return 0;
                }
            }
        }
        if (not_used_y > 2)
        {
            if ((ans ^ n) <= n)
            {
                ans = n - (ans ^ n);
                if (!cy || Y[0] > 1)
                {
                    cout << "0 1 " << ans << " 1" << endl;
                    return 0;
                }
                else
                {
                    int wh = 0;
                    while (wh + 1 < cy && Y[wh + 1] <= Y[wh] + 1)
                        wh++;
                    cout << "0 " << Y[wh] + 1 << ans << " " << Y[wh] + 1 << endl;
                    return 0;
                }
            }
        }
    }
    else
        cout << "SECOND" << endl;
    return 0;
}
