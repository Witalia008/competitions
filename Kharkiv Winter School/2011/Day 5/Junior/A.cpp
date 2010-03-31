#include <cstdio>

#include <algorithm>
#include <iostream>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)

const int maxn = (int)1e5 + 10;

int n, k, a[maxn], b[maxn], p[maxn], val[maxn], res[maxn];

bool pless(int i, int j)
{
    return val[i] > val[j];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long sum = 0;
    scanf("%d%d", &n, &k);
    forn(i, n)
    {
        scanf("%d%d", &a[i], &b[i]);
        val[i] = b[i] - a[i];
        p[i] = i;
        res[i] = 0;
        sum += a[i];
    }

    sort(p, p + n, pless);
    int Min = (n - k + 1) / 2;
    forn(i, n - Min) if (i < Min || val[p[i]] > 0)
        sum += val[p[i]],
        res[p[i]] ^= 1;

    cout << sum << endl;
    forn(i, n) if (i != n - 1)
        printf("%d ", res[i]);
    else printf("%d\n", res[i]);
    return 0;
}
