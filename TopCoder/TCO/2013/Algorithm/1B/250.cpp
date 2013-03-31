#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class EllysPairs
{
public:
    int getDifference(vector<int> knowl)
    {
        sort(knowl.begin(), knowl.end());
        int m1 = 0, m2 = 100000;
        for (int i = 0; i < knowl.size() / 2; i++)
        {
            m1 = max(m1, knowl[knowl.size() - i - 1] + knowl[i]);
            m2 = min(m2, knowl[knowl.size() - i - 1] + knowl[i]);
        }
        return m1 - m2;
    }
};
