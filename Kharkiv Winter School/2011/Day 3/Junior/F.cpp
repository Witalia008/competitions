#include <stdio.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include <memory.h>

using namespace std;

#define nmax 100000

ifstream cin("input.txt");
ofstream cout("output.txt");

int count(int n1, int n2, int n3)
{
    if (n2 == 3)
        return 1;
    if (n1 == 3)
    {
        if (n2 == n3)
            return 1;
        return 2;
    }
    if (n1 == n2 && n1 == n3)
        return 1;
    if (n1 != n2 && n1 != n3 && n2 != n3)
        return 3;
    return 2;
}

int ans = 0;

void push(int &f, int val)
{
    if (f == -1 || f < val)
        f = val;
    ans = max(ans, f);
}

int N;
string s;
int F[2][4][4][4][4];

int main()
{
    cin >> N;
    cin >> s;
    for (int i = 0; i < N; i++)
        switch (s[i])
        {
        case 'M':
            s[i] = 0;
            break;
        case 'F':
            s[i] = 1;
            break;
        case 'B':
            s[i] = 2;
            break;
        }

    memset(F, -1, sizeof(F));
    F[0][3][3][3][3] = 0;
    for (int i = 0; i < N; i++)
    {
        memset(F[1 - i % 2], -1, sizeof(F[1 - i % 2]));
        for (int i1 = 0; i1 < 4; i1++)
            for (int i2 = 0; i2 < 4; i2++)
                for (int j1 = 0; j1 < 4; j1++)
                    for (int j2 = 0; j2 < 4; j2++)
                    {
                        int tmp = F[i % 2][i1][i2][j1][j2];
                        if (tmp != -1)
                        {
                            push(F[(i + 1) % 2][i2][s[i]][j1][j2], tmp + count(i1, i2, s[i]));
                            push(F[(i + 1) % 2][i1][i2][j2][s[i]], tmp + count(j1, j2, s[i]));
                        }
                    }
    }

    cout << ans << endl;
    return 0;
}
