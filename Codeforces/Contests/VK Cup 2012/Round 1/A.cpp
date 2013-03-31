#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const char *infile = "input.txt";
const char *outfile = "output.txt";

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define max(a, b) ((a) > (b)) ? (a) : (b)
#define CLR(a, x) memset(a, x, sizeof(a))
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define MP make_pair
#define Inf 1000000000

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPI;

int N, M, x, y;
VPI A, B, ans;

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d%d%d%d", &N, &M, &x, &y);
    A.resize(N);
    B.resize(M);
    REP(i, N)
    scanf("%d", &A[i]), A[i].second = i;
    REP(i, M)
    scanf("%d", &B[i].first), B[i].second = i;
    sort(all(A));
    sort(all(B));
    int it = 0;
    REP(i, N)
    {
        while (it < M && B[it].first < A[i].first - x)
            it++;
        if (it >= M)
            break;
        if (B[it].first <= A[i].first + y)
        {
            ans.pb(MP(A[i].second, B[it].second));
            it++;
        }
    }
    printf("%d\n", ans.size());
    REP(i, ans.size())
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    return 0;
}
