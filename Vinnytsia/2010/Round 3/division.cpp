#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <memory.h>
#include <set>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

long long A[105], a, b, k, ans;
set<long> s;

void srch(int i, long long dob)
{
    int c = (a / dob) * dob;
    if (dob != 1)
        while (c <= b)
        {
            if (c <= b && c >= a && c != 1 && s.find(c) == s.end())
            {
                ans++;
                s.insert(c);
            }
            c += dob;
        }
    if (i <= k)
    {
        srch(i + 1, dob);
        if (dob * A[i] <= b)
            srch(i + 1, dob * A[i]);
    }
}

int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    scanf("%lld%lld%lld", &a, &b, &k);
    For(i, 1, k)
        scanf("%lld", &A[i]);
    ans = 0;
    if (a > b)
        swap(a, b);
    if ((b - a) * k <= 1234567)
    {
        For(i, a, b)
        {
            bool fl = true;
            For(j, 1, k) if (i % A[j] == 0) fl = false;
            if (!fl)
                ans++;
        }
    }
    else
        srch(1, 1);
    printf("%lld\n", b - a - ans + 1);
    return 0;
}
