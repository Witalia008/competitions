#include <stdio.h>
#include <cstdlib>

using namespace std;

#define N 10

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    if (k >= 3 * n)
        printf("0\n");
    else
        printf("%d\n", 3 * n - k);
    return 0;
}
