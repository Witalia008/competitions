#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define N 100005

typedef long double ld;
typedef long long ll;

struct pt
{
    int x, y;
    bool operator==(pt b)
    {
        return x == b.x && y == b.y;
    }
};

int n;
vector<pt> A, B, C;

bool comp(pt a, pt b)
{
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw(pt a, pt b, pt c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool ccw(pt a, pt b, pt c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

bool find(pt x)
{
    int l = 0, r = B.size();
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        if (comp(B[mid], x))
            l = mid;
        else
            r = mid;
    }
    if (B[l] == x || B[r] == x)
        return true;
    return false;
}

void convex_hull(vector<pt> &a)
{
    sort(a.begin(), a.end(), &comp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < a.size(); i++)
    {
        if (i == a.size() - 1 || !ccw(p1, a[i], p2))
        {
            while (up.size() > 1 && ccw(up[up.size() - 2], up[up.size() - 1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || !cw(p1, a[i], p2))
        {
            while (down.size() > 1 && cw(down[down.size() - 2], down[down.size() - 1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    a.clear();
    for (int i = 0; i < up.size(); ++i)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    A.resize(n);
    REP(i, n)
    scanf("%d%d", &A[i].x, &A[i].y);
    int ans = 0;
    while (A.size() > 2)
    {
        ans++;
        B = A;
        convex_hull(B);
        sort(B.begin(), B.end(), &comp);
        C = A;
        A.clear();
        for (int i = 0; i < C.size(); i++)
            if (!find(C[i]))
                A.push_back(C[i]);
    }
    if (A.size() != 0)
        ans++;
    printf("%d\n", ans);
    return 0;
}
