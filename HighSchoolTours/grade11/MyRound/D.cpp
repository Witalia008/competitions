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
#define min(a, b) (a < b) ? (a) : (b)
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 1000000007
#define N 100005

typedef double ld;
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

#define p 31

string s;
ll H[N], Hr[N], P[N];

bool is_palin(int pos, int len)
{
    int l, r, lr, rr;
    if (len % 2 == 0)
        r = pos, l = r - len / 2 + 1, rr = s.length() - pos - 2, lr = rr - len / 2 + 1;
    else
        r = pos, l = r - len / 2, rr = s.length() - pos - 1, lr = rr - len / 2;
    if (l < 0 || lr < 0)
        return false;
    ll hash1 = H[r];
    if (l)
        hash1 -= H[l - 1];
    ll hash2 = Hr[rr];
    if (lr)
        hash2 -= Hr[lr - 1];
    if (l > lr)
        hash2 *= P[l - lr];
    else
        hash1 *= P[lr - l];
    return hash1 == hash2;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> s;
    P[0] = 1;
    FOR(i, 1, N - 1)
    P[i] = P[i - 1] * p;
    REP(i, s.length())
    {
        H[i] = (s[i] - 'a' + 1) * P[i];
        if (i)
            H[i] += H[i - 1];
        Hr[i] = (s[s.length() - 1 - i] - 'a' + 1) * P[i];
        if (i)
            Hr[i] += Hr[i - 1];
    }
    int ans = 0, pl = 0, pr = 0;
    REP(i, s.length())
    {
        int l = 0, r = s.length();
        while (l < r - 1)
        {
            int mid = (l + r) / 2;
            if (is_palin(i, mid * 2 - 1))
                l = mid;
            else
                r = mid;
        }
        int cur = 0;
        FOR(j, l, r)
        if (is_palin(i, j * 2 - 1))
            cur = j * 2 - 1;
        if (cur > ans)
            ans = cur, pl = i - cur / 2, pr = i + cur / 2;
        l = 0, r = s.length();
        while (l < r - 1)
        {
            int mid = (l + r) / 2;
            if (is_palin(i, mid * 2))
                l = mid;
            else
                r = mid;
        }
        cur = 0;
        FOR(j, l, r)
        if (is_palin(i, j * 2))
            cur = j * 2;
        if (cur > ans)
            ans = cur, pl = i - cur / 2 + 1, pr = i + cur / 2;
    }
    printf("%d %d %d\n", ans, pl, pr);
    return 0;
}
