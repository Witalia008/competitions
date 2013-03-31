#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

int A[1010];
int N;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    int Max = 0;
    for (int i = 1; i <= N; ++i)
    {
        int k = 1;
        int j = i;
        while (j > 1 && A[j - 1] <= A[j])
            j--, k++;
        j = i;
        while (j < N && A[j + 1] <= A[j])
            j++, k++;
        if (k > Max)
            Max = k;
    }
    cout << Max << endl;
    return 0;
}
