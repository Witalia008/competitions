#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define For(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100

using namespace std;

/*struct tmas{
    int num[nmax+1];
    int len;
};

int longlen(tmas a)
{
    int i=1;
    while ((a.num[i]==0)&&(i<nmax)) i++;
    return nmax-i+1;
}

tmas dob(tmas a,tmas b)
{
    int s,p;
    tmas res;
    memset(res.num,0,sizeof(res.num));
    p=0;
    for (int i=nmax;i>=nmax-b.len-1;i--)
        for(int j=nmax;j>=nmax-a.len-1;j--)
        {
            s=a.num[j]*b.num[i]+p+res.num[i+j-nmax];
            res.num[i+j-nmax]=s%10;
            p=s/10;
        }
    res.len=longlen(res);
    return res;
}

tmas minus(tmas a,tmas b)
{
    int z=0;
    tmas res;
    for(int i=nmax;i>=1;i--)
    {
        res.num[i]=a.num[i]-b.num[i]-z;
        if (res.num[i]<0)
        {
            res.num[i]+=10;
            z=1;
        } else z=0;
    }
    res.len=longlen(res);
    return res;
}

int comp(tmas a,tmas b)
{
    int i=1;
    while ((a.num[i]==b.num[i])&&(i<nmax)) i++;
    if (a.num[i]==b.num[i]) return 0;
    if (a.num[i]>b.num[i]) return 1;
    return -1;
}

void div_mod(tmas a,tmas b,tmas &ost,tmas &res)
{
    memset(res.num,0,sizeof(res.num));
    memset(ost.num,0,sizeof(ost.num));
    For(i,nmax-a.len-1,nmax)
    {
        For(j,1,nmax-1)
            ost.num[j]=ost.num[j+1];
        ost.num[nmax]=a.num[i];
        int n=0;
        while (comp(ost,b)>=0)
        {
            ost=minus(ost,b);
            n++;
        }
        res.num[i]=n;
    }
    res.len=longlen(res);
    ost.len=longlen(ost);
}

bool comp_0(tmas a)
{
    For(i,1,nmax)
        if (a.num[i]!=0) return false;
    return true;
}*/

int gcd(int a, int b)
{
    while ((a != 0) && (b != 0))
        if (a > b)
            a = a % b;
        else
            b = b % a;
    if (a == 0)
        return b;
    else
        return a;
}

long long a[12];

int main()
{
    int n;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    For(i, 1, n)
    {
        scanf("%lld", &a[i]);
        if ((i > 1) && (i < n) && (a[i] % 2 == 0))
            a[i] = a[i] / 2;
    }
    long long ans;
    ans = a[1];
    For(i, 2, n)
        ans = (ans * a[i]) / (gcd(ans, a[i]));
    printf("%lld\n", ans / a[1]);
    system("PAUSE");
    return 0;
}
