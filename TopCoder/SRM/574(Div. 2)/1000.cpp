#include <stdio.h>
#include <cstdlib>
#include <vector>

using namespace std;

int n, ans;
bool used[15];
vector<int> path;

bool intersects(int a, int b, int c, int d)
{
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    if (c < a && d < b && d > a)
        return true;
    if (c > a && c < b && d > b)
        return true;
    return false;
}

bool check(int a, int b)
{
    for (int i = 0; i + 1 < path.size(); i++)
        if (intersects(a, b, path[i], path[i + 1]))
            return true;
    return false;
}

void search(int last, int mask)
{
    if (mask + 1 == (1 << n))
    {
        ans += check(last, path[0]);
        return;
    }
    for (int i = 0; i < n; i++)
        if (!used[i] && check(last, i))
        {
            used[i] = true;
            path.push_back(i);
            search(i, mask | (1 << i));
            used[i] = false;
            path.pop_back();
        }
}

class PolygonTraversal2
{
public:
    int count(int N, vector<int> points)
    {
        n = N;
        ans = 0;
        int mask = 0;
        for (int i = 0; i < points.size(); i++)
        {
            points[i]--;
            used[points[i]] = true;
            mask |= (1 << points[i]);
        }
        path = points;
        search(points.back(), mask);
        return ans;
    }
};
