/* GCC */
#include <stdio.h>
#include <cstdlib>

using namespace std;

struct tpoint
{
    int x, y;
};

struct tsq
{
    tpoint n1, n2, n3, n4;
};

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

bool per(tpoint a1, tpoint a2, tpoint b1, tpoint b2)
{
    if ((a1.x == a2.x) && (b1.y == b2.y))
    {
        if ((min(b1.x, b2.x) <= a1.x) && (max(b1.x, b2.x) >= a1.x))
        {
            if ((min(a1.y, a2.y) <= b1.y) && (max(a1.y, a2.y) >= b1.y))
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else if ((a1.y == a2.y) && (b1.x == b2.x))
    {
        if ((min(b1.y, b2.y) <= a1.y) && (max(b1.y, b2.y) >= a1.y))
        {
            if ((min(a1.x, a2.x) <= b1.x) && (max(a1.x, a2.x) >= b1.x))
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}
int main()
{
    freopen("union.in", "r", stdin);
    freopen("union.out", "w", stdout);
    tsq a, b;
    scanf("%d%d%d%d%d%d%d%d", &a.n1.x, &a.n1.y, &a.n3.x, &a.n3.y, &b.n1.x, &b.n1.y, &b.n3.x, &b.n3.y);
    a.n2.x = a.n1.x;
    a.n2.y = a.n3.y;
    a.n4.x = a.n3.x;
    a.n4.y = a.n1.y;
    b.n2.x = b.n1.x;
    b.n2.y = b.n3.y;
    b.n4.x = b.n3.x;
    b.n4.y = b.n1.y;
    bool ans = false;

    if (per(a.n1, a.n2, b.n1, b.n2))
        ans = true;
    if (per(a.n1, a.n2, b.n3, b.n2))
        ans = true;
    if (per(a.n1, a.n2, b.n3, b.n4))
        ans = true;
    if (per(a.n1, a.n2, b.n1, b.n4))
        ans = true;

    if (per(a.n3, a.n2, b.n1, b.n2))
        ans = true;
    if (per(a.n3, a.n2, b.n3, b.n2))
        ans = true;
    if (per(a.n3, a.n2, b.n3, b.n4))
        ans = true;
    if (per(a.n3, a.n2, b.n1, b.n4))
        ans = true;

    if (per(a.n3, a.n4, b.n1, b.n2))
        ans = true;
    if (per(a.n3, a.n4, b.n3, b.n2))
        ans = true;
    if (per(a.n3, a.n4, b.n3, b.n4))
        ans = true;
    if (per(a.n3, a.n4, b.n1, b.n4))
        ans = true;

    if (per(a.n1, a.n4, b.n1, b.n2))
        ans = true;
    if (per(a.n1, a.n4, b.n3, b.n2))
        ans = true;
    if (per(a.n1, a.n4, b.n3, b.n4))
        ans = true;
    if (per(a.n1, a.n4, b.n1, b.n4))
        ans = true;

    if (ans)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
