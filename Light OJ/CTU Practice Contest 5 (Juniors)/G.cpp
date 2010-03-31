#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#include <math.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define min(a, b) (a < b) ? a : b;
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 1000000007
#define N 1000005

typedef long double ld;
typedef unsigned long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;

int Abs(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

double sq(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int n;
string s;

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    int T;
    scanf("%d\n", &T);
    REP(t, T)
    {
        printf("Case %d: ", t + 1);
        scanf("%d", &n);
        s = "";
        while (n)
        {
            s += n % 2 + '0';
            n /= 2;
        }
        s += '0';
        REP(i, s.length() - 1)
        if (s[i] == '1' && s[i + 1] == '0')
        {
            swap(s[i], s[i + 1]);
            int cs = 0;
            REP(j, i)
            cs += (s[j] == '1');
            REP(j, i)
            {
                if (cs > 0)
                    s[j] = '1';
                else
                    s[j] = '0';
                cs--;
            }
            break;
        }
        for (int i = s.length() - 1; i >= 0; i--)
            n = n * 2 + s[i] - '0';
        printf("%d\n", n);
    }
    return 0;
}
