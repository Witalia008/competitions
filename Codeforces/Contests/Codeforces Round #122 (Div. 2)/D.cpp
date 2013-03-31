#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef long long ll;

#define N 35
#define max(a, b) (a > b) ? (a) : (b)

ll a[N], b[N], p[N], k[N], ax[N][N];
int n, u, r;
ll ans = -1000000000000000000;

void func(int pos, int last)
{
    if ((u - pos) % 2 == 0)
    {
        ll cans = 0;
        for (int i = 1; i <= n; i++)
            cans += ax[pos][i] * k[i];
        ans = max(ans, cans);
        if (pos == u)
            return;
    }
    if (last != 1)
    {
        for (int i = 1; i <= n; i++)
            ax[pos + 1][i] = ax[pos][i] ^ b[i];
        func(pos + 1, 1);
    }
    for (int i = 1; i <= n; i++)
        ax[pos + 1][i] = ax[pos][p[i]] + r;
    func(pos + 1, 2);
}

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &u, &r);
    for (int i = 1; i <= n; i++)
        cin >> a[i], ax[0][i] = a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> k[i];
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    func(0, 0);
    cout << ans << endl;
    return 0;
}
