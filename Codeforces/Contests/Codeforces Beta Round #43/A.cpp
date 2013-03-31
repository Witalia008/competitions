#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <cstring>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define nmax 200

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	printf("2");
	int nom=2;
	int step=2;
	For(i,3,n)
	{
		nom+=step;
		step++;
		if (nom>n) 
		{
			while (nom>n) nom-=n;
		}
		printf(" %d",nom);
	}
	printf("\n");
	return 0;
}
