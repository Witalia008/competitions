#include <stdio.h>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int what[100];

class TheDeviceDiv2
{
public:
    string identify(vector<string> plates)
    {
        int n = plates.size(), m = plates[0].length();
        for (int i = 0; i < m; ++i)
            what[i] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                for (int k = 0; k < m; ++k)
                {
                    if ((plates[i][k] == '0' && plates[j][k] == '1') || (plates[i][k] == '1' && plates[j][k] == '0'))
                        what[k] |= 1;
                    if (plates[i][k] == '1' && plates[j][k] == '1')
                        what[k] |= 2;
                }
        for (int i = 0; i < m; ++i)
            if (what[i] != 3)
                return "NO";
        return "YES";
    }
};
