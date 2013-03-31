#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

#define N 100000

int A[N], B[N];
int n, k;
ll b, S;

bool bin_search(int l, int r, int x)
{
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        if (x <= B[mid])
            r = mid;
        else
            l = mid;
    }
    if (x == B[l] || x == B[r])
        return true;
    return false;
}

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    scanf("%d%d", &n, &k);
    cin >> b;
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    memcpy(B, A, sizeof(A));
    sort(B, B + n - 1);
    for (int i = 0; i < k; i++)
    {
        B[i] = B[i + n - k - 1];
        S += ll(B[i]);
    }
    int ans = n;
    for (int i = 0; i < n - 1; i++)
    {
        int cur = S - B[0];
        if (bin_search(0, k - 1, A[i]))
            cur = S - A[i];
        if (b - cur < A[i])
        {
            ans = i + 1;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
