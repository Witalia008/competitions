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

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define CLR(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define mp make_pair
#define eps 10e-6
#define Inf 1000000000
#define Mi 1000000007
#define N 1505
//#define debug

typedef double ld;
typedef long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<double, char> pdc;

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
ll sqr(ll a) { return a * a; }
ld sqr(ld a) { return a * a; }

const int mx[4] = {0, 0, -1, 1};
const int my[4] = {-1, 1, 0, 0};
const pii nothing = mp(-Inf, -Inf);

int n, m;
char A[N][N];
queue<pii> Q;
pii used[N][N];

int main()
{
    //freopen ("input.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    REP(i, n)
    REP(j, m)
    used[i][j] = nothing;
    REP(i, n)
    {
        scanf("%s", &A[i]);
        REP(j, m)
        if (A[i][j] == 'S')
        {
            Q.push(mp(i, j));
            used[i][j] = mp(i, j);
            A[i][j] = '.';
        }
    }
    while (!Q.empty())
    {
        pii v = Q.front();
        Q.pop();
        REP(k, 4)
        {
            pii nv = mp(v.first + mx[k], v.second + my[k]);
            pii mnv = mp((nv.first % n + n) % n, (nv.second % m + m) % m);
            if (A[mnv.first][mnv.second] == '#')
                continue;
            if (used[mnv.first][mnv.second] == nothing)
            {
                used[mnv.first][mnv.second] = nv;
                Q.push(nv);
            }
            else if (used[mnv.first][mnv.second] != nv)
            {
                cout << "Yes" << endl;
#ifdef debug
                cout << mnv.first << " " << mnv.second << endl;
                cout << nv.first << " " << nv.second << endl;
#endif
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
