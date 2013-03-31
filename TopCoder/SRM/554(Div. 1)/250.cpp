#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

class TheBrickTowerEasyDivOne
{
public:
    int find(int redCount, int redHeight, int blueCount, int blueHeight)
    {
        if (redCount > blueCount)
        {
            swap(redCount, blueCount);
            swap(redHeight, blueHeight);
        }
        int ans = 0;
        //try put first red
        ans += 2;
        ans += min(redCount - 1, blueCount - 1) * 2;
        //try put first blue
        if (redHeight != blueHeight)
        {
            ans++;
            ans += min(blueCount - 1, redCount);
        }
        return ans;
    }
};
