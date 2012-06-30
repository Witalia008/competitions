#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

const char *infile = "robbery.in";
const char *outfile = "robbery.out";

#define Inf 1000000000
#define sqr(a) ((a) * (a))

struct pt
{
    double x, y;
};

bool cmp(pt a, pt b)
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

void convex_hull(vector<pt> &a)
{
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);

    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);

    for (int i = 1; i < a.size(); ++i)
    {
        if (i == a.size() - 1 || cw(p1, a[i], p2))
        {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2))
        {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < up.size(); ++i)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; --i)
        a.push_back(down[i]);
}

vector<pt> A;
pt O;
double R, dest;
int N, cou;

double dist(pt a, pt b)
{
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

bool ang_PI(pt a, pt b, pt c)
{
    return (dist(a, c) >= dist(a, b) + dist(b, c));
}

double Abs(double a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

double try_(pt a, pt b)
{
    if (ang_PI(O, a, b) || ang_PI(O, b, a))
    {
        double aa = min(sqrt(dist(O, a)), sqrt(dist(O, b)));
        if (aa <= R)
            return 0;
        else
            return aa - R;
    }
    else
    {
        double _a, _b, _c, p;
        _a = a.y - b.y;
        _b = b.x - a.x;
        _c = a.x * b.y - b.x * a.y;
        p = Abs(_a * O.x + _b * O.y + _c) / sqrt(sqr(_a) + sqr(_b));
        if (p > R)
            return p - R;
        else
        {
            double oa, ob;
            oa = dist(O, a);
            ob = dist(O, b);
            oa = (oa < R) ? (R - oa) : 0;
            ob = (ob < R) ? (R - ob) : 0;
            return min(oa, ob);
        }
    }
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d", &N);
    A.resize(N);
    for (int i = 0; i < N; i++)
        scanf("%lf%lf", &A[i].x, &A[i].y);
    scanf("%lf%lf%lf", &O.x, &O.y, &R);
    convex_hull(A);

    dest = Inf;
    for (int i = 0; i < A.size(); i++)
        dest = min(dest, try_(A[i], A[(i + 1) % A.size()]));

    if (dest == Inf)
        printf("\n");
    else
        printf("%0.10lf\n", dest);
    return 0;
}
