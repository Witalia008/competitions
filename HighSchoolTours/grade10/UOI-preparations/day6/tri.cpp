#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

#define nmax 2000
#define MP make_pair

struct PII
{
    int x, y;
};

PII A[nmax + 1];
int N;
double ans;

double Square(int x1, int y1, int x2, int y2)
{
    return ((double)(x1 * y2 - x2 * y1)) / 2;
}

double abss(double a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

int main()
{
    ifstream cin("tri.in");
    ofstream cout("tri.out");
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i].x >> A[i].y;

    ans = 0;
    for (int i = 1; i <= N; i++)
    {
        int k = (i + 2 != N) ? (i + 2) % N : N;
        for (int j = i + 1; j != i; j = j % N + 1)
        {
            double sq = abss(Square(
                A[j].x - A[i].x, A[j].y - A[i].y,
                A[k].x - A[i].x, A[k].y - A[i].y));
            while (double sq1 = abss(Square(
                                    A[j].x - A[i].x, A[j].y - A[i].y,
                                    A[k % N + 1].x - A[i].x, A[k % N + 1].y - A[i].y)) > sq)
                k = k % N + 1, sq = sq1;
            if (sq > ans)
                ans = sq;
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(6) << ans << endl;
    return 0;
}
