#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "meteorite.in";
const char *outfile = "meteorite.out";
const int nmax = 20000;

struct TPoint
{
    int x, y;
};

int N, M;
TPoint A[nmax];

inline bool on_right(TPoint a, TPoint b, TPoint c)
{
    return ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y) <= 0);
}

inline bool in_tri(TPoint p1, TPoint p2, TPoint p3, TPoint p)
{
    return (!on_right(p1, p2, p) && !on_right(p2, p3, p) && !on_right(p3, p1, p));
}

inline bool in_poly(int l, int r, TPoint cur)
{
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        if (on_right(A[0], A[mid], cur))
            r = mid;
        else
            l = mid;
    }
    return in_tri(A[0], A[l], A[r], cur);
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d", &A[i].x, &A[i].y);
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        TPoint cur;
        scanf("%d%d", &cur.x, &cur.y);
        if (in_poly(1, N - 1, cur))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
