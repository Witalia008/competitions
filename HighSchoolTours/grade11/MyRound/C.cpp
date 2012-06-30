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

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
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

string L, R;
ll pow10[50];

void decone(string &s)
{
    bool fl = true;
    REP(i, s.length())
    if (s[i] != '0')
        fl = false;
    if (s == "" || fl)
        return;
    s[s.length() - 1]--;
    for (int i = s.length() - 1; s[i] < '0'; i--)
        s[i] += 10, s[i - 1]--;
}

ll func(string s, bool f)
{
    int n = s.length();
    if (s == "0" || s == "")
        return 0;
    ll ans = ((s[0] - '0' - 1 + f) * pow10[(n - 1) / 2]) % Mi;
    if (!f)
        FOR(i, 1, n - 1)
        {
            ll cur = 9;
            if (i > 2)
                cur *= pow10[i - 2];
            ans = (ans + cur) % Mi;
        }
    if (s.length() > 2 && s[0] <= s[s.length() - 1])
    {
        string s1 = s;
        s1.erase(0, 1);
        s1.erase(s1.length() - 1, 1);
        decone(s1);
        ans = (ans + func(s1, 1)) % Mi;
    }
    bool fl = true;
    REP(i, n)
    if (s[i] != s[n - 1 - i])
        fl = false;
    ans += fl;
    return ans % Mi;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> L >> R;
    decone(L);
    pow10[0] = 1;
    FOR(i, 1, 49)
    pow10[i] = (pow10[i - 1] * 10) % Mi;
    cout << (Mi + func(R, 0) - func(L, 0)) % Mi << endl;
    return 0;
}
