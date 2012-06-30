#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <iostream>

using namespace std;

#define sqr(a) ((a) * (a))
#define eps 10e-7

const char *infile = "drakhir.in";
const char *outfile = "drakhir.out";
const int INF = 1000000000;
const int nmax = 201;
const int kmax = 101;

struct TPoint
{
    int x, y;
};

double dist(TPoint a, TPoint b)
{
    return sqrt(double(sqr(a.x - b.x) + sqr(a.y - b.y)));
}

bool on_right(TPoint a, TPoint b, TPoint c)
{
    return ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y) <= 0);
}

int N, K, R;
TPoint p[nmax];
double F[nmax][kmax];
bool can[nmax][nmax];

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d%d%d", &N, &K, &R);
    for (int i = 0; i < N; i++)
        scanf("%d%d", &p[i].x, &p[i].y);

    for (int i = 0; i < N; i++)
        for (int j = 0; j <= K; j++)
            F[i][j] = INF;

    for (int i = 0; i < N - 2; i++)
        for (int j = i + 2; j < N; j++)
            if (dist(p[i], p[j]) <= R)
            {
                can[i][j] = true;
                for (int k = i + 1; k < j; k++)
                    if (!on_right(p[i], p[j], p[k]))
                        can[i][j] = false;
            }

    F[0][0] = 0;
    for (int k = 0; k <= K; k++)
    {
        for (int i = 0; i < N; i++)
        {
            if (i < N - 1)
                F[i + 1][k] = min(F[i + 1][k], F[i][k] + dist(p[i], p[i + 1]));

            if (k < K)
                for (int j = i + 2; j < N; j++)
                    if (can[i][j])
                        F[j][k + 1] = min(F[j][k + 1], F[i][k] + dist(p[i], p[j]));
        }

        for (int i = N - 1; i >= 0; i--)
        {
            if (i > 0)
                F[i - 1][k] = min(F[i - 1][k], F[i][k] + dist(p[i], p[i - 1]));

            if (k < K)
                for (int j = i - 2; j >= 0; j--)
                    if (can[j][i])
                        F[j][k + 1] = min(F[j][k + 1], F[i][k] + dist(p[i], p[j]));
        }
    }

    double ans = INF;
    for (int k = 0; k <= K; k++)
        ans = min(ans, F[N - 1][k]);
    printf("%0.5lf\n", ans);
    return 0;
}
