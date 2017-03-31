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

string s, A, B;
vector<string> all;

int bin_search(string a)
{
    int l = 0, r = all.size() - 1;
    while (l < r - 1)
    {
        int mid = (l + r) >> 1;
        if (comp(a, all[mid]))
            r = mid;
        else
            l = mid;
    }
    if (comp(all[r], a))
        return r;
    return l;
}

//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main()
{
    std::ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ifstream fin("list.txt");
    all.clear();
    for (;;)
    {
        s = "";
        getline(fin, s);
        if (s == "")
            break;
        all.push_back(s);
    }
    fin.close();
    int T;
    cin >> T;
    REP(t, T)
    {
        cin >> A >> B;
        int a = bin_search(A);
        int b = bin_search(B);
        int ans = b - a;
        if (all[a] == A)
            ans++;
        cout << "Case #" << t + 1 << ": " << ans << endl;
    }
    return 0;
}
