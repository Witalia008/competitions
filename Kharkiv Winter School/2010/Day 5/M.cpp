#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#define nmax 500

using namespace std;

typedef pair<int, int> P;

int M, N, D;
int L[nmax + 1];
int max_cou[nmax + 1][nmax + 1], F[nmax + 1][nmax / 2];
priority_queue<int> Q;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &M, &D, &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &L[i]);
    for (int i = N; i >= 1; i--)
    {
        int sum = 0;
        while (!Q.empty())
            Q.pop();
        for (int j = i; j <= N; j++)
        {
            int temp;
            if (!Q.empty())
                temp = Q.top();
            max_cou[i][j] = max_cou[i][j - 1];
            if (sum + L[j] <= D)
            {
                sum += L[j];
                Q.push(L[j]);
                max_cou[i][j]++;
            }
            else if (!Q.empty() && temp > L[j])
            {
                Q.pop();
                sum -= temp;
                sum += L[j];
                Q.push(L[j]);
            }
        }
    }
    for (int i = 1; i <= N; i++)
        F[i][1] = max_cou[1][i];
    for (int i = 1; i <= N; i++)     // what is the last song
        for (int j = 2; j <= M; j++) // how many disks did we use
        {
            F[i][j] = max_cou[1][i];
            for (int k = 1; k < i; k++)
                if (F[k][j - 1] + max_cou[k + 1][i] > F[i][j])
                    F[i][j] = F[k][j - 1] + max_cou[k + 1][i];
        }
    cout << F[N][M] << endl;
    return 0;
}
