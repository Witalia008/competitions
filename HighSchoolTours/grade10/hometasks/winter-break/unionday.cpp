#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <math.h>
#include <time.h>
#define sqr(a) ((a) * (a))
#define nmax 5000
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

struct tpoint
{
    int x, y;
};

int n;
tpoint m[nmax + 1];
double a[nmax + 1];
bool used[nmax + 1];

int main()
{
    freopen("unionday.in", "r", stdin);
    freopen("unionday.out", "w", stdout);
    scanf("%d", &n);
    For(i, 1, n)
        scanf("%d%d", &m[i].x, &m[i].y);
    a[1] = 0;
    memset(used, 0, sizeof(used));
    used[1] = true;
    For(i, 2, n)
        a[i] = sqrt((double)(sqr(m[1].x - m[i].x) + sqr(m[1].y - m[i].y)));
    double ans = 0;
    For(i, 1, n - 1)
    {
        int k = -1;
        For(j, 1, n) if ((k == -1 || (a[j] < a[k])) && (!used[j])) k = j;
        ans += a[k];
        used[k] = true;
        For(j, 1, n) if (!used[j] && a[j] > sqrt((double)(sqr(m[j].x - m[k].x) + sqr(m[j].y - m[k].y)))) a[j] = sqrt((double)(sqr(m[j].x - m[k].x) + sqr(m[j].y - m[k].y)));
    }
    printf("%0.5lf\n", ans);
    /*srand(time(NULL));
	For(i,1,5000)
		printf("%d %d\n",rand(),rand());*/
    return 0;
}
