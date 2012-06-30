#include <stdio.h>
#include <cstdlib>
#include <fstream>

using namespace std;

#define nmax 250
#define INF 1000000000

struct Treag
{
    int time, good;
    bool can;
    int s[nmax + 1], f[nmax + 1];
};

struct Tstat
{
    int time, what;
};

int N, M, K, F;
Tstat stat[nmax + 1];
Treag reac[nmax * 2 + 1];

int main()
{
    ifstream cin("alchemy.dat");
    ofstream cout("alchemy.sol");
    cin >> N >> M >> K >> F;
    for (int i = 1; i <= K; i++)
        stat[i].what = 2;
    for (int i = 1; i <= M; i++)
    {
        cin >> reac[i].time;
        reac[i].can = true;
        reac[i].good = 1;
        cin >> reac[i].s[0];
        for (int j = 1; j <= reac[i].s[0]; j++)
            cin >> reac[i].s[j];
        cin >> reac[i].f[0];
        for (int j = 1; j <= reac[i].f[0]; j++)
            cin >> reac[i].f[j];
    }
    int TIME = 0;
    for (int t = 1; t <= N - K + 1; t++)
    {
        for (int i = 1; i <= M; i++)
        {
            if (reac[i].can)
            {
                int j = reac[i].good;
                while (stat[reac[i].s[j]].what == 2 && j <= reac[i].s[0])
                    j++;
                if (j > reac[i].s[0])
                {
                    reac[i].can = false;
                    for (j = 1; j <= reac[i].f[0]; j++)
                    {
                        if (stat[reac[i].f[j]].what == 0)
                        {
                            stat[reac[i].f[j]].what = 1;
                            stat[reac[i].f[j]].time = TIME + reac[i].time;
                        }
                        else
                        {
                            if (stat[reac[i].f[j]].what == 1)
                                if (stat[reac[i].f[j]].time > TIME + reac[i].time)
                                    stat[reac[i].f[j]].time = TIME + reac[i].time;
                        }
                    }
                }
                else
                    reac[i].good = j;
            }
        }
        int x = 0;
        for (int i = 1; i <= N; i++)
            if (stat[i].what == 1)
                if (x == 0 || stat[i].time < stat[x].time)
                    x = i;
        stat[x].what = 2;
        TIME = stat[x].time;
    }
    if (stat[F].what == 0)
        cout << "-1" << endl;
    else
        cout << stat[F].time << endl;
    return 0;
}
