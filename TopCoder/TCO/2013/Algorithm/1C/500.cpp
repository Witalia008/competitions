#include <stdio.h>
#include <cstdlib>
#include <vector>

using namespace std;

long long get(int score, vector<int> &sums)
{
    long long res = 0;
    for (int i = 0; i < sums.size(); i++)
        res += sums[i] / (score + 1);
    return res;
}

class TheOlympiadInInformatics
{
public:
    int find(vector<int> sums, int k)
    {
        int l = 0, r = 0;
        for (int i = 0; i < sums.size(); i++)
            r = max(r, sums[i]);
        while (l < r - 1)
        {
            int mid = (l + r) >> 1;
            if (get(mid, sums) >= k)
                l = mid;
            else
                r = mid;
        }
        if (get(l, sums) <= k)
            return l;
        return r;
    }
};
