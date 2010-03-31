#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

const char *infile = "input.txt";
const char *outfile = "output.txt";

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define max(a, b) ((a) > (b)) ? (a) : (b)
#define CLR(a, x) memset(a, x, sizeof(a))
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define MP make_pair
#define Inf 1000000000

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPI;
typedef unsigned long long LL;

#define NMAX 105

struct TLong
{
    int n[NMAX + 1];
    void Output()
    {
        int s = 0;
        while (s < NMAX && !n[s])
            s++;
        FOR(i, s, NMAX)
        printf("%d", n[i]);
        printf("\n");
    }
    void operator+=(TLong b)
    {
        int p = 0;
        FORD(i, NMAX, 1)
        {
            n[i] += b.n[i] + p;
            p = n[i] / 10;
            n[i] %= 10;
        }
    }
};

int N;
TLong F[NMAX][10], ans;

bool can(int a, int b)
{
    switch (a)
    {
    case 0:
        return ((b == 4 || b == 6) ? true : false);
    case 1:
        return ((b == 8 || b == 6) ? true : false);
    case 2:
        return ((b == 7 || b == 9) ? true : false);
    case 3:
        return ((b == 4 || b == 8) ? true : false);
    case 4:
        return ((b == 0 || b == 9 || b == 3) ? true : false);
    case 5:
        return false;
    case 6:
        return ((b == 7 || b == 1 || b == 0) ? true : false);
    case 7:
        return ((b == 2 || b == 6) ? true : false);
    case 8:
        return ((b == 1 || b == 3) ? true : false);
    case 9:
        return ((b == 4 || b == 2) ? true : false);
    }
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d", &N);
    REP(i, 10)
    F[1][i].n[NMAX] = 1;
    F[1][0].n[NMAX] = F[1][8].n[NMAX] = 0;
    FOR(i, 2, N)
    REP(j, 10)
    REP(l, 10)
    if (can(l, j))
        F[i][j] += F[i - 1][l];
    REP(i, 10)
    ans += F[N][i];
    ans.Output();
    return 0;
}
