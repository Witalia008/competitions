#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define N 100005

struct pt
{
    ll x, y;
    bool operator==(pt b)
    {
        return x == b.x && y == b.y;
    }
};

int n, m;
pt A[N];

bool left(pt a, pt b, pt c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) >= 0;
}

bool in_v(pt a, pt b, pt c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) == 0;
}

bool in_tri(pt a, pt b, pt c, pt x)
{
    return left(a, c, x) && left(c, b, x) && left(b, a, x);
}

bool in_mn(pt x)
{
    int l = 0, r = n - 1;
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        if (left(A[0], A[mid], x))
            r = mid;
        else
            l = mid;
    }
    bool fl = in_tri(A[0], A[l], A[r], x);
    if (in_v(A[l], A[r], x))
        fl = false;
    if (in_v(A[0], A[1], x))
        fl = false;
    if (in_v(A[0], A[n - 1], x))
        fl = false;
    if (x == A[l] || x == A[r] || x == A[0])
        fl = false;
    return fl;
}

int main()
{
    // freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    scanf("%d", &n);
    REP(i, n)
    scanf("%I64d%I64d", &A[i].x, &A[i].y);
    scanf("%d", &m);
    bool flag = true;
    REP(i, m)
    {
        pt a;
        scanf("%I64d%I64d", &a.x, &a.y);
        if (!in_mn(a))
            flag = false;
    }
    if (flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
