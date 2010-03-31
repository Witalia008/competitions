#include <stdio.h>
#include <cstdlib>
#include <string.h>

using namespace std;

int n;
char a[50001];
int f[50001];

bool isVowel(char q)
{
    if (q == 'a' || q == 'e' || q == 'i' || q == 'o' || q == 'u' || q == 'y' || q == 'A' || q == 'E' || q == 'I' || q == 'O' || q == 'U' || q == 'Y')
        return true;
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s\n", &a);
        int cnt = 0;
        if (isVowel(a[0]))
            f[0] = 1;
        else
            f[0] = 0, cnt = 1;
        for (int j = 1; j < strlen(a); j++)
        {
            cnt++;
            if (isVowel(a[j]))
            {
                f[j] = f[j - 1] * (cnt + 1);
                if (!f[j])
                    f[j] = 1;
                cnt = 0;
            }
            else
                f[j] = f[j - 1];
        }
        printf("%d\n", f[strlen(a) - 1]);
    }
    return 0;
}
