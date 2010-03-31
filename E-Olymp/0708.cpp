#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define MP make_pair
#define Inf 1000000000
#define N 126005

typedef long double ld;
typedef long long ll;

struct pt
{
    int x, y;
    pt(int _x, int _y) : x(_x), y(_y) {}
    bool operator<(const pt b) const
    {
        return y < b.y || (y == b.y && x < b.x);
    }
};

struct vt
{
    pt s, f;
    vt() : s(pt(0, 0)), f(pt(0, 0)) {}
};

struct ppt
{
    int id;
    pt po;
    char wh;
    ppt() : id(0), po(pt(0, 0)), wh(0) {}
    bool operator<(ppt b)
    {
        if (po.x < b.po.x)
            return true;
        if (po.x > b.po.x)
            return false;
        return wh < b.wh;
    }
};

int wise(pt a, pt b, pt c)
{
    int x = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (x < 0)
        return -1;
    if (x > 0)
        return 1;
    return 0;
}

bool intersect1d(int l1, int r1, int l2, int r2)
{
    if (l1 > r1)
        swap(l1, r1);
    if (l2 > r2)
        swap(l2, r2);
    return max(l1, l2) <= min(r1, r2);
}

bool intersect(vt a, vt b)
{
    return intersect1d(a.s.x, a.f.x, b.s.x, b.f.x) && intersect1d(a.s.y, a.f.y, b.s.y, b.f.y) &&
           wise(a.s, a.f, b.s) * wise(a.s, a.f, b.f) <= 0 && wise(b.s, b.f, a.s) * wise(b.s, b.f, a.f) <= 0;
}

typedef pair<pt, int> ppti;

int n;
vt A[N];
ppt B[N * 2];
set<ppti> S;
set<ppti>::iterator it;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    REP(i, n)
    {
        scanf("%d%d%d%d", &A[i].s.x, &A[i].s.y, &A[i].f.x, &A[i].f.y);
        if (A[i].s.x > A[i].f.x)
            swap(A[i].s, A[i].f);
        B[i * 2].po = A[i].s;
        B[i * 2].wh = 'l';
        B[i * 2 + 1].po = A[i].f;
        B[i * 2 + 1].wh = 'r';
        B[i * 2].id = B[i * 2 + 1].id = i;
    }
    n *= 2;
    sort(B, B + n);
    REP(i, n)
    {
        if (B[i].wh == 'l')
        {
            S.insert(MP(B[i].po, B[i].id));
        }
        if (B[i].wh == 'r')
        {
            S.erase(MP(A[B[i].id].s, B[i].id));
            S.insert(MP(B[i].po, B[i].id));
        }
        it = S.find(MP(B[i].po, B[i].id));
        if (it != S.begin())
        {
            it--;
            if (intersect(A[B[i].id], A[it->second]))
            {
                printf("YES\n%d %d\n", B[i].id + 1, it->second + 1);
                return 0;
            }
            it++;
        }
        it++;
        if (it != S.end())
            if (intersect(A[B[i].id], A[it->second]))
            {
                printf("YES\n%d %d\n", B[i].id + 1, it->second + 1);
                intersect(A[B[i].id], A[it->second]);
                return 0;
            }
        if (B[i].wh == 'l')
            S.erase(MP(B[i].po, B[i].id));
    }
    printf("NO\n");
    return 0;
}
