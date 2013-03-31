#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define min(a, b) (a < b) ? a : b;
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 1000000007
#define N 100005

typedef long double ld;
typedef unsigned long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;

string toStr(ll a)
{
    string res = "";
    while (a)
    {
        res += a % 10 + '0';
        a /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

ll a, b;
ll pow10[20];

ll func(ll s)
{
    if (!s)
        return 0;
    string S = toStr(s);
    ll res = pow10[S.length() - 2] * ll(S[0] - '0' - 1);
    for (int i = 0; i + 2 < S.length(); i++)
        res += pow10[i] * 9;
    ll sub = 0;
    for (int i = 1; i < S.length() - 1; i++)
        sub = sub * 10 + S[i] - '0';
    if (S[0] <= S[S.length() - 1] && S.length() != 1)
        sub++;
    res += min(s, 9);
    res += sub;
    return res;
}

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    cin >> a >> b;
    pow10[0] = 1;
    FOR(i, 1, 19)
    pow10[i] = pow10[i - 1] * 10;
    cout << func(b) - func(a - 1) << endl;
    return 0;
}
