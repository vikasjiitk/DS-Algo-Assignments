#include<stdio.h>
int min(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}
int main()
{
	int m,n,i,j,k,wt,total=0,min_j,min_wt=10000,count=0;
	scanf("%d %d",&n,&m);
	int **a=new int*[n];
	for(i=0;i<n;i++){
        a[i]=new int[n];
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=-10;
	for(k=0;k<m;k++)
	{
		scanf("%d %d %d",&i,&j,&wt);
		a[i][j]=wt;
		a[j][i]=wt;
	}
	while(count<n-1)
	{	//printf("\n\n\n-----count= %d--total =%d ---\n",count,total);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
		//		printf("%d   ",a[i][j]);
			}
		//	printf("\n");
		}
		for(k=0;k<n;k++)
		{
			if(a[0][k]<0)
				continue;
			if(min_wt>a[0][k])
			{
				min_wt=a[0][k];
				min_j=k;
			}
		}
		count++;
		total=total+min_wt;
		min_wt=1000;
		for(k=0;k<n;k++)
		{
			if(a[min_j][k]>=0)
			{
				if(a[0][k]>=0)
				{
					if(a[min_j][k]<a[0][k])
					a[0][k]=a[min_j][k];
					a[min_j][k]=-10;
				}
				else
				{
					a[0][k]=a[min_j][k];
					a[min_j][k]=-10;
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
		a[0][0]=-10;
		for(j=0;j<n;j++)
		{
			a[min_j][j]=-10;
			a[j][min_j]=-10;
		}

	}
	printf("\n%d",total);
	return 0;
}
