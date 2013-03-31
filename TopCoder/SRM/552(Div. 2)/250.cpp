#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class FoxAndFlowerShopDivTwo
{
public:
    int theMaxFlowers(vector<string> A, int X, int Y)
    {
        int ans = 0;
        int s1, s2, s3, s4;
        s1 = s2 = s3 = s4 = 0;
        for (int i = 0; i < X; i++)
            for (int j = 0; j < A[i].length(); j++)
                s1 += A[i][j] == 'F';
        for (int i = X + 1; i < A.size(); i++)
            for (int j = 0; j < A[i].length(); j++)
                s2 += A[i][j] == 'F';
        for (int j = 0; j < Y; j++)
            for (int i = 0; i < A.size(); i++)
                s3 += A[i][j] == 'F';
        for (int i = 0; i < A.size(); i++)
            for (int j = Y + 1; j < A[i].length(); j++)
                s4 += A[i][j] == 'F';
        if (s1 > ans)
            ans = s1;
        if (s2 > ans)
            ans = s2;
        if (s3 > ans)
            ans = s3;
        if (s4 > ans)
            ans = s4;
        return ans;
    }
};
