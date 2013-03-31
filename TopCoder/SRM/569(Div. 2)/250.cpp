#include <stdio.h>
#include <cstdlib>
#include <vector>

using namespace std;

class TheJediTestDiv2
{
public:
    int countSupervisors(vector<int> students, int Y, int J)
    {
        int n = students.size();
        int ans = 1000000000;
        for (int pos = 0; pos < n; ++pos)
        {
            int cnt = 0;
            for (int i = 0; i < n; ++i)
            {
                int cur = students[i];
                if (i == pos)
                    cur -= Y;
                if (cur < 0)
                    cur = 0;
                cnt += cur / J + (cur % J != 0);
            }
            if (cnt < ans)
                ans = cnt;
        }
        return ans;
    }
};
