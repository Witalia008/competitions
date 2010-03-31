#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <memory.h>

using namespace std;

const char *infile = "input.txt";
const char *outfile = "output.txt";

typedef long long LL;

#define NMAX 1001

struct TLong
{
    int n[NMAX + 1];
    void Output()
    {
        int x = 0;
        while (x < NMAX && n[x] == 0)
            x++;
        for (int i = x; i <= NMAX; i++)
            printf("%d", n[i]);
        printf("\n");
    }
    void Multi(int b)
    {
        int p = 0;
        for (int i = NMAX; i > 0; i--)
        {
            n[i] = n[i] * b + p;
            p = n[i] / 10;
            n[i] %= 10;
        }
    }
    void Sub(int b)
    {
        int z = 0;
        for (int i = NMAX; i > 0; i--)
        {
            n[i] = n[i] - z - b % 10;
            b /= 10;
            if (n[i] < 0)
                n[i] += 10, z = 1;
            else
                z = 0;
        }
    }
};

int N;
bool prime[NMAX];
int Ans[NMAX], cur[NMAX];

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d", &N);

    for (int i = 2; i <= N; i++)
        prime[i] = true;
    for (int i = 2; i <= N; i++)
        if (prime[i])
            for (int j = i * i; j <= N; j += i)
                prime[j] = false;
    for (int n = 2; n <= N; n++)
    {
        int p = n;
        memset(cur, 0, sizeof cur);
        for (int i = 2; i <= n; i++)
            if (prime[i])
                while (p % i == 0)
                    p /= i, cur[i]++;
        for (int i = 2; i <= n; i++)
            if (cur[i] > Ans[i])
                Ans[i] = cur[i];
    }
    TLong ans;
    memset(ans.n, 0, sizeof ans.n);
    ans.n[NMAX] = 1;
    for (int i = 2; i <= N; i++)
        if (Ans[i])
            for (int j = 0; j < Ans[i]; j++)
                ans.Multi(i);
    ans.Sub(1);
    ans.Output();
    return 0;
}
