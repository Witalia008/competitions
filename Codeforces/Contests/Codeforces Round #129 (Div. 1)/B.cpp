#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define min(a, b) (a < b) ? a : b;
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 1000000007
#define N 100005

typedef long double ld;
typedef unsigned long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;

int n, k, ans;
int x[N], y[N];
map<int, int> top, back, co;

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    scanf("%d", &n);
    k = n / 2 + n % 2;
    REP(i, n)
    {
        scanf("%d%d", &x[i], &y[i]);
        top[x[i]]++;
        back[y[i]]++;
        if (x[i] == y[i])
            co[x[i]]++;
    }
    ans = -1;
    REP(i, n)
    {
        int c = top[x[i]];
        if (c >= k)
            ans = 0;
        else
        {
            int cb = back[x[i]] ? back[x[i]] : 0;
            if (co[x[i]])
                cb -= co[x[i]];
            if (c + cb >= k && (ans == -1 || ans > k - c))
                ans = k - c;
        }
    }
    REP(i, n)
    if (ans == -1 && back[y[i]] >= k)
        ans = k;
    printf("%d\n", ans);
    return 0;
}
