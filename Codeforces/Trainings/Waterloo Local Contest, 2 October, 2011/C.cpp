#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

#define NMAX 200

struct pt
{
    double x, y;
};

#define sqr(a) ((a) * (a))

pt A[NMAX];
int N, ans;
double r = 2.5;

pt r1, r2;

bool centre(pt a, pt b)
{
    double l, h;
    l = sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
    if (l > 2 * r)
        return false;
    h = sqrt(r * r - l * l / 4);
    pt v1, v2, mid;

    v1.x = (a.x - b.x) / 2;
    v1.y = (a.y - b.y) / 2;
    v2.y = (v1.x * h * l / 2) / (sqr(v1.x) + sqr(v1.y));
    v2.x = (v1.x) ? (-(v2.y * v1.y) / v1.x) : h;
    mid.x = (a.x + b.x) / 2;
    mid.y = (a.y + b.y) / 2;
    r1.x = mid.x + v2.x;
    r1.y = mid.y + v2.y;
    r2.x = mid.x - v2.x, r2.y = mid.y - v2.y;
    return true;
}

int main()
{
    for (N = 0; scanf("%lf%lf", &A[N].x, &A[N].y) == 2; N++)
        ;

    if (N)
        ans = 1;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            if (!centre(A[i], A[j]))
                continue;
            int s, ss;
            s = ss = 2;
            for (int k = 0; k < N; k++)
                if (k != i && k != j)
                {
                    if (r * r >= sqr(r1.x - A[k].x) + sqr(r1.y - A[k].y))
                        s++;
                    if (r * r >= sqr(r2.x - A[k].x) + sqr(r2.y - A[k].y))
                        ss++;
                }
            if (s > ans)
                ans = s;
            if (ss > ans)
                ans = ss;
        }
    printf("%d\n", ans);
    return 0;
}
