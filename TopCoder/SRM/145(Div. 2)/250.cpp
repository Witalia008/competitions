#include <stdio.h>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class ImageDithering
{
public:
    int count(string dithered, vector<string> screen)
    {
        int ans = 0;
        for (int i = 0; i < screen.size(); ++i)
            for (int j = 0; j < screen[i].length(); ++j)
            {
                bool fl = false;
                for (int k = 0; k < dithered.length(); ++k)
                    if (dithered[k] == screen[i][j])
                        fl = true;
                ans += fl;
            }
        return ans;
    }
};
