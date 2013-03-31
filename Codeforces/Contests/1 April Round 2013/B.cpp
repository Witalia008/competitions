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
//#include <assert.h>

using namespace std;

#define For(i, a, b, d) for (int i = (a); i != (b); i += d)
#define FORD(i, a, b) for (int i = (a); i >= b; i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REPD(i, n) for (int i = (n - 1); i >= 0; i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(a) (a).begin(), (a).end()
#define CLR(a, x) memset(a, x, sizeof(a))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define Abs(a) ((a < 0) ? -(a) : a)
#define sqr(a) ((a) * (a))
#define pb push_back
#define mp make_pair
#define eps 10e-5
#define Inf 1000000000
#define Mi 1000000007
#define N 100015
#define K 32

typedef double ld;
typedef unsigned long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<double, char> pdc;
typedef enum
{
    heavy,
    light
} lbl;

const int mx[4] = {1, -1, 0, 0};
const int my[4] = {0, 0, 1, -1};

inline ll gcd(ll a, ll b) { return (!b ? a : gcd(b, a % b)); }

const ld PI = 2 * acos(0.0);
const ll InfLL = ll(Inf) * ll(Inf);

int rand15() { return rand() % (1 << 15); }
int rand30() { return (rand15() << 15) + rand15(); }
int rand(int L, int R)
{
    if (L > R)
        return R;
    return rand30() % (R - L + 1) + L;
}
ld random(ld L, ld R) { return rand(ceil((L - eps) * 100), floor((R + eps) * 100)) / 100.0; }

//#define DEBUG

const string S[33] = {
    "111111101010101111100101001111111",
    "100000100000000001010110001000001",
    "101110100110110000011010001011101",
    "101110101011001001111101001011101",
    "101110101100011000111100101011101",
    "100000101010101011010000101000001",
    "111111101010101010101010101111111",
    "000000001111101111100111100000000",
    "100010111100100001011110111111001",
    "110111001111111100100001000101100",
    "011100111010000101000111010001010",
    "011110000110001111110101100000011",
    "111111111111111000111001001011000",
    "111000010111010011010011010100100",
    "101010100010110010110101010000010",
    "101100000101010001111101000000000",
    "000010100011001101000111101011010",
    "101001001111101111000101010001110",
    "101101111111000100100001110001000",
    "000010011000100110000011010000010",
    "001101101001101110010010011011000",
    "011101011010001000111101010100110",
    "111010100110011101001101000001110",
    "110001010010101111000101111111000",
    "001000111011100001010110111110000",
    "000000001110010110100010100010110",
    "111111101000101111000110101011010",
    "100000100111010101111100100011011",
    "101110101001010000101000111111000",
    "101110100011010010010111111011010",
    "101110100100011011110110101110000",
    "100000100110011001111100111100000",
    "111111101101000101001101110010001"};

//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main()
{
    std::ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "wb", stdout);
#endif
    int n, m;
    cin >> n >> m;
    cout << S[n][m] << endl;
    return 0;
}
