#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int m[1001];

int main()
{
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    memset(m, 0, sizeof(m));
    For(i, 1, k)
    {
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        m[a] -= t;
        m[b] += t;
    }
    int ans = 0;
    For(i, 1, n) if (m[i] < 0) ans += abs(m[i]);
    printf("%d\n", ans);
    system("PAUSE");
    return 0;
}
