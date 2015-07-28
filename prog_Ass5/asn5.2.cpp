#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,i,j,wt,k,total=0,min_j,min_wt=INT_MAX,ct=0;
	scanf("%d %d",&n,&m);
	int **a=new int*[n];
	for(i=0;i<n;i++)
        a[i]=new int[n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=INT_MIN;
	for(k=0;k<m;k++)
	{
		scanf("%d %d %d",&i,&j,&wt);
		a[i][j]=wt;
		a[j][i]=wt;
	}
	while(ct<n-1)
	{
		for(k=0;k<n;k++)
		{
			if(a[0][k]!=INT_MIN)
			if(min_wt>a[0][k])
			{
				min_wt=a[0][k];
				min_j=k;
			}
		}
		ct++;
		total+=min_wt;
		min_wt=INT_MAX;
		for(k=0;k<n;k++)
		{
			if(a[min_j][k]>=0)
			{
				if(a[0][k]>=0)
				{
					if(a[min_j][k]<a[0][k])
					a[0][k]=a[min_j][k];
					a[min_j][k]=INT_MIN;
				}
				else
				{
					a[0][k]=a[min_j][k];
					a[min_j][k]=INT_MIN;
				}
			}
		}
		for(k=0;k<n;k++)
		{
			if(a[k][min_j]>0)
			{
				if(a[k][0]>0)
				a[k][0]=min(a[k][0],a[k][min_j]);
				else
					a[k][0]=a[k][min_j];
			}
		}
		a[0][0]=INT_MIN;
		for(j=0;j<n;j++)
		{
			a[min_j][j]=INT_MIN;
			a[j][min_j]=INT_MIN;
		}
	}
	printf("%d\n",total);
	return 0;
}
