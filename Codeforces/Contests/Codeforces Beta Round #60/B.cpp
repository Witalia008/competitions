#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <string>
#include <iostream>
#include <math.h>
#include <complex>
#include <vector>

using namespace std;

int aa[1001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    int prev = 0;
    bool fl = true;
    for (int k = 1; k <= n; ++k)
    {
        int a;
        cin >> a;
        vector<int> A;
        A.resize(4);
        int ans = 100000;
        A[0] = a / 1000;
        A[1] = (a / 100) % 10;
        A[2] = (a / 10) % 10;
        A[3] = a % 10;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j <= 9; ++j)
            {
                vector<int> b = A;
                b[i] = j;
                int k = b[0] * 1000 + b[1] * 100 + b[2] * 10 + b[3];
                if (k < ans && k >= 1000 && k <= 2011 && k >= prev)
                    ans = k;
            }
        if (ans != 100000)
            aa[k] = ans;
        else
            fl = false;
        prev = ans;
    }
    if (!fl)
        cout << "No solution\n";
    else
    {
        //cout << n << endl;
        for (int k = 1; k <= n; ++k)
            cout << aa[k] << endl;
    }
    return 0;
}
