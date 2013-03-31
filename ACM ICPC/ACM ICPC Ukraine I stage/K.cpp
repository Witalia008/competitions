#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define N 100005

int n, m, l;
vector<int> R[N];
int D[N];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &l, &n, &m);
    n += m;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        R[r].push_back(l);
    }
    for (int i = 1; i <= l; i++)
    {
        D[i] = D[i - 1];
        for (int j = 0; j < R[i].size(); j++)
            if (D[R[i][j]] + 1 > D[i])
                D[i] = D[R[i][j]] + 1;
    }
    printf("%d\n", D[l]);
    return 0;
}
