#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

ll gcd (ll a, ll b)
{
   if (!b) return a;
   return gcd (b, a % b);
}

int n, m;
ll ans;
int A[1000001];

int main ()
{
   freopen ("input.txt", "r", stdin);
   freopen ("output.txt", "w", stdout);
   scanf ("%d%d", &n, &m);
   for (int i = 0; i < m; i++)
       scanf ("%d", &A[i]);
   sort (A, A + m);
   A[m] = A[0] + n;
   for (int i = 1; i <= m; i++)
   {
       ll cur = A[i] - A[i-1];
       if (cur < 0) cur += n;
       ans += cur*(cur-1)/2;
   }
   ll g = gcd (ans, ll(n));
   ans /= g;
   n /= g;
   cout << ans << "/" << n << endl;
   return 0;
}
