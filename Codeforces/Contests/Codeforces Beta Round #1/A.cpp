#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#define eps 10e-5
#define abs(a) (((a) < 0) ? (-a) : (a))
#define sqr(a) ((a) * (a))
#define nmax 100000
#define MP make_pair

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

int main()
{
    //ifstream cin ("input.txt"); ofstream cout ("output.txt");
    //freopen ("input.txt", "r", stdin); freopen ("output.txt", "w", stdout);
    long long n, m, a;
    cin >> n >> m >> a;
    long long ans = (n / a) * (m / a);
    if (n % a)
        ans += m / a;
    if (m % a)
        ans += n / a;
    if (m % a && n % a)
        ans++;
    cout << ans << endl;
    return 0;
}
