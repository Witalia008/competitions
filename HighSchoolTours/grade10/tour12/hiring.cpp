#include <algorithm>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

#define MAX_N 500000

class candidate
{
public:
    double s, q, r;
    int i;

    bool operator<(const candidate &c) const
    {
        return r < c.r;
    }
};

struct T
{
    int i;
    double q;
};

candidate c[MAX_N];
bool usedCandidate[MAX_N + 1];
int heapQuals[MAX_N];
T heap[MAX_N];
int n, top;
long long w;

int best = 0;
int bestIndex = 0;
double bestCost = 0;

int main()
{
    freopen("hiring.dat", "r", stdin);
    freopen("hiring.res", "w", stdout);
    scanf("%d %lld", &n, &w);

    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &c[i].s, &c[i].q);
        c[i].r = c[i].s / c[i].q;
        c[i].i = i + 1;
    }

    sort(c, c + n);

    double totalQual = 0;
    top = -1;
    for (int i = 0; i < n; i++)
    {
        top++;
        int x = top;
        heapQuals[top] = c[i].q;
        while (x > 0 && heapQuals[x] > heapQuals[x / 2])
        {
            swap(heapQuals[x], heapQuals[x / 2]);
            x /= 2;
        }
        totalQual += c[i].q;
        double maxQual = w / c[i].r;
        while (totalQual > maxQual)
        {
            totalQual -= heapQuals[0];
            swap(heapQuals[0], heapQuals[top]);
            top--;
            x = 0;
            while (x * 2 <= top)
            {
                int k = x;
                if (heapQuals[x * 2] > heapQuals[k])
                    k = x * 2;
                if (x * 2 + 1 <= top && heapQuals[x * 2 + 1] > heapQuals[k])
                    k = x * 2 + 1;
                if (k == x)
                    x = top + 1;
                else
                {
                    swap(heapQuals[x], heapQuals[k]);
                    x = k;
                }
            }
        }

        double cost = totalQual * c[i].r;
        if (top + 1 > best || (top + 1 == best && cost < bestCost))
        {
            best = top + 1;
            bestCost = cost;
            bestIndex = i;
        }
    }

    memset(usedCandidate, 0, sizeof(usedCandidate));
    totalQual = 0;
    top = -1;
    for (int i = 0; i <= bestIndex; i++)
    {
        top++;
        int x = top;
        heap[top].q = c[i].q;
        heap[top].i = c[i].i;
        while (x > 0 && heap[x].q > heap[x / 2].q)
        {
            swap(heap[x], heap[x / 2]);
            x /= 2;
        }
        totalQual += c[i].q;
        usedCandidate[c[i].i] = true;
    }

    // Remove over-qualified candidates
    double maxQual = w / c[bestIndex].r;
    while (totalQual > maxQual)
    {
        totalQual -= heap[0].q;
        usedCandidate[heap[0].i] = false;
        swap(heap[0], heap[top]);
        top--;
        int x = 0;
        while (x * 2 <= top)
        {
            int k = x;
            if (heap[x * 2].q > heap[k].q)
                k = x * 2;
            if (x * 2 + 1 <= top && heap[x * 2 + 1].q > heap[k].q)
                k = x * 2 + 1;
            if (k == x)
                x = top + 1;
            else
            {
                swap(heap[x], heap[k]);
                x = k;
            }
        }
    }

    // Output the list of candidates used
    printf("%d\n", best);
    for (int i = 1; i <= n; i++)
        if (usedCandidate[i])
            printf("%d\n", i);

    return 0;
}
