#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

#define N 1000

int n;
unsigned long long Ans[N + 1];

void multi(int b)
{
    int p = 0;
    for (int i = N; i >= 0; i--)
    {
        Ans[i] = Ans[i] * b + p;
        p = Ans[i] / 1000000000;
        Ans[i] %= 1000000000;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    Ans[N] = 1;
    for (int i = 2; i <= n; i++)
    {
        int x = i;
        int cur = 1, st = 26;
        while (x > st)
        {
            cur++;
            x -= st;
            st *= 26;
        }
        multi(cur + 1);
    }
    int i = 0;
    while (i < N && Ans[i] == 0)
        i++;
    cout << Ans[i];
    for (int j = i + 1; j <= N; j++)
        printf("%09d", int(Ans[j]));
    cout << endl;
    return 0;
}
