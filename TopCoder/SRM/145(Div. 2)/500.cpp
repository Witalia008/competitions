#include <stdio.h>
#include <cstdlib>
#include <string>

using namespace std;

class ExerciseMachine
{
public:
    int getPercentages(string time)
    {
        int h, m, s;
        sscanf(time.c_str(), "%d:%d:%d", &h, &m, &s);
        int tot = h * 60 * 60 + m * 60 + s;
        int ans = 0;
        for (int i = 1; i < tot; ++i)
            if ((i * 100) % tot == 0)
                ans++;
        return ans;
    }
};
