#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <iostream>

using namespace std;

int sqr(int a) { return a * a; }

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int x1, y1, r1, x2, y2, r2;
    scanf("%d%d%d", &x1, &y1, &r1);
    scanf("%d%d%d", &x2, &y2, &r2);
    double d = sqrt(1.0 * (sqr(x1 - x2) + sqr(y1 - y2)));
    if (r1 < r2)
    {
        swap(x1, x2);
        swap(y1, y2);
        swap(r1, r2);
    }
    if (d < r1 + r2)
    {
        if (d >= r1 && d >= r2)
            printf("0.000000\n");
        else
        {
            if (d < r1)
            {
                if (d + r2 < r1)
                    printf("%0.6lf\n", (r1 - d - r2) / 2);
                else
                    printf("0.000000\n");
            }
            else
            {
                if (d + r1 < r2)
                    printf("%0.6lf\n", (r2 - d - r1) / 2);
                else
                    printf("0.000000\n");
            }
        }
    }
    else
        printf("%0.6lf\n", (d - r1 - r2) / 2);
    return 0;
}
