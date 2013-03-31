#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define pb push_back
#define mp make_pair
#define Inf 1000000000
#define N 50005

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    int n;
    ld ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ld a;
        cin >> a;
        ans += a;
    }
    printf("%0.9lf\n", ans / n);
    return 0;
}
