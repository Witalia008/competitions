#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 1000000007
#define N 100005

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

struct xx
{
    int f, i;
};

bool comp(xx a, xx b)
{
    if (a.f < b.f)
        return true;
    if (a.f > b.f)
        return false;
    return a.i < b.i;
}

int n, k;
xx A[N];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    REP(i, n)
    {
        scanf("%d", &A[i].f);
        A[i].i = i;
    }
    sort(A, A + n, &comp);
    int ans = 1;
    int l = 0;
    FOR(r, 1, n - 1)
    if (A[r].f != A[r - 1].f || A[r].i - A[l].i >= k)
    {
        l = r;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
