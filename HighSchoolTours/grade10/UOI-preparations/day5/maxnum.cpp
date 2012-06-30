#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

#define nmax 300
#define INF 10e+300
#define max 0
#define min 1
#define EPS 10e-9

string s;
int cyfr[nmax], open[nmax], close[nmax];
char sign[nmax];
double F[2][nmax][nmax];
int N;

double abss(double a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

void GetBracket(int l, int r, int p)
{
    if (l == r)
        return;
    if (l == 1 && r == N)
        ;
    else
    {
        open[l]++;
        close[r]++;
    }
    bool fl = false;
    for (int k = l; k < r && !fl; k++)
        switch (sign[k])
        {
        case '+':
            if (F[p][l][r] == F[p][l][k] + F[p][k + 1][r])
            {
                fl = true;
                GetBracket(l, k, p);
                GetBracket(k + 1, r, p);
            }
            break;
        case '-':
            if (F[p][l][r] == (F[p][l][k] - F[1 - p][k + 1][r]))
            {
                fl = true;
                GetBracket(l, k, p);
                GetBracket(k + 1, r, 1 - p);
            }
            break;
        case '*':
            if (F[p][l][r] == F[p][l][k] * F[p][k + 1][r])
            {
                fl = true;
                GetBracket(l, k, p);
                GetBracket(k + 1, r, p);
                break;
            }
            if (F[p][l][r] == F[p][l][k] * F[1 - p][k + 1][r])
            {
                fl = true;
                GetBracket(l, k, p);
                GetBracket(k + 1, r, 1 - p);
                break;
            }
            if (F[p][l][r] == F[1 - p][l][k] * F[p][k + 1][r])
            {
                fl = true;
                GetBracket(l, k, 1 - p);
                GetBracket(k + 1, r, p);
                break;
            }
            if (F[p][l][r] == F[1 - p][l][k] * F[1 - p][k + 1][r])
            {
                fl = true;
                GetBracket(l, k, 1 - p);
                GetBracket(k + 1, r, 1 - p);
                break;
            }
        }
}

int main()
{
    //ifstream cin ("input.txt"); ofstream cout ("output.txt");
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> s;
    N = s.length() / 2 + 1;
    for (int i = 1; i <= N; i++)
    {
        cyfr[i] = s[i * 2 - 2] - '0';
        if (i != N)
            sign[i] = s[i * 2 - 1];
    }

    for (int i = 1; i <= N; i++)
    {
        F[max][i][i] = cyfr[i];
        F[min][i][i] = cyfr[i];
    }

    for (int p = 2; p <= N; p++)
        for (int i = 1; i <= N - p + 1; i++)
        {
            int j = i + p - 1;
            F[max][i][j] = -INF;
            F[min][i][j] = INF;
            for (int k = i; k < j; k++)
                switch (sign[k])
                {
                case '+':
                    if (F[max][i][k] + F[max][k + 1][j] > F[max][i][j])
                        F[max][i][j] = F[max][i][k] + F[max][k + 1][j];

                    if (F[min][i][k] + F[min][k + 1][j] < F[min][i][j])
                        F[min][i][j] = F[min][i][k] + F[min][k + 1][j];
                    break;
                case '-':
                    if (F[max][i][k] - F[min][k + 1][j] > F[max][i][j])
                        F[max][i][j] = F[max][i][k] - F[min][k + 1][j];

                    if (F[min][i][k] - F[max][k + 1][j] < F[min][i][j])
                        F[min][i][j] = F[min][i][k] - F[max][k + 1][j];
                    break;
                case '*':
                    if (F[max][i][k] * F[max][k + 1][j] > F[max][i][j])
                        F[max][i][j] = F[max][i][k] * F[max][k + 1][j];
                    if (F[max][i][k] * F[min][k + 1][j] > F[max][i][j])
                        F[max][i][j] = F[max][i][k] * F[min][k + 1][j];
                    if (F[min][i][k] * F[max][k + 1][j] > F[max][i][j])
                        F[max][i][j] = F[min][i][k] * F[max][k + 1][j];
                    if (F[min][i][k] * F[min][k + 1][j] > F[max][i][j])
                        F[max][i][j] = F[min][i][k] * F[min][k + 1][j];

                    if (F[max][i][k] * F[max][k + 1][j] < F[min][i][j])
                        F[min][i][j] = F[max][i][k] * F[max][k + 1][j];
                    if (F[max][i][k] * F[min][k + 1][j] < F[min][i][j])
                        F[min][i][j] = F[max][i][k] * F[min][k + 1][j];
                    if (F[min][i][k] * F[max][k + 1][j] < F[min][i][j])
                        F[min][i][j] = F[min][i][k] * F[max][k + 1][j];
                    if (F[min][i][k] * F[min][k + 1][j] < F[min][i][j])
                        F[min][i][j] = F[min][i][k] * F[min][k + 1][j];
                    break;
                }
        }

    GetBracket(1, N, max);

    //cout << setiosflags(ios::fixed) << setprecision(15) << F[max][1][N] << endl;
    printf("%1.11lle\n", F[max][1][N]);
    for (int i = 1; i <= N; i++)
    {
        for (int k = 1; k <= open[i]; k++)
            cout << "(";
        cout << cyfr[i];
        for (int k = 1; k <= close[i]; k++)
            cout << ")";
        if (i != N)
            cout << sign[i];
    }
    cout << endl;
    return 0;
}
