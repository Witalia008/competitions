#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 2000000
#define N 1005

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;

int n, s;
int c3, c4, c5, k3, k4, k5, g;
int ans = Inf;
int K3, K4, K5;

int Abs(int a)
{
    if (a < 0)
        return -a;
    return a;
}

int f(int xk3, int xk4, int xk5)
{
    return Abs(xk3 * c3 - xk4 * c4) + Abs(xk4 * c4 - xk5 * c5);
}

void gcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        g = a;
        return;
    }
    int x1, y1;
    gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * ll(a / b);
}

int F(int k)
{
    ll xk4 = k4 + (c5 / g) * k;
    ll xk5 = k5 - (c4 / g) * k;
    if (k3 <= xk4 && xk4 <= xk5)
    {
        int x = f(k3, xk4, xk5);
        if (x < ans)
        {
            ans = x;
            K3 = k3;
            K4 = xk4;
            K5 = xk5;
        }
        return x;
    }
    if (xk5 < xk4)
        return Inf;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (a == 3)
            c3++;
        if (a == 4)
            c4++;
        if (a == 5)
            c5++;
    }
    for (k3 = 0; k3 <= s / c3; k3++)
    {
        int s1 = s - k3 * c3;
        gcd(c4, c5, k4, k5);
        if (s1 % g)
            continue;
        k4 *= (s1 / g);
        k5 *= (s1 / g);
        int k = (k3 - k4) / (c5 / g);
        k4 += k * (c5 / g);
        k5 -= k * (c4 / g);
        if (k4 < k3)
            k4 += c5 / g, k5 -= c4 / g;
        if (k4 - c5 / g >= k3)
            k4 -= c5 / g, k5 += c4 / g;
        int l = 0, r = Mi;
        while (l < r - 2)
        {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            if (F(m1) <= F(m2))
                r = m2;
            else
                l = m1;
        }
        for (int i = l; i <= r; i++)
        {
            int xk4 = k4 + (c5 / g) * i;
            int xk5 = k5 - (c4 / g) * i;
            if (k3 <= xk4 && xk4 <= xk5)
            {
                int x = f(k3, xk4, xk5);
                if (x < ans)
                {
                    ans = x;
                    K3 = k3;
                    K4 = xk4;
                    K5 = xk5;
                }
            }
        }
    }
    if (ans == Inf)
        cout << "-1\n";
    else
        printf("%d %d %d\n", K3, K4, K5);
    return 0;
}
