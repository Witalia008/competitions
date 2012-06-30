#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "matches.in";
const char *outfile = "matches.out";
const int nmax = 55;

class TLong
{
    int len;
    int n[nmax];

public:
    int GetLen()
    {
        int i = 0;
        while (!n[i])
            i++;
        return nmax - i + 1;
    }
    void AddCyfr(int nn)
    {
        len++;
        n[nmax - len] = nn;
    }
    bool operator>(TLong b)
    {
        if (b.len == 0)
            return true;
        int i = 0;
        while (n[i] == b.n[i] && i < nmax)
            i++;
        return n[i] >= b.n[i];
    }
    void output()
    {
        for (int i = nmax - len; i < nmax; i++)
            printf("%d", n[i]);
        printf("\n");
    }
};

int N, K;
int a[11];
TLong F[nmax];
TLong ans;

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d%d", &N, &K);
    for (int i = 0; i <= K; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= N; i++)
    {
        for (int j = K; j >= 0; j--)
            if (i - a[j] >= 0)
            {
                TLong A = F[i - a[j]];
                A.AddCyfr(j);
                if (A > F[i])
                    F[i] = A;
            }
    }
    /*for (int i = 1; i <= N; i++)
		F[i].output();*/
    for (int i = 1; i <= N; i++)
        if (F[i] > ans)
            ans = F[i];
    ans.output();
    return 0;
}
