#include <stdio.h>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int abs(int a) { return a < 0 ? -a : a; }

class TypingDistance
{
public:
    int minDistance(string keyboard, string word)
    {
        int res = 0;
        int prev = 0;
        for (int i = 0; i < word.length(); ++i)
        {
            int cur = 0;
            for (int j = 0; j < keyboard.length(); ++j)
                if (keyboard[j] == word[i])
                    cur = j;
            if (i)
                res += abs(cur - prev);
            prev = cur;
        }
        return res;
    }
};
