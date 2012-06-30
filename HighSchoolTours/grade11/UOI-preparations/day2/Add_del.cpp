#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <math.h>

using namespace std;

const char *infile = "add_del.in";
const char *outfile = "add_del.out";

#define NMAX 3005

struct _1
{
    int nom, D;
};

struct TQ
{
    _1 a[NMAX];
    int cou;
    void ShiftUp(int i)
    {
        for (; i > 1; i /= 2)
            if (a[i].D > a[i / 2].D)
                swap(a[i], a[i / 2]);
    }
    void push(int val, int nom)
    {
        cou++;
        a[cou].nom = nom;
        a[cou].D = val;
        ShiftUp(cou);
    }
    void ShiftDown(int i)
    {
        while (i * 2 <= cou)
        {
            int k = i;
            if (a[2 * i].D > a[k].D)
                k = 2 * i;
            if (i * 2 + 1 <= cou && a[2 * i + 1].D > a[k].D)
                k = 2 * i + 1;
            if (k == i)
                i = cou;
            else
            {
                swap(a[i], a[k]);
                i = k;
            }
        }
    }
    void pop()
    {
        swap(a[1], a[cou]);
        cou--;
        ShiftDown(1);
    }
};

int dist(int x1, int y1, int x2, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

TQ A[NMAX];
int M[NMAX][NMAX];
int prev[NMAX];
int x[NMAX], y[NMAX];
bool del[NMAX];
int N, Cnt;

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++)
    {
        char wh;
        int X, Y;
        scanf("%c%d%d\n", &wh, &X, &Y);
        if (wh == '+')
        {
            y[Cnt] = Y;
            x[Cnt] = X;
            prev[Cnt] = M[X][Y];
            M[X][Y] = Cnt;
            A[Cnt].push(0, Cnt);
            for (int j = 0; j < Cnt; j++)
                if (!del[j])
                {
                    A[j].push(dist(x[j], y[j], X, Y), Cnt);
                    A[Cnt].push(dist(x[j], y[j], X, Y), j);
                }
            Cnt++;
        }
        else
        {
            int no = M[X][Y];
            M[X][Y] = prev[M[X][Y]];
            del[no] = true;
        }
        double ans = 0;
        for (int j = 0; j < Cnt; j++)
            if (!del[j])
            {
                while (del[A[j].a[1].nom])
                    A[j].pop();
                ans += sqrt(double(A[j].a[1].D));
            }
        printf("%0.20lf\n", ans);
    }
    return 0;
}
