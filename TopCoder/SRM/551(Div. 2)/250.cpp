#include <stdio.h>
#include <string>

using namespace std;

class ColorfulBricks
{
public:
    int countLayouts(string s)
    {
        bool A[30];
        for (int i = 0; i < 30; i++)
            A[i] = 0;
        for (int i = 0; i < s.length(); i++)
            A[s[i] - 'A'] = true;
        int ans = 0;
        for (int i = 'A'; i <= 'Z'; i++)
            ans += A[i - 'A'];
        if (ans <= 2)
            return ans;
        return 0;
    }
};
