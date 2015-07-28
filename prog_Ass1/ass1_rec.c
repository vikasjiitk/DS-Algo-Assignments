#include<stdio.h>
#define mod 1000000007

long long int fib(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    else return (fib(n-1)%mod+ fib(n-2)%mod)%mod;
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test>0)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",fib(n));
        test--;
    }
    return 0;
}
