#include <stdio.h>
#include <cstdlib>

using namespace std;

#define NMAX 100005

struct pt
{
    int x, y;
};

inline int vd(pt a, pt b, pt c)
{
    return ((b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x));
}

int K, N;
pt A[NMAX];

int main()
{
    scanf("%d", &K);
    for (int k = 0; k < K; k++)
    {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            scanf("%d%d", &A[i].x, &A[i].y);
        A[0] = A[N];
        A[N + 1] = A[1];

        int ans = 0, n = N;
        for (int i = 1; i <= N; i++)
        {
            int v = vd(A[i - 1], A[i], A[i + 1]);
            if (v == 0)
                n--;
            if (v > 0)
                ans++;
        }
        printf("%d", (ans == n || ans == 0));
        printf((k == K - 1) ? "\n" : " ");
    }
    return 0;
}
