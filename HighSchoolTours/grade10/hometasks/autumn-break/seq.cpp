#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int test, n, cur, j, mn;
int nums[3], cou[3];
bool ex, sr;

int main()
{
    freopen("seq.dat", "r", stdin);
    freopen("seq.res", "w", stdout);
    scanf("%d", &test);
    For(i, 1, test)
    {
        scanf("%d", &n);
        sr = true;
        mn = 0;
        For(k, 1, n)
        {
            scanf("%d", &cur);
            if (sr)
            {
                ex = false;
                For(j, 1, mn) if (nums[j] == cur)
                {
                    ex = true;
                    cou[j]++;
                }
                if (!ex)
                    if (mn < 2)
                    {
                        mn++;
                        cou[mn] = 1;
                        nums[mn] = cur;
                    }
                    else
                        sr = false;
            }
        }
        if ((sr) && ((mn < 2) || (cou[1] == cou[2])))
            printf("1\n");
        else
            printf("0\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
