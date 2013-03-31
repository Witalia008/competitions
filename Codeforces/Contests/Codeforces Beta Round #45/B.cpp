#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <memory.h>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int aa[100][100];

int main()
{
    /*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
    For(i, 1, 99)
        For(j, 1, 99)
            aa[i][j] = 10000;
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    For(i, 1, n)
        For(j, 1, m)
            scanf("%d", &aa[i][j]);
    scanf("%d%d", &a, &b);
    int ans = n * m;
    For(i, 1, n)
        For(j, 1, n)
    {
        int s = 0;
        For(ii, i, i + a - 1)
            For(jj, j, j + b - 1)
                s += aa[ii][jj];
        if (s < ans)
            ans = s;
        s = 0;
        For(ii, i, i + b - 1)
            For(jj, j, j + a - 1)
                s += aa[ii][jj];
        if (s < ans)
            ans = s;
    }
    printf("%d\n", ans);
    return 0;
}
