#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

const char *infile = "crossout.in";
const char *outfile = "crossout.out";
const int lmax = 50;
const int nmax = 770;
const int MOD = 1000000000;

char s[nmax];

class TLong
{
public:
    int n[lmax];
    void operator+=(TLong a)
    {
        int p = 0;
        for (int i = lmax - 1; i >= 0; i--)
        {
            n[i] += a.n[i] + p;
            p = n[i] / MOD;
            n[i] %= MOD;
        }
    }
    void output()
    {
        int c = 0;
        while (c < lmax - 1 && !n[c])
            c++;
        printf("%d", n[c]);
        c++;
        for (int i = c; i < lmax; i++)
            printf("%09d", n[i]);
        printf("\n");
    }
    bool comp_0()
    {
        bool fl = true;
        for (int i = 0; i < lmax; i++)
            if (n[i])
                fl = false;
        return fl;
    }
};

TLong F[nmax][nmax];

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    gets(s);
    int len = strlen(s);
    F[0][0].n[lmax - 1] = 1;

    for (int i = 0; i < len; i++)
    {
        for (int bal = 0; bal <= len; bal++)
        {
            if (!F[i][bal].comp_0())
            {
                F[i + 1][bal] += F[i][bal];
                switch (s[i])
                {
                case '(':
                    F[i + 1][bal + 1] += F[i][bal];
                    break;
                case ')':
                    if (bal > 0)
                        F[i + 1][bal - 1] += F[i][bal];
                    break;
                case ']':
                    if (bal > 0)
                        F[i + 1][0] += F[i][bal];
                    break;
                }
            }
        }
    }

    F[len][0].output();

    return 0;
}
