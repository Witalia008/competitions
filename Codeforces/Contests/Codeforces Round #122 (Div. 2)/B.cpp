#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef long long ll;

#define N 10

ll gcd(ll a, ll b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        ll n;
        cin >> n;
        cout << 4 * n / gcd(4 * n, n + 1) + 1 << endl;
    }
    return 0;
}
