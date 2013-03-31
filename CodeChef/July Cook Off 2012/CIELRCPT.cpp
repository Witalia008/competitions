#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <list>
#include <fstream>
#include <time.h>
#include <iomanip>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define CLR(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define mp make_pair
#define eps 10e-6
#define Inf 1000000000
#define Mi 1000000007
#define N 1005

typedef double ld;
typedef unsigned long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<double, char> pdc;

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}
int Abs(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

int main()
{
    // freopen ("input.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    REP(t, T)
    {
        int p;
        scanf("%d", &p);
        int ans = 0;
        while (p >= 2048)
            ans++, p -= 2048;
        while (p)
        {
            ans += p % 2;
            p /= 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
