#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>

//#include "list.h"

using namespace std;

typedef long long ll;

#define N 100005
#define Abs(a) (a < 0 ? (-(a)) : (a))
#define BITS 45

int n, en;
ll A[N], S[N];
int bor[N * 50][2];
ll res;

void add(ll a)
{
    int v = 0;
    for (int i = BITS; i >= 0; i--)
    {
        int d = (a >> i) & 1;
        if (bor[v][d] == -1)
            bor[v][d] = ++en;
        v = bor[v][d];
    }
}

ll get(ll a)
{
    int v = 0;
    ll res = 0;
    for (int i = BITS; i >= 0; i--)
    {
        int d = (a >> i) & 1;
        if (bor[v][1 - d] != -1)
        {
            res += 1LL << i;
            v = bor[v][1 - d];
        }
        else
            v = bor[v][d];
    }
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    memset(bor, -1, sizeof(bor));
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        S[i] = A[i];
        if (i)
            S[i] ^= S[i - 1];
        res = max(res, S[i]);
    }

    add(0);
    ll cur = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        cur ^= A[i];
        res = max(res, cur);
        res = max(res, get(S[i]));
        add(cur);
    }
    cout << res << endl;
    return 0;
}
