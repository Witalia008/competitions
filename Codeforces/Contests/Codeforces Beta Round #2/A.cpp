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
const int N = 100005;
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

struct player
{
    string name;
    int score;
};

vector<player> A;
map<string, int> scores;
int n;
vector<string> ans;

//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main()
{
    std::ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    A.resize(n);
    REP(i, n)
    {
        cin >> A[i].name >> A[i].score;
        scores[A[i].name] += A[i].score;
    }
    int m = 0;
    for (map<string, int>::iterator it = scores.begin(); it != scores.end(); it++)
        m = max(m, it->second);
    for (map<string, int>::iterator it = scores.begin(); it != scores.end(); it++)
        if (it->second != m)
            it->second = -Inf;
        else
            it->second = 0;
    REP(i, n)
    {
        if (scores[A[i].name] != -Inf)
        {
            scores[A[i].name] += A[i].score;
            if (scores[A[i].name] >= m)
            {
                cout << A[i].name << endl;
                return 0;
            }
        }
    }
    return 0;
}
