#include <stdio.h>
#include <cstdlib>
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

#define nmax 100
#define sqr(a) ((a) * (a))
#define abss(a) ((a < 0) ? -a : a)

struct THill
{
    double x, y, r;
};

struct TAng
{
    double ang;
    char what;
};

bool comp(TAng &a, TAng b)
{
    return a.ang < b.ang;
}

int N, top, bal;
double H, ans, Prev;
THill C[nmax + 1];
TAng Ang[nmax * 2 + 1];

int main()
{
    ifstream cin("hills.dat");
    ofstream cout("hills.sol");
    cin >> H >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> C[i].x >> C[i].y >> C[i].r;
        if (C[i].r > sqrt(sqr(C[i].x) + sqr(C[i].y)))
            H += sqrt(sqr(C[i].r) - (sqr(C[i].x) + sqr(C[i].y)));
    }

    //Get Up Earth
    for (int i = 1; i <= N; i++)
        if (H < C[i].r)
            C[i].r = sqrt(sqr(C[i].r) - sqr(H));
        else
            C[i].r = 0;

    //Get Angles
    bal = 0;
    top = -1;
    for (int i = 1; i <= N; i++)
        if (C[i].r != 0)
        {
            double a = atan2(C[i].y, C[i].x);
            if (a < 0)
                a += 2 * M_PI;
            double phi = C[i].r / sqrt(sqr(C[i].x) + sqr(C[i].y));
            phi = asin(phi);
            top += 2;
            if (phi < 0)
                phi += 2 * M_PI;
            Ang[top - 1].ang = a - phi;
            if (Ang[top - 1].ang < 0)
                Ang[top - 1].ang += 2 * M_PI;
            Ang[top].ang = a + phi;
            if (Ang[top].ang > 2 * M_PI)
                Ang[top].ang -= 2 * M_PI;
            Ang[top - 1].what = 'B';
            Ang[top].what = 'E';
            if (abss(C[i].y) < C[i].r && C[i].x > 0)
                bal++;
        }

    top++;
    sort(Ang, Ang + top, &comp);

    //Get Ans
    Prev = 0;
    for (int i = 0; i < top; i++)
    {
        if (bal > 0)
            ans += Ang[i].ang - Prev;
        if (Ang[i].what == 'B')
            bal++;
        else
            bal--;
        Prev = Ang[i].ang;
    }
    if (bal != 0)
        ans += 2 * M_PI - Prev;
    cout << setiosflags(ios::fixed) << setprecision(8) << (ans * 100) / (2 * M_PI) << endl;
    return 0;
}
