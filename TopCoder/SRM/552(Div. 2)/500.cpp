#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

class FoxPaintingBalls
{
public:
    ll theMax(ll R, ll G, ll B, int N)
    {
        if (N == 1)
            return R + G + B;
        ll all = ll(N) * ll(N + 1) / 2;
        return min(min(R / (all / 3), G / (all / 3)), min(B / (all / 3), (R + G + B) / all));
    }
};
