#include <stdio.h>
#include <cstdlib>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

struct tmas
{
    int n[9][9];
};

tmas b, a;

int main()
{
    freopen("ritual.dat", "r", stdin);
    freopen("ritual.res", "w", stdout);
    int n;
    scanf("%d", &n);
    For(i, 1, 7)
        For(j, 1, 7)
            scanf("%d", &a.n[i][j]);
    For(count, 1, 952 - n)
    {
        For(i, 1, 7)
            For(j, 1, 7)
        {
            b.n[i][j] = (a.n[i][j + 1] + a.n[i + 1][j + 1] + a.n[i + 1][j] + a.n[i + 1][j - 1] + a.n[i][j - 1] + a.n[i - 1][j - 1] + a.n[i - 1][j] + a.n[i - 1][j + 1] + a.n[i][j]) % 13;
            if (b.n[i][j] == 0)
                b.n[i][j] = 13;
        }
        a = b;
    }
    For(i, 1, 7)
    {
        For(j, 1, 6)
            printf("%d ", a.n[i][j]);
        printf("%d\n", a.n[i][7]);
    }
    return 0;
}
