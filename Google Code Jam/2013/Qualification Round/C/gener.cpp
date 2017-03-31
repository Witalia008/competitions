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
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define Abs(a) ((a < 0) ? -(a) : a)
#define sqr(a) ((a) * (a))
#define pb push_back
#define mp make_pair

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

const int Inf = 10e9;
const int Mi = Inf + 7;
const int N = 10000005;
const int K = 20;
const ld eps = 10e-7;
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

//#define DEBUG

string reverse(string a)
{
    reverse(a.begin(), a.end());
    return a;
}

void print(string s, int n)
{
    string s1 = reverse(s);
    cout << s << s1 << endl;
    if (s.size() < 25)
    {
        FOR(i, 0, n)
        cout << s << i << s1 << endl;
    }
}

void push(vector<string> &a, string s, int n)
{
    string s1 = reverse(s);
    a.push_back(s + s1);
    if (s.size() < 25)
    {
        FOR(i, 0, n)
        {
            a.push_back(s + char(i + '0') + s1);
        }
    }
}

bool comp(string a, string b)
{
    if (a.size() != b.size())
    {
        return a.size() < b.size();
    }
    else
    {
        int i = 0;
        while (i + 1 < a.size() && a[i] == b[i])
            i++;
        return a[i] <= b[i];
    }
}

string multi(string a, string b)
{
    string res = "";
    FOR(i, 0, a.size() + b.size() + 1)
    res += '0';
    REP(i, a.size())
    {
        int p = 0;
        REP(j, b.size())
        {
            int cur = (a[i] - '0') * (b[j] - '0') + p + res[i + j] - '0';
            res[i + j] = cur % 10 + '0';
            p = cur / 10;
        }
    }
    while (res[res.size() - 1] == '0')
        res.erase(res.size() - 1, 1);
    return res;
}

string s;
vector<string> all;

//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main()
{
    std::ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    all.clear();
    all.push_back("1");
    all.push_back("2");
    all.push_back("3");
    s = "1";
    FOR(len, 1, 25)
    {
        //print(s, 2);
        push(all, s, 2);
        FOR(_1, 1, s.length() - 1)
        {
            s[_1] = '1';
            //print(s, 2);
            push(all, s, 2);
            FOR(_2, _1 + 1, s.length() - 1)
            {
                s[_2] = '1';
                //print(s, 1);
                push(all, s, 1);
                FOR(_3, _2 + 1, s.length() - 1)
                {
                    s[_3] = '1';
                    push(all, s, 1);
                    //print(s, 1);
                    s[_3] = '0';
                }
                s[_2] = '0';
            }
            s[_1] = '0';
        }
        s[0] = '2';
        push(all, s, 1);
        s[0] = '1';
        s += "0";
    }
    sort(all.begin(), all.end(), comp);
    REP(i, all.size())
    cout << multi(all[i], all[i]) << endl;
    return 0;
}
