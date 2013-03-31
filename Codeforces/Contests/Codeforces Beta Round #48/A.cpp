#include <stdio.h>
#include <cstdlib>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

struct tt
{
    char n[2][2];
};

bool rivn(tt a, tt b)
{
    if (a.n[0][0] == b.n[0][0] && a.n[0][1] == b.n[0][1] && a.n[1][0] == b.n[1][0] && a.n[1][1] == b.n[1][1])
        return true;
    if (a.n[0][1] == b.n[0][0] && a.n[1][1] == b.n[0][1] && a.n[1][0] == b.n[1][1] && a.n[0][0] == b.n[1][0])
        return true;
    if (a.n[1][0] == b.n[0][0] && a.n[0][0] == b.n[0][1] && a.n[0][1] == b.n[1][1] && a.n[1][1] == b.n[1][0])
        return true;
    if (a.n[1][1] == b.n[0][0] && a.n[1][0] == b.n[0][1] && a.n[0][0] == b.n[1][1] && a.n[0][1] == b.n[1][0])
        return true;
    return false;
}

tt a[1001], sol[1001];

int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    int n;
    scanf("%d\n", &n);
    char a1[3], a2[3];
    For(i, 1, n)
    {
        if (i != 1)
            scanf("%s\n", &a1);
        scanf("%s\n", &a1);
        scanf("%s\n", &a2);
        a[i].n[0][0] = a1[0];
        a[i].n[0][1] = a1[1];
        a[i].n[1][0] = a2[0];
        a[i].n[1][1] = a2[1];
    }
    int top = 0;
    For(i, 1, n)
    {
        bool fl = false;
        For(j, 1, top) if (rivn(a[i], sol[j])) fl = true;
        if (!fl)
        {
            top++;
            sol[top] = a[i];
        }
    }
    printf("%d\n", top);
    return 0;
}
