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
#define eps 10e-10
#define e_num 2.718281828259
#define Inf 2000000000
#define Mi 1000000007
#define N 1005
#define K 16
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

ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}
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
ld Abs(ld a)
{
    if (a < 0)
        return -a;
    else
        return a;
}
ll sqr(ll a) { return a * a; }
ld sqr(ld a) { return a * a; }

struct pirate
{
    ll t[4];
    ll arrive;
    int side;
    bool operator<(const pirate &b) const
    {
        if (arrive == b.arrive)
        {
            if (side == 0)
                return t[3] < b.t[3];
            return t[1] < b.t[1];
        }
        return arrive > b.arrive;
    }
};

int n, p;
priority_queue<pirate> Q1, Q2;

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    scanf("%d\n", &T);
    REP(t, T)
    {
        scanf("%d%d", &n, &p);
        while (!Q1.empty())
            Q1.pop();
        while (!Q2.empty())
            Q2.pop();
        REP(i, p)
        {
            pirate cur;
            REP(k, 4)
            scanf("%lld", &cur.t[k]);
            cur.arrive = i - p;
            cur.side = 0;
            Q1.push(cur);
        }
        ll T = 0;
        while (!Q1.empty() || !Q2.empty())
        {
            if (Q2.empty())
            {
                pirate p = Q1.top();
                Q1.pop();
                if (n)
                {
                    T = max(p.arrive, T) + p.t[0];
                    p.arrive = T + p.t[1];
                    p.side = 1;
                    Q2.push(p);
                    n--;
                }
            }
            else if (Q1.empty())
            {
                pirate p = Q2.top();
                Q2.pop();
                T = max(T, p.arrive) + p.t[2];
                if (n)
                {
                    p.arrive = T + p.t[3];
                    p.side = 0;
                    Q1.push(p);
                }
            }
            else
            {
                pirate p1 = Q1.top();
                pirate p2 = Q2.top();
                if (p2.arrive <= T || p2.arrive <= p1.arrive)
                {
                    Q2.pop();
                    T = max(T, p2.arrive) + p2.t[2];
                    if (n)
                    {
                        p2.side = 0;
                        p2.arrive = T + p2.t[3];
                        Q1.push(p2);
                    }
                }
                else
                {
                    Q1.pop();
                    if (n)
                    {
                        T = max(p1.arrive, T) + p1.t[0];
                        p1.side = 1;
                        p1.arrive = T + p1.t[1];
                        Q2.push(p1);
                        n--;
                    }
                }
            }
        }
        cout << T << endl;
    }
    return 0;
}
