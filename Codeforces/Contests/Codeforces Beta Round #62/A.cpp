#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <memory.h>
#include <math.h>
#include <set>

using namespace std;

#define cons 31.4159265352718281828459045
#define nmax 100

int a, b;
int p[5];

int main()
{
    //ifstream cin ("input.txt");
    //ofstream cout ("output.txt");
    cin >> p[1] >> p[2] >> p[3] >> p[4];
    cin >> a >> b;
    int ans = 0;
    for (int i = a; i <= b; i++)
    {
        int x = 0;
        for (int p1 = 1; p1 <= 4; p1++)
            for (int p2 = 1; p2 <= 4; p2++)
                for (int p3 = 1; p3 <= 4; p3++)
                    for (int p4 = 1; p4 != 4; p4++)
                        if (p1 != p2 && p1 != p3 && p1 != p4 && p2 != p3 && p2 != p4 && p3 != p4)
                            if (((((i % p[p1]) % p[p2]) % p[p3]) % p[p4]) == i)
                                x++;
        if (((double)x / 24) * 100 >= cons)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
