#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "baloon.in";
const char *outfile = "baloon.out";
const int nmax = 20;

struct Tst
{
    int t, y, z, te, us, we;
};

int N, M;
Tst staff[nmax];

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d%d", &M, &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d%d", &staff[i].t, &staff[i].z, &staff[i].y);
        staff[i].te = 0;
        staff[i].us = 0;
    }
    for (int c = 0; c < M; c++)
    {
        int wu = -1;
        for (int i = 0; i < N; i++)
        {
            bool isr = false;
            if ((staff[i].us / staff[i].z) && !(staff[i].us % staff[i].z))
                isr = true;
            staff[i].we = staff[i].te + staff[i].t + staff[i].y * isr;
            if (wu == -1 || staff[i].we < staff[wu].we)
                wu = i;
        }
        staff[wu].te = staff[wu].we;
        staff[wu].us++;
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
        if (staff[i].te > ans)
            ans = staff[i].te;
    printf("%d\n", ans);
    return 0;
}
