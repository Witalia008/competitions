#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <memory.h>

using namespace std;

ifstream fin("peace.in");
ofstream fout("peace.out");

#define NMAX 43100000
#define MAX 8

int R[MAX], cur[MAX];
int A[MAX][MAX];
int Cnt[NMAX];

void Update(int i, int j, int d)
{
    A[i][j] += d;
    if (i > 0 && j > 1)
        A[i - 1][j - 2] += d;
    if (i > 1 && j > 0)
        A[i - 2][j - 1] += d;
    if (i > 0 && j < MAX - 2)
        A[i - 1][j + 2] += d;
    if (i > 1 && j < MAX - 1)
        A[i - 2][j + 1] += d;
    if (i < MAX - 1 && j > 1)
        A[i + 1][j - 2] += d;
    if (i < MAX - 2 && j > 0)
        A[i + 2][j - 1] += d;
    if (i < MAX - 1 && j < MAX - 2)
        A[i + 1][j + 2] += d;
    if (i < MAX - 2 && j < MAX - 1)
        A[i + 2][j + 1] += d;
}

void Search1(int pos);

void Search2(int pos1, int cou, int last)
{
    if (!cou)
    {
        Search1(pos1 + 1);
        return;
    }
    for (int i = last + 1; i < MAX; i++)
        if (A[pos1][i] == 0)
        {
            Update(pos1, i, 1);
            cur[i]++;
            Search2(pos1, cou - 1, i);
            cur[i]--;
            Update(pos1, i, -1);
        }
}

void Search1(int pos)
{
    if (pos == MAX)
    {
        int Cur = 0;
        for (int i = 0; i < MAX; i++)
            Cur = Cur * 9 + cur[i];
        Cnt[Cur]++;
        return;
    }
    Search2(pos, R[pos], -1);
}

int main()
{
    for (int i = 0; i < MAX; i++)
        fin >> R[i];

    Search1(0);

    for (int i = 0; i < NMAX; i++)
        if (Cnt[i] == 1)
        {
            int C[MAX];
            for (int j = 0; j < MAX; j++)
                C[j] = i % 9, i /= 9;
            for (int j = MAX - 1; j >= 0; j--)
            {
                fout << C[j];
                if (j == 0)
                    fout << endl;
                else
                    fout << " ";
            }
            return 0;
        }
    for (int j = 0; j < MAX; j++)
    {
        fout << -1;
        if (j == MAX - 1)
            fout << endl;
        else
            fout << " ";
    }
    return 0;
}
