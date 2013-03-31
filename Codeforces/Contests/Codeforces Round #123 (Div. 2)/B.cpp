#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef unsigned long long ll;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define N 100005

struct TQ
{
    int cou, nom;
};

double Abs(double a)
{
    if (a < 0)
        return -a;
    return a;
}

int n, m, mm;
TQ Q[N];

bool lower(TQ a, TQ b)
{
    if (a.cou < b.cou)
        return true;
    if (a.cou > b.cou)
        return false;
    if (Abs((1.0 * (mm + 1)) / 2 - a.nom) < Abs((1.0 * (mm + 1)) / 2 - b.nom))
        return true;
    if (Abs((1.0 * (mm + 1)) / 2 - a.nom) > Abs((1.0 * (mm + 1)) / 2 - b.nom))
        return false;
    return a.nom < b.nom;
}

void ShiftUp(int i)
{
    while (i > 1 && lower(Q[i], Q[i / 2]))
        swap(Q[i], Q[i / 2]), i /= 2;
}

void ShiftDown(int i)
{
    while (i * 2 <= m)
    {
        int k = i;
        if (lower(Q[i * 2], Q[i]))
            k = i * 2;
        if (i * 2 + 1 <= m && lower(Q[i * 2 + 1], Q[k]))
            k = i * 2 + 1;
        if (i == k)
            i = m;
        else
        {
            swap(Q[i], Q[k]);
            i = k;
        }
    }
}

int main()
{
    // freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    scanf("%d%d", &n, &mm);
    for (int i = 1; i <= mm; i++)
    {
        m++;
        Q[m].cou = 0;
        Q[m].nom = i;
        ShiftUp(m);
    }
    for (int i = 1; i <= n; i++)
    {
        Q[1].cou++;
        printf("%d\n", Q[1].nom);
        ShiftDown(1);
    }
    return 0;
}
