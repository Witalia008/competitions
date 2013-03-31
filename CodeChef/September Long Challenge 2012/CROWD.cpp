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
#define K 3
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

ll power(int a, ll k)
{
    if (!k)
        return 1;
    ll res = power(a, k / 2);
    res = (res * res) % Mi;
    if (k & 1)
        res = (res * a) % Mi;
    return res;
}

struct tmatr
{
    int a, b;
    ll n[K][K];
    tmatr operator*(tmatr b)
    {
        tmatr res;
        CLR(res.n, 0);
        if (this->b != b.a)
            return res;
        res.a = this->a;
        res.b = b.b;
        REP(i, res.a)
        REP(j, res.b)
        REP(k, b.a)
        {
            res.n[i][j] += this->n[i][k] * b.n[k][j];
            res.n[i][j] %= Mi;
        }
        return res;
    }
};

void setmatr(tmatr &a)
{
    CLR(a.n, 0);
    a.a = a.b = K;
    REP(i, K - 1)
    a.n[i][i + 1] = 1;
    REP(i, K)
    a.n[K - 1][i] = 1;
}

void setone(tmatr &a)
{
    CLR(a.n, 0);
    a.a = a.b = K;
    REP(i, K)
    a.n[i][i] = 1;
}

tmatr poww(ll k)
{
    tmatr res;
    setone(res);
    tmatr a;
    setmatr(a);
    while (k)
    {
        if (k & 1)
            res = res * a;
        a = a * a;
        k >>= 1;
    }
    return res;
}

int mm[K] = {2, 4, 7};

ll f(ll n)
{
    if (n <= K)
        return n == 1 ? 2 : (n == 2 ? 4 : 7);
    tmatr x = poww(n - K);
    tmatr y;
    y.a = K;
    y.b = 1;
    REP(i, K)
    y.n[i][0] = mm[i];
    x = x * y;
    return x.n[K - 1][0];
}

string s;

void showall(int pos, int n)
{
    if (!pos)
        s = "";
    if (pos == n)
    {
        bool fl = false;
        REP(i, n)
        if (i > 1 && s[i] == '1' && s[i - 1] == '1' && s[i - 2] == '1')
            fl = true;
        if (fl)
            cout << s << endl;
        return;
    }
    REP(i, 2)
    {
        s += i + '0';
        showall(pos + 1, n);
        s.erase(s.length() - 1, 1);
    }
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    REP(t, T)
    {
        ll n;
        cin >> n;
        ll ans = power(2, n);
        ans = ((ans - f(n)) % Mi + Mi) % Mi;
        cout << ans % Mi << endl;
    }
    //showall(0, 10);
    return 0;
}
