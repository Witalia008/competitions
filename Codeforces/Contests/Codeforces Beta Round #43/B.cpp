#include <stdio.h>
#include <cstdlib>
#include <cstring>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

char a[4];
int m[6];

void print(int j)
{
    if (j == 1)
        printf("S\n");
    if (j == 2)
        printf("M\n");
    if (j == 3)
        printf("L\n");
    if (j == 4)
        printf("XL\n");
    if (j == 5)
        printf("XXL\n");
}

int main()
{
    /*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
    scanf("%d%d%d%d%d\n", &m[1], &m[2], &m[3], &m[4], &m[5]);
    int k;
    scanf("%d\n", &k);
    For(i, 1, k)
    {
        scanf("%s\n", &a);
        if (a[0] == 'S')
        {
            int j = 1;
            while (m[j] == 0)
                j++;
            m[j]--;
            print(j);
        }
        if (a[0] == 'M')
        {
            int j = 2, l = 2;
            while ((m[l] == 0) && (l >= 1))
                l--;
            while ((m[j] == 0) && (j <= 5))
                j++;
            if (l < 1)
            {
                print(j);
                m[j]--;
            }
            if (j > 5)
            {
                print(l);
                m[l]--;
            }
            if ((l > 0) && (j <= 5))
            {
                if (2 - l < j - 2)
                {
                    print(l);
                    m[l]--;
                }
                if (2 - l >= j - 2)
                {
                    print(j);
                    m[j]--;
                }
            }
        }
        if (a[0] == 'L')
        {
            int j = 3, l = 3;
            while ((m[l] == 0) && (l >= 1))
                l--;
            while ((m[j] == 0) && (j <= 5))
                j++;
            if (l < 1)
            {
                print(j);
                m[j]--;
            }
            if (j > 5)
            {
                print(l);
                m[l]--;
            }
            if ((l > 0) && (j <= 5))
            {
                if (3 - l < j - 3)
                {
                    print(l);
                    m[l]--;
                }
                else
                {
                    print(j);
                    m[j]--;
                }
            }
        }
        if ((a[0] == 'X') && (a[1] == 'L'))
        {
            int j = 4, l = 4;
            while ((m[l] == 0) && (l >= 1))
                l--;
            while ((m[j] == 0) && (j <= 5))
                j++;
            if (l < 1)
            {
                print(j);
                m[j]--;
            }
            if (j > 5)
            {
                print(l);
                m[l]--;
            }
            if ((l > 0) && (j <= 5))
            {
                if (4 - l < j - 4)
                {
                    print(l);
                    m[l]--;
                }
                else
                {
                    print(j);
                    m[j]--;
                }
            }
        }
        if ((a[0] == 'X') && (a[1] == 'X'))
        {
            int l = 5;
            while ((m[l] == 0) && (l >= 1))
                l--;
            print(l);
            m[l]--;
        }
    }
    return 0;
}
