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
#define eps 10e-7
#define InfL 10000000000000000LL
#define Inf 2000010000
#define Mi 100000000
#define N 1015
#define K 105
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

const int mx[4] = {1, -1, 0, 0};
const int my[4] = {0, 0, 1, -1};

inline ll Abs(ll x) { return x < 0 ? -x : x; }
inline ll sqr(ll a) { return a * a; }
inline ll gcd(ll a, ll b) { return (!b ? a : gcd(b, a % b)); }
inline ll minn(ll a, ll b) { return a < b ? a : b; }
inline ll maxx(ll a, ll b) { return a > b ? a : b; }

class TomekPhone
{
public:
    int minKeystrokes(vector<int> occurences, vector<int> keySizes)
    {
        int sum = 0;
        REP(i, keySizes.size())
        sum += keySizes[i];
        if (sum < occurences.size())
            return -1;
        vector<int> already;
        already.clear();
        already.resize(keySizes.size());
        REPD(i, occurences.size())
        REP(j, i)
        if (occurences[j] < occurences[j + 1])
            swap(occurences[j], occurences[j + 1]);
        int res = 0;
        REP(i, occurences.size())
        {
            int cur = 0;
            REP(j, keySizes.size())
            if (already[j] < already[cur] && already[j] != keySizes[j])
                cur = j;
            ++already[cur];
            res += (already[cur]) * occurences[i];
        }
        return res;
    }
};
