#include <stdio.h>
#include <cstdlib>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

struct tmas
{
    int len;
    int num[50];
};

void swap(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

tmas ans;

int main()
{
    long n;
    scanf("%ld", &n);
    bool fl = true;
    ans.len = 0;
    while ((n != 1) && (fl))
    {
        int i = 9;
        while ((i > 1) && (n % i != 0))
            i--;
        if (i == 1)
            fl = false;
        else
        {
            ans.len++;
            ans.num[ans.len] = i;
            n = n / i;
        }
    }
    if (fl)
    {
        if (ans.len == 0)
            printf("1\n");
        else
        {
            for (int i = ans.len; i > 1; i--)
                For(j, 1, i - 1) if (ans.num[j] > ans.num[j + 1])
                    swap(ans.num[j], ans.num[j + 1]);
            For(j, 1, ans.len)
                printf("%d", ans.num[j]);
            printf("\n");
        }
    }
    else
        printf("0\n");
    system("PAUSE");
    return 0;
}
