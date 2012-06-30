#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "sort.in";
const char *outfile = "sort.out";

int N, ans;
int a[20], f[20];

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    f[0] = 1;
    for (int i = 1; i < N; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
            if (f[j] + 1 > f[i] && a[j] < a[i])
                f[i] = f[j] + 1;
    }
    ans = 0;
    for (int i = 0; i < N; i++)
        if (f[i] > ans)
            ans = f[i];
    printf("%d\n", N - ans);
    return 0;
}
