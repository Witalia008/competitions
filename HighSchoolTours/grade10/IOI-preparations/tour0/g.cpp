#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define N 1001

int n, m, ans;
int l[N], r[N];
bool used[N];

inline bool cross(int i, int j)
{
    if (l[i] > l[j])
        swap(i, j);
    return (r[i] >= l[j]);
}

int main()
{
    freopen("g.in", "r", stdin);
    freopen("g.out", "w", stdout);
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &l[i], &r[i]);
    ans = n;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (!used[j] && cross(i, j))
                used[j] = true, ans--;
    }
    printf("%d\n", ans);
    return 0;
}
