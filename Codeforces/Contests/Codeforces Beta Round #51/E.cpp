#include <stdio.h>
#include <cstdlib>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

#define eps 10e-5
#define abs(a) (((a) < 0) ? (-a) : (a))
#define sqr(a) ((a) * (a))
#define nmax 100000
#define MP make_pair

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

struct point
{
    LL x, y;
};

point shape[nmax * 2];
int n, t;
point p[20];

LL square(point a, point b, point c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}

bool clockwise(point a, point b, point c)
{
    return (square(a, b, c) < 0);
}

int bin_search(int i, int pos, int l, int r)
{
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        if (clockwise(shape[i], shape[mid], p[pos]))
            l = mid;
        else
            r = mid;
    }
    if (l == r - 1)
    {
        if (clockwise(shape[i], shape[r], p[pos]))
            return r;
        else
            return l;
    }
    if (l > r)
        return -1;
    if (l == r)
    {
        if (clockwise(shape[i], shape[l], p[pos]))
            return l;
        else
            return -1;
    }
}

bool in_tri(point a, point b, point c, point x)
{
    return square(a, b, x) < 0 && square(b, c, x) < 0 && square(c, a, x) < 0;
}

bool in_shape(int pos)
{
    int x1 = bin_search(0, pos, 1, n - 1);
    if (x1 == n - 1)
        return false;
    return in_tri(shape[0], shape[x1], shape[x1 + 1], p[pos]);
}

long long cou[nmax];

int main()
{
    //ifstream cin ("input.txt"); ofstream cout ("output.txt");
    //freopen ("input.txt", "r", stdin); freopen ("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%I64d%I64d", &shape[i].x, &shape[i].y);
        shape[i + n] = shape[i];
    }
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        scanf("%I64d%I64d", &p[i].x, &p[i].y);
    long long ans;
    cou[2] = 1;
    long long prev = 1;
    for (int i = 3; i < n; i++)
    {
        prev += i - 1;
        cou[i] = cou[i - 1] + prev;
    }
    for (int pos = 0; pos < t; pos++)
    {
        if (in_shape(pos))
        {
            ans = 0;
            for (int i = 0; i < n; i++)
            {
                int x = bin_search(i, pos, i + 1, n + i - 1);
                long long N = x - i;
                ans += N * (N - 1) / 2;
            }
            printf("%I64d\n", cou[n - 1] - ans);
        }
        else
            printf("0\n");
    }
    return 0;
}
