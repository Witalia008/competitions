#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;
using std::min;

#define nmax 100
#define sqr(a) ((a) * (a))
#define abs(a) (a < 0) ? (-a) : a
#define all(a) a.begin(), a.end()

long long a, b, mod, i, md, ans, mx;

int main()
{
    //ifstream cin ("input.txt"); ofstream cout ("output.txt");
    //freopen ("input.txt", "r", stdin); freopen ("output.txt", "w", stdout);
    cin >> a >> b >> mod;
    md = min(a + 1, mod);
    for (i = 0; i < md; i++)
    {
        ans = (i * 1000000000LL) % mod;
        mx = mod - ans;
        if (mx == mod)
            mx = 0;
        if (mx > b)
        {
            printf("1 %09d\n", i);
            return 0;
        }
    }
    printf("2\n");
    return 0;
}
