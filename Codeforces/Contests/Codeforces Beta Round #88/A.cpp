#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;
using std::max;

#define nmax 100
#define sqr(a) ((a) * (a))
#define abs(a) (a < 0) ? (-a) : a
#define all(a) a.begin(), a.end()

int n, m, s, f, t;

int main()
{
    //ifstream cin ("input.txt"); ofstream cout ("output.txt");
    //freopen ("input.txt", "r", stdin); freopen ("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &s, &f, &t);
        if (s == f)
            printf("%d\n", t);
        else
        {
            int cou = t / (2 * (m - 1));
            int left = t % (2 * (m - 1));
            if (left >= m - 1) // lift is going down
            {
                if (left - m + 1 <= m - s) // he woun't be late
                {
                    if (f > s)
                        printf("%d\n", (cou + 1) * 2 * (m - 1) + f - 1);
                    else
                        printf("%d\n", (cou + 1) * 2 * (m - 1) - f + 1);
                }
                else // he'll be late
                {
                    if (f > s)
                        printf("%d\n", (cou + 1) * 2 * (m - 1) + f - 1);
                    else
                        printf("%d\n", (cou + 2) * 2 * (m - 1) - f + 1);
                }
            }
            else // lift is going up
            {
                if (left < s) // he won't be late
                {
                    if (f > s)
                        printf("%d\n", cou * 2 * (m - 1) + f - 1);
                    else
                        printf("%d\n", (cou + 1) * 2 * (m - 1) - f + 1);
                }
                else // he'll be late
                {
                    if (f > s)
                        printf("%d\n", (cou + 1) * 2 * (m - 1) + f - 1);
                    else
                        printf("%d\n", (cou + 1) * 2 * (m - 1) - f + 1);
                }
            }
        }
    }
    return 0;
}
