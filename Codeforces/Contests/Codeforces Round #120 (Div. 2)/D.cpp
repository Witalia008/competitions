#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;

int n, k;
int a[400000];
map<int, int> Cnt;
long long ans;

int main()
{
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    Cnt[a[0]] = 1;
    int l = 0, r = 0;
    while (l < n)
    {
        while (r < n && Cnt[a[r]] < k)
            Cnt[a[++r]]++;
        if (r == n)
            break;
        ans += long long(n - r);
        Cnt[a[l++]]--;
    }
    cout << ans << endl;
    return 0;
}
