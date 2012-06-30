#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#define nmax 200

using namespace std;

struct TRect
{
    int x1, x2, y1, y2;
};

int bin(int a[nmax * 5], int x, int l, int r)
{
    while (l != r - 1)
    {
        int mid = (l + r) / 2;
        if (a[mid] == x)
            return mid;
        else
        {
            if (a[mid] < x)
                l = mid;
            else
                r = mid;
        }
    }
    if (a[l] == x)
        return l;
    else
        return r;
}

TRect a[nmax + 1];
int x[nmax * 5], y[nmax * 5];
int m[nmax * 5][nmax * 5];
int queue[2][nmax * nmax * 5];
int kx, ky;

int main()
{
    freopen("rectpart.in", "r", stdin);
    freopen("rectpart.out", "w", stdout);
    int n;
    scanf("%d", &n);
    kx = 0;
    ky = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
        bool fl = true;
        for (int j = 1; j <= kx; j++)
            if (x[j] == a[i].x1)
                fl = false;
        if (fl)
        {
            kx++;
            x[kx] = a[i].x1;
        }
        fl = true;
        for (int j = 1; j <= kx; j++)
            if (x[j] == a[i].x2)
                fl = false;
        if (fl)
        {
            kx++;
            x[kx] = a[i].x2;
        }
        fl = true;
        for (int j = 1; j <= ky; j++)
            if (y[j] == a[i].y1)
                fl = false;
        if (fl)
        {
            ky++;
            y[ky] = a[i].y1;
        }
        fl = true;
        for (int j = 1; j <= ky; j++)
            if (y[j] == a[i].y2)
                fl = false;
        if (fl)
        {
            ky++;
            y[ky] = a[i].y2;
        }
    }
    sort(x, x + kx + 1);
    sort(y, y + ky + 1);
    memset(m, 0, sizeof(m));
    for (int i = 1; i <= n; i++)
    {
        int x1, x2, y1, y2;
        x1 = bin(x, a[i].x1, 1, kx) * 2;
        x2 = bin(x, a[i].x2, 1, kx) * 2;
        if (x1 > x2)
            swap(x1, x2);
        y1 = bin(y, a[i].y1, 1, ky) * 2;
        y2 = bin(y, a[i].y2, 1, ky) * 2;
        if (y1 > y2)
            swap(y1, y2);
        for (int i = x1; i <= x2; i++)
        {
            m[i][y1] = -1;
            m[i][y2] = -1;
        }
        for (int i = y1; i <= y2; i++)
        {
            m[x1][i] = -1;
            m[x2][i] = -1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n * 4; i++)
        for (int j = 1; j <= n * 4; j++)
            if (m[i][j] == 0)
            {
                ans++;
                int head = 0, tail = 1;
                queue[0][0] = i;
                queue[1][0] = j;
                while (head < tail)
                {
                    int x = queue[0][head];
                    int y = queue[1][head];
                    m[x][y] = ans;
                    head++;
                    if (x < 4 * n && m[x + 1][y] == 0)
                    {
                        m[x + 1][y] = ans;
                        queue[0][tail] = x + 1;
                        queue[1][tail] = y;
                        tail++;
                    }
                    if (x > 1 && m[x - 1][y] == 0)
                    {
                        m[x - 1][y] = ans;
                        queue[0][tail] = x - 1;
                        queue[1][tail] = y;
                        tail++;
                    }
                    if (y < 4 * n && m[x][y + 1] == 0)
                    {
                        m[x][y + 1] = ans;
                        queue[0][tail] = x;
                        queue[1][tail] = y + 1;
                        tail++;
                    }
                    if (y > 1 && m[x][y - 1] == 0)
                    {
                        queue[0][tail] = x;
                        queue[1][tail] = y - 1;
                        m[x][y - 1] = ans;
                        tail++;
                    }
                }
            }
    if (ans > n * n + (n - 1) * (n - 1) + 1)
        ans = n * n + (n - 1) * (n - 1) + 1;
    printf("%d\n", ans);
    return 0;
}
