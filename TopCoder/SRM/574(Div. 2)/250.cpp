#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class CityMap
{
public:
    string getLegend(vector<string> cityMap, vector<int> POIs)
    {
        int a[30] = {};
        for (int i = 0; i < cityMap.size(); i++)
            for (int j = 0; j < cityMap[i].size(); j++)
                if (cityMap[i][j] != '.')
                    a[cityMap[i][j] - 'A']++;
        string res = "";
        for (int i = 0; i < POIs.size(); i++)
            for (int j = 0; j < 26; j++)
                if (a[j] == POIs[i])
                    res += j + 'A';
        return res;
    }
};
