#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#define eps 10e-5
#define abs(a) (((a) < 0) ? (-a) : (a))
#define sqr(a) ((a) * (a))
#define nmax 160
#define MP make_pair

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

int StrToInt(string a)
{
    int res = 0;
    for (int i = 0; i < a.length(); i++)
        if (a[i] >= '0' && a[i] <= '9')
            res = res * 10 + a[i] - '0';
    return res;
}

int Left[nmax], Right[nmax];

int main()
{
    //ifstream cin ("input.txt"); ofstream cout ("output.txt");
    //freopen ("input.txt", "r", stdin); freopen ("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        Left[i] = m, Right[i] = -1;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == 'W')
            {
                if (j > Right[i])
                    Right[i] = j;
                if (j < Left[i])
                    Left[i] = j;
            }
        }
    }
    int N = n;
    while (N > 0 && Left[N - 1] == m)
        N--;
    if (N > 0)
        Left[N] = Left[N - 1], Right[N] = Right[N - 1];
    int ans = 0;
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            while (j < max(Right[i], Right[i + 1]))
                j++, ans++;
        }
        else
        {
            while (j > min(Left[i], Left[i + 1]))
                j--, ans++;
        }
        ans++;
    }
    printf("%d\n", (ans == 0) ? 0 : (ans - 1));
    return 0;
}
