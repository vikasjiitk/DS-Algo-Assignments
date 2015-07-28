#include<stdio.h>
#define mod 1000000007
int main()
{
    int test;
    scanf("%d",&test);
    while(test>0)
    {
        int n,i;
        long long int a=0,b=1,temp;
        scanf("%d",&n);
        for(i=0;i<n-1;i++)
        {
           temp=a;
            a=b%mod;
            b=(b%mod+temp%mod)%mod;
        }
        if(n==0)
            printf("0\n");
        else
            printf("%lld\n",b);
        test--;
    }

}
