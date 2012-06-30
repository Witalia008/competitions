#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "a.in";
const char *outfile = "a.out";

int n, a, b;

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d%d%d", &n, &a, &b);
    int x = (b * n) / 100;
    for (int i = 0; i < n; i++)
    {
        printf("%d", a + (i < x ? 1 : 0));
        if (i == n - 1)
            printf("\n");
        else
            printf(" ");
    }
    return 0;
}
