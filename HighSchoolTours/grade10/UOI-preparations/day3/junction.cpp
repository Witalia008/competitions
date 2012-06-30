/* gcc */
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define ALL(a) a.begin(), a.end()

struct node
{
    int x, y, z, w;

    node(int xx, int yy, int zz, int ww)
    {
        x = xx;
        y = yy;
        z = zz;
        w = ww;
    }

    bool operator<(node b) const
    {
        //return (z<b.z) || (z == b.z && (y<b.y || (y==b.y && x<b.x)));
        // check time, when segway get on road
        if (z < b.z)
            return true;
        if (z > b.z)
            return false;
        // check road, on which it came
        if (y < b.y)
            return true;
        if (y > b.y)
            return false;
        // check serial number
        if (x < b.x)
            return true;
        return false;
    }
};

vector<node> A;
int N, M;

int main()
{
    freopen("junction.in", "r", stdin);
    freopen("junction.out", "w", stdout);
    scanf("%d%d", &N, &M);

    if (M == 1)
        M++;

    // read from file
    for (int i = 0; i < N; i++)
    {
        int x, y, z, w;
        scanf("%d%d%d%d", &x, &y, &z, &w);
        y--;

        A.pb(node(x, y, z, w));
    }

    // sort by priority
    sort(ALL(A));

    // we'll have segways on road in queue
    map<int, queue<int>> roads;

    set<int> good, bad;

    long long t = 0;
    int ii = 0;

    while (ii < N || good.size() || bad.size())
    {
        // if we have no segways in queue and the next cames then we change time
        if (!good.size() && !bad.size() && A[ii].z > t)
            t = A[ii].z;

        while (ii < N && A[ii].z <= t)
        {
            node &b = A[ii];
            if (roads[(b.y + 1) % M].empty() && roads[b.y].empty())
                good.insert(ii); // if on this road is no one and on righthand road in no one to, then this segway gets in queue
            else
                bad.insert(ii);

            //this segway arrive on road
            roads[b.y].push(ii);

            //if on lefthand road is segway, then it is bad
            if (!roads[(b.y + M - 1) % M].empty())
            {
                int left = roads[(b.y + M - 1) % M].front();
                good.erase(left);
                bad.insert(left);
            }

            ii++;
        }

        int x;

        // if there is any one segway, which is good, the it starts passing
        if (good.size())
        {
            x = *good.begin();
            good.erase(x);
        }
        else
        {
            x = *bad.begin();
            bad.erase(x);
        }

        node &b = A[x];
        t += b.w;
        printf("%d %I64d\n", b.x, t);

        //this segway ends passing
        roads[b.y].pop();

        //if we have any segway on this road and on righthand is'nt any segway then it is good
        if (!roads[b.y].empty() && roads[(b.y + 1) % M].empty())
        {
            bad.erase(roads[b.y].front());
            good.insert(roads[b.y].front());
        }

        //if on lefthand is segway and on this road is'nt any one segway then left is good
        if (roads[b.y].empty() && !roads[(b.y + M - 1) % M].empty())
        {
            int left = roads[(b.y + M - 1) % M].front();
            bad.erase(left);
            good.insert(left);
        }
    }

    return 0;
}
