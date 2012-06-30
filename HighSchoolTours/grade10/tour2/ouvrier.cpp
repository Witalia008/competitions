#include <stdio.h>
#include <cstdlib>
#include <memory.h>

using namespace std;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int main()
{
    FILE *fi = fopen("ouvrier.dat", "r");
    FILE *fo = fopen("ouvrier.res", "w");
    int a[30];
    int n;
    fscanf(fi, "%d", &n);
    memset(a, 0, sizeof(a));
    for (int i = n / 2 + 1; i <= n; i++)
    {
        a[i] = 1;
    }
    bool fl;
    fl = true;
    int ans;
    ans = 0;
    int balans;
    while (fl)
    {
        bool fl1;
        fl1 = true;
        balans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (balans < 0)
                fl1 = false;
            if (a[i] == 0)
                balans++;
            else
                balans--;
        }
        if (fl1)
            ans++;
        int j;
        j = n;
        while ((a[j] >= a[j + 1]) && (j > 0))
        {
            j--;
        }
        if (j == 0)
            fl = false;
        else
        {
            int k;
            k = n;
            while (a[k] <= a[j])
            {
                k--;
            }
            swap(a[j], a[k]);
            for (int i = j + 1; i <= (n + j) / 2; i++)
            {
                swap(a[i], a[n - i + j + 1]);
            }
        }
        fprintf(fo, "%d\n", ans);
    }
    //const int mas=(1,2,5,14,42,132,429,1430,4862,16796,58786,208012,742900,2674440);
    fclose(fi);
    fclose(fo);
    return 0;
}
