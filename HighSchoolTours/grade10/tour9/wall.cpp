#include <stdio.h>
#include <cstdlib>
#include <math.h>
#define sqr(a) ((a) * (a))
#define nmax 10000
#define pi 3.14159265358979323846264338327950288419716939937510

using namespace std;

struct tmas
{
    int x, y;
};

tmas list[nmax], stack[nmax];

bool right(tmas p1, tmas p2, tmas p3)
{
    int x1 = (p1.x - p2.x);
    int x2 = (p3.x - p2.x);
    int y1 = (p1.y - p2.y);
    int y2 = (p3.y - p2.y);
    if (x1 * y2 - x2 * y1 > 0)
        return true;
    else
        return false;
}

int main()
{
    freopen("wall.in", "r", stdin);
    freopen("wall.out", "w", stdout);
    int n, l;
    double ans = 0;
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &list[i].x, &list[i].y);
    if (n > 2)
    {
        int ii = 1;
        for (int i = 2; i <= n; i++)
            if ((list[i].y < list[ii].y) || ((list[i].y == list[ii].y) && (list[i].x < list[ii].x)))
                ii = i;
        int top = 2;
        stack[1] = list[ii];
        stack[2] = list[ii % n + 1];
        int j = (ii % n + 1) % n + 1;
        while ((!right(stack[1], stack[2], list[j])) && (j != ii))
        {
            stack[2] = list[j];
            j = j % n + 1;
        }
        while (j != ii)
        {
            while (!right(stack[top - 1], stack[top], list[j]))
                top--;
            stack[top + 1] = list[j];
            top++;
            j = j % n + 1;
        }
        while (!right(stack[top - 1], stack[top], list[j]))
            top--;
        stack[top + 1] = list[j];
        for (int i = 1; i <= top; i++)
            ans += sqrt((double)(sqr(stack[i].x - stack[i + 1].x) + sqr(stack[i].y - stack[i + 1].y)));
    }
    else
    {
        if (n == 2)
            ans = sqrt((double)(sqr(list[1].x - list[2].x) + sqr(list[1].y - list[2].y))) * 2;
        if (n == 1)
            ans = 0;
    }
    ans += pi * 2 * l;
    if (((int)(ans * 10)) % 10 <= 5)
        printf("%d\n", (int)ans);
    else
        printf("%d\n", (int)ans + 1);
    return 0;
}
