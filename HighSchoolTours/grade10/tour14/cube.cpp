#include <stdio.h>
#include <cstdlib>
#include <iostream>
#define sqr(a) ((a) * (a))

using namespace std;

int main()
{
    freopen("cube.dat", "r", stdin);
    freopen("cube.res", "w", stdout);
    int a, n;
    cin >> a >> n;
    cout << a << " " << n << "\n";
    for (int i = 1; i <= n; i++)
    {
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        cout << x1 << " " << y1 << " " << z1 << " " << x2 << " " << y2 << " " << z2 << " ";
        int ans = 1000;
        int nx1 = x1, nx2 = x2, nz1 = z1, nz2 = z2;
        //plus to x
        if (y1 != 0)
        {
            if (y1 == a)
                nx1 = 3 * a - x1;
            else
            {
                if (x1 == 0)
                    nx1 = -y1;
                else if (x1 == a)
                    nx1 = a + y1;
                else if (z1 == 0)
                    nz1 = -y1;
                else if (z1 == a)
                    nz1 = a + y1;
            }
        }
        if (y2 != 0)
        {
            if (y2 == a)
                nx2 = 3 * a - x2;
            else
            {
                if (x2 == 0)
                    nx2 = -y2;
                else if (x2 == a)
                    nx2 = a + y2;
                else if (z2 == 0)
                    nz2 = -y2;
                else if (z2 == a)
                    nz2 = a + y2;
            }
        }
        if (sqr(nx1 - nx2) + sqr(nz1 - nz2) < ans)
            ans = sqr(nx1 - nx2) + sqr(nz1 - nz2);
        //minus to x
        nx1 = x1;
        nx2 = x2;
        nz1 = z1;
        nz2 = z2;
        if (y1 != 0)
        {
            if (y1 == a)
                nx1 = -a - x1;
            else
            {
                if (x1 == 0)
                    nx1 = -y1;
                else if (x1 == a)
                    nx1 = a + y1;
                else if (z1 == 0)
                    nz1 = -y1;
                else if (z1 == a)
                    nz1 = a + y1;
            }
        }
        if (y2 != 0)
        {
            if (y2 == a)
                nx2 = -a - x2;
            else
            {
                if (x2 == 0)
                    nx2 = -y2;
                else if (x2 == a)
                    nx2 = a + y2;
                else if (z2 == 0)
                    nz2 = -y2;
                else if (z2 == a)
                    nz2 = a + y2;
            }
        }
        if (sqr(nx1 - nx2) + sqr(nz1 - nz2) < ans)
            ans = sqr(nx1 - nx2) + sqr(nz1 - nz2);
        //plus to z
        nx1 = x1;
        nx2 = x2;
        nz1 = z1;
        nz2 = z2;
        if (y1 != 0)
        {
            if (y1 == a)
                nz1 = 3 * a - z1;
            else
            {
                if (x1 == 0)
                    nx1 = -y1;
                else if (x1 == a)
                    nx1 = a + y1;
                else if (z1 == 0)
                    nz1 = -y1;
                else if (z1 == a)
                    nz1 = a + y1;
            }
        }
        if (y2 != 0)
        {
            if (y2 == a)
                nz2 = 3 * a - z2;
            else
            {
                if (x2 == 0)
                    nx2 = -y2;
                else if (x2 == a)
                    nx2 = a + y2;
                else if (z2 == 0)
                    nz2 = -y2;
                else if (z2 == a)
                    nz2 = a + y2;
            }
        }
        if (sqr(nx1 - nx2) + sqr(nz1 - nz2) < ans)
            ans = sqr(nx1 - nx2) + sqr(nz1 - nz2);
        //minus to z
        nx1 = x1;
        nx2 = x2;
        nz1 = z1;
        nz2 = z2;
        if (y1 != 0)
        {
            if (y1 == a)
                nz1 = -a - z1;
            else
            {
                if (x1 == 0)
                    nx1 = -y1;
                else if (x1 == a)
                    nx1 = a + y1;
                else if (z1 == 0)
                    nz1 = -y1;
                else if (z1 == a)
                    nz1 = a + y1;
            }
        }
        if (y2 != 0)
        {
            if (y2 == a)
                nz2 = -a - z2;
            else
            {
                if (x2 == 0)
                    nx2 = -y2;
                else if (x2 == a)
                    nx2 = a + y2;
                else if (z2 == 0)
                    nz2 = -y2;
                else if (z2 == a)
                    nz2 = a + y2;
            }
        }
        if (sqr(nx1 - nx2) + sqr(nz1 - nz2) < ans)
            ans = sqr(nx1 - nx2) + sqr(nz1 - nz2);
        //if they are adjacent
        if (x1 == 0 && (z2 == 0 || z2 == a))
        {
            nx1 = -z1;
            nz1 = y1;
            nz2 = y2;
            if (sqr(nx1 - nx2) + sqr(nz1 - nz2) < ans)
                ans = sqr(nx1 - nx2) + sqr(nz1 - nz2);
        }
        if (x2 == 0 && (z1 == 0 || z1 == a))
        {
            nx2 = -z2;
            nz2 = y2;
            nz1 = y1;
            if (sqr(nx1 - nx2) + sqr(nz1 - nz2) < ans)
                ans = sqr(nx1 - nx2) + sqr(nz1 - nz2);
        }
        if (x1 == a && (z2 == 0 || z2 == a))
        {
            nx1 = a + z1;
            nz1 = y1;
            nz2 = y2;
            if (sqr(nx1 - nx2) + sqr(nz1 - nz2) < ans)
                ans = sqr(nx1 - nx2) + sqr(nz1 - nz2);
        }
        if (x2 == a && (z1 == 0 || z1 == a))
        {
            nx2 = a + z2;
            nz2 = y2;
            nz1 = y1;
            if (sqr(nx1 - nx2) + sqr(nz1 - nz2) < ans)
                ans = sqr(nx1 - nx2) + sqr(nz1 - nz2);
        }
        cout << ans << "\n";
    }
    return 0;
}
