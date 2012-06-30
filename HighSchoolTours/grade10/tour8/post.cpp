#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int step[1004];
int top, en;
int stack[200010], sol[100000];
int m[1001][1001];

int main()
{
    freopen("post.in", "r", stdin);
    freopen("post.out", "w", stdout);
    int n;
    scanf("%d", &n);
    memset(step, 0, sizeof(step));
    memset(m, 0, sizeof(m));
    en = 0;
    For(i, 1, n)
    {
        scanf("%d", &step[i]);
        en += step[i];
        int k;
        double t;
        For(j, 1, step[i])
        {
            scanf("%d%lf", &k, &t);
            m[i][k]++;
        }
    }
    en = en / 2;
    int start = 1;
    For(i, 2, n) if (step[i] % 2 == 1) start = i;
    top = 1;
    stack[top] = start;
    int ans = 0;
    while (top > 0)
    {
        int v = stack[top];
        int j = 1;
        while ((m[v][j] == 0) && (j <= n))
            j++;
        if (j <= n)
        {
            step[j]--;
            step[v]--;
            m[v][j]--;
            m[j][v]--;
            top++;
            stack[top] = j;
            en--;
        }
        else
        {
            if (en == 0)
            {
                while (top > 0)
                {
                    ans++;
                    sol[ans] = stack[top];
                    top--;
                }
            }
            else
            {
                while (step[stack[top]] == 0)
                {
                    ans++;
                    sol[ans] = stack[top];
                    top--;
                }
            }
        }
    }
    printf("%d\n", ans - 1);
    for (int i = ans; i > 1; i--)
        printf("%d ", sol[i]);
    printf("%d\n", sol[1]);
    return 0;
}
