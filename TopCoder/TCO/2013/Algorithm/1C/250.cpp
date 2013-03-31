#include <stdio.h>
#include <cstdlib>

#define Inf 1000000000
using namespace std;

bool good(int mmax, int n, int d, int first, int last)
{
    int up = (mmax + d - 1 - last) / d;
    int down = (mmax + d - 1 - first) / d;
    return up + down < n;
}

int bin_search(int n, int d, int first, int last)
{
    int l = -Inf, r = Inf;
    while (l < r - 1)
    {
        int mid = (l + r) >> 1;
        if (good(mid, n, d, first, last))
            l = mid;
        else
            r = mid;
    }
    if (good(r, n, d, first, last))
        return r;
    return l;
}

class TheArray
{
public:
    int find(int n, int d, int first, int last)
    {
        if (!d)
            return first;
        return bin_search(n, d, first, last);
    }
};
