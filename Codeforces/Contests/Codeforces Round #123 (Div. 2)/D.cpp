#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define N 100005

typedef long double ld;
typedef long long ll;

typedef pair<int, int> pii;

set<pii> S;
int n;

int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

int Abs(int a)
{
    if (a < 0)
        return -a;
    return a;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int k, b;
        scanf("%d%d", &k, &b);
        if (k != 0)
        {
            int g = gcd(Abs(k), Abs(b));
            k /= g;
            b /= g;
            if (k < 0)
                k = -k, b = -b;
            S.insert(make_pair(k, b));
        }
    }
    printf("%d\n", S.size());
    return 0;
}
