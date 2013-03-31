#include <string>
#include <iostream>

#define MAX 1050000

using namespace std;

class EllysCheckers
{
public:
    string getWinner(string a)
    {
        int N = 0;
        for (int i = 0; i < a.size(); i++)
            N = N * 2 + (a[i] == 'o');
        bool F[MAX];
        F[0] = false;
        for (int i = 1; i < MAX; i++)
        {
            F[i] = false;
            if (i % 2)
                F[i] = F[i - 1];
            else
            {
                for (int j = 1; j < 22; j++)
                {
                    if ((i & (1 << j)) && (!(i & (1 << (j - 1)))))
                        if (!F[(i ^ (1 << j)) ^ (1 << (j - 1))])
                            F[i] = true;
                    if (j > 2)
                        if ((i & (1 << j)) && (i & (1 << (j - 1))) && (i & (1 << (j - 2))) && (!(i & (1 << (j - 3)))))
                            if (!F[(i ^ (1 << j)) ^ (1 << (j - 3))])
                                F[i] = true;
                }
            }
        }
        if (F[N])
            return "YES";
        else
            return "NO";
    }
};
