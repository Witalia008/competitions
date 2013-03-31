#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <list>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <queue>
#include <stack>
#include <complex>
#include <limits.h>

#define Cpp11
#ifdef Cpp11
#include <cassert>
#include <chrono>
#include <regex>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <valarray>
using namespace std::chrono;
#endif
using namespace std;

typedef long long ll;

const int N = 1000005;
const int K = 105;
const int Inf = 1000000000;
const ll InfL = 1000000000000000000LL;
const int MOD = 1000000007;

ll Abs(ll a) { return a < 0 ? -a : a; }
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

char* allowed = "chef";
struct Data {
    int count[4];
    ll cnt[4][4];
    Data() {
        memset(count, 0, sizeof(count));
        memset(cnt, 0, sizeof(cnt));
    }
};

inline int find(char q) {
    return strchr(allowed, q) - allowed;
}

char p[N];

//#define ONLINE_JUDGE
int main() {
    ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%s", p);
    int n = strlen(p);
    Data* mas = new Data[n];
    for (int i = 0; i < n; i++) {
        int cur = find(p[i]);
        if (i > 0) {
            memcpy(mas[i].cnt, mas[i - 1].cnt, sizeof(mas[i].cnt));
        }
        for (int j = 0; j < 4; j++) {
            mas[i].count[j] = (i == 0 ? 0 : mas[i - 1].count[j])
                + (cur == j ? 1 : 0);
            if (i > 0) {
                mas[i].cnt[j][cur] += mas[i - 1].count[j];
            }
        }
    }

    int m;
    scanf("%d\n", &m);
    for (int i = 0; i < m; i++) {
        int a, b, l, r;
        char x, y;
        scanf("%c %c%d%d\n", &x, &y, &l, &r);
        a = find(x);
        b = find(y);
        --l; --r;

        ll res = mas[r].cnt[a][b];
        if (l > 0) {
            res -= mas[l - 1].cnt[a][b];
            res -= (ll) (mas[r].count[b] - mas[l - 1].count[b]) * mas[l - 1].count[a];
        }
        printf("%lld\n", res);
    }
    return 0;
}
