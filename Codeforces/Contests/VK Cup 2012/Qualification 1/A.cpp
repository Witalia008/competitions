#include <stdio.h>
#include <cstdlib>

using namespace std;

int n, k;
int a[60];

int main ()
{
	scanf ("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	int cou = k;
	while (cou < n && a[cou] == a[cou - 1]) cou++;
	while (cou > 0 && a[cou - 1] == 0) cou--;
	printf ("%d\n", cou);
	return 0;
}
