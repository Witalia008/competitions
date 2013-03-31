#include <stdio.h>
#include <set>

using namespace std;

#define MP make_pair
#define NMAX 1001

typedef pair<int, int> PII;
typedef multiset<PII> msp;

int N, M, x, y;
int Cnt[NMAX];
msp A, B;

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    scanf("%d%d", &N, &M);
    A.clear();
    B.clear();
    for (int i = 0; i < N; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        A.insert(MP(a, b));
        Cnt[b]++;
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        B.insert(MP(a, b));
        if (Cnt[b])
        {
            x++;
            Cnt[b]--;
        }
    }
    for (msp::iterator it = A.begin(); it != A.end(); it++)
        if (B.find(*it) != B.end())
        {
            B.erase(B.find(*it));
            y++;
        }

    printf("%d %d\n", x, y);
    return 0;
}
