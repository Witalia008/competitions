#include <stdio.h>
#include <cstdlib>

using namespace std;

int gcd(int a, int b)
{
    while ((a != 0) && (b != 0))
        if (a > b)
            a = a % b;
        else
            b = b % a;
    if (a == 0)
        return b;
    else
        return a;
}

int main()
{
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int l1 = abs(x2 - x1);
    int l2 = abs(y2 - y1);
    int ans;
    ans = gcd(l1, l2) - 1;
    if (ans != -1)
        printf("%d\n", ans);
    else
        printf("0\n");
    system("PAUSE");
    return 0;
}
