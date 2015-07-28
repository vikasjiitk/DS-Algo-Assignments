#include<stdio.h>
#define mod 1000000007
void mult_even(long long int a[2][2])
{
    long long int b[2][2]={0,0,0,0};
    int i,j,k;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            for(k=0;k<2;k++)
            b[i][j]+=(a[i][k]%mod * a[k][j]%mod)%mod;

    a[0][0]=b[0][0]%mod;
    a[1][0]=b[1][0]%mod;
    a[0][1]=b[0][1]%mod;
    a[1][1]=b[1][1]%mod;

    return;
}
void mult_odd(long long int arr[2][2])
{
    mult_even(arr);
    long long int t1=arr[0][0];
    long long int t2=arr[1][0];
    arr[0][0]=(t1+arr[0][1])%mod;
    arr[1][0]=(t2+arr[1][1])%mod;
    arr[0][1]=t1;
    arr[1][1]=t2;

    return;
}
void find(long long int arr[2][2],long long int n)
{
    if(n>0)
    {
        find(arr,n/2);
        if(n%2==0)
        {
            mult_even(arr);
            return;
        }
        else if(n!=1)
        {
            mult_odd(arr);
            return;
        }
    }
    return;
}
long long int fibo(long long int n)
{
    long long int arr[2][2];
    arr[0][0]=1,arr[0][1]=1,arr[1][0]=1,arr[1][1]=0;
    find(arr,n-1);

    return arr[0][0];
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test>0)
    {
        long long int n;
        scanf("%lld",&n);
        if(n==0)printf("0\n");
        else{
        long long int ans=fibo(n);
        printf("%lld\n",ans);}
        test--;
    }
    return 0;
}
