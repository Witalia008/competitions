#include <stdio.h>
#include <cstdlib>
#include <vector>

using namespace std;

class TheSimilarNumbers
{
public:
    int find(int lower, int upper)
    {
        int res = 0;
        for (; lower <= upper; lower = lower * 10 + 1)
            res++;
        return res;
    }
};
