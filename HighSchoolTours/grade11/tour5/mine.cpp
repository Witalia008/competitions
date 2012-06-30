#include <stdio.h>
#include <cstdlib>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>

using namespace std;

typedef long long LL;

#define nmax 1001

const char *infile = "mine.dat";
const char *outfile = "mine.sol";

struct TPoint
{
    int x, y;
    double ang;
};

bool comp(TPoint a, TPoint b)
{
    return a.ang < b.ang;
}

bool cmp(TPoint a, TPoint b)
{
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

bool left(TPoint p1, TPoint p2, TPoint p3)
{
    return LL(p2.x - p1.x) * LL(p3.y - p2.y) - LL(p3.x - p2.x) * LL(p2.y - p1.y) > 0;
}

int N, ans, top;
TPoint A[nmax], B[nmax];

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d", &A[i].x, &A[i].y);

    ans = 0;
    while (N > 2)
    {
        ans++;
        sort(A, A + N, &cmp);
        for (int i = 1; i < N; i++)
        {
            A[i].ang = atan2(double(A[i].y - A[0].y), double(A[i].x - A[0].x));
            if (A[i].ang < 0)
                A[i].ang += 2 * M_PI;
        }
        A[0].ang = 0;
        sort(A, A + N, &comp);
        top = 1;
        B[0] = A[0];
        B[1] = A[1];
        for (int i = 2; i < N; i++)
        {
            while (top > 0 && !left(B[top - 1], B[top], A[i]))
                top--;
            top++;
            B[top] = A[i];
        }
        int n = 0;
        for (int i = 0; i < N; i++)
        {
            bool fl = false;
            for (int j = 0; j <= top; j++)
                if (A[i].x == B[j].x && A[i].y == B[j].y)
                    fl = true;
            if (!fl)
                A[n++] = A[i];
        }
        N = n;
    }
    printf("%d %d\n", N, ans);
    return 0;
}
