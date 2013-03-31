#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int n, k;
int A[100005];

bool can(double len)
{
    int l = 0, cnt = 1;
    for (int i = 1; i < n; i++)
        if (A[i] - A[l] > len * 2)
            cnt++, l = i;
    return cnt <= k;
}

double bin_search(double l, double r)
{
    int cnt = 0;
    while (cnt < 64)
    {
        double mid = (r + l) / 2;
        if (can(mid))
            r = mid;
        else
            l = mid;
        cnt++;
    }
    return l;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    sort(A, A + n);
    printf("%0.2lf\n", bin_search(0, 1000000000));
    return 0;
}
