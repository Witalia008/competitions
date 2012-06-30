#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define For(i, a, b) for (int i = a; i <= b; i++)
#define nmax 50

using namespace std;

struct tmas
{
    int num[nmax + 1];
};

tmas f[60][60];
int n, m;

bool comp_0(tmas a)
{
    bool fl = true;
    For(i, 1, nmax) if (a.num[i] != 0) fl = false;
    return fl;
}

tmas sum(tmas a, tmas b)
{
    tmas res;
    memset(res.num, 0, sizeof(res.num));
    int p = 0;
    for (int i = nmax; i >= 1; i--)
    {
        int s = a.num[i] + b.num[i] + p;
        res.num[i] = s % 10;
        p = s / 10;
    }
    return res;
}

tmas srch(int i, int j)
{
    tmas cou;
    memset(cou.num, 0, sizeof(cou.num));
    if ((i == 1) && (j == 1))
    {
        cou.num[nmax] = 1;
        return cou;
    }
    if ((i > 1) && (j > 2))
    {
        if (comp_0(f[i - 1][j - 2]))
            cou = sum(cou, srch(i - 1, j - 2));
        else
            cou = sum(cou, f[i - 1][j - 2]);
    }
    if ((i > 2) && (j > 1))
    {
        if (comp_0(f[i - 2][j - 1]))
            cou = sum(cou, srch(i - 2, j - 1));
        else
            cou = sum(cou, f[i - 2][j - 1]);
    }
    if ((i < n) && (j > 2))
    {
        if (comp_0(f[i + 1][j - 2]))
            cou = sum(cou, srch(i + 1, j - 2));
        else
            cou = sum(cou, f[i + 1][j - 2]);
    }
    if ((i > 2) && (j < m))
    {
        if (comp_0(f[i - 2][j + 1]))
            cou = sum(cou, srch(i - 2, j + 1));
        else
            cou = sum(cou, f[i - 2][j + 1]);
    }
    f[i][j] = cou;
    return cou;
}

void out(tmas a)
{
    int i = 1;
    while ((a.num[i] == 0) && (i < nmax))
        i++;
    For(j, i, nmax)
        printf("%d", a.num[j]);
}

int main()
{
    freopen("knight2.in", "r", stdin);
    freopen("knight2.out", "w", stdout);
    scanf("%d%d", &n, &m);
    memset(f, 0, sizeof(f));
    /*f[1][1].num[nmax]=1;
	For(i,1,n)
		For(j,1,m)
		{
			f[i-1][j+2]+=f[i][j];
			f[i+2][j-1]+=f[i][j];
			f[i+2][j+1]+=f[i][j];
			f[i+1][j+2]+=f[i][j];
		}*/
    tmas ans = srch(n, m);
    out(ans);
    printf("\n");
    /*For(i,1,n)
	{
		For(j,1,m)
		{
			out(f[i][j]);
			printf(" ");
		}
		printf("\n");
	}*/
    return 0;
}
