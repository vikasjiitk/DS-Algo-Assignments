#include<bits/stdc++.h>
using namespace std;
int n;
int coun=0;
int arr[100000];
/*void cop(int **b,int **m)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        b[i][j]=m[i][j];
}*/
void queen(int **m,int row)
{
    int **b=new int*[n];
    for(int i=0;i<n;i++)
        b[i]=new int[n];

    for(int i=0;i<n;i++)
    {
        //cop(b,m);
         for(int l=0;l<n;l++)
        for(int p=0;p<n;p++)
        b[l][p]=m[l][p];

        /*for(int l=0;l<n;l++)
        for(int p=0;p<n;p++)
        cout<<b[l][p];*/

        if(b[row][i]==1)
        {
            arr[row]=i;
            for(int j=0;j<n;j++){b[row][j]=0;b[j][i]=0;}
            int r=row,c=i;
            while(r<n&&c<n)b[r++][c++]=0;
            r=row,c=i;
            while(r>=0&&c>=0)b[r--][c--]=0;
            r=row,c=i;
            while(r>=0&&c<n)b[r--][c++]=0;
            r=row,c=i;
            while(c>=0&&r<n)b[r++][c--]=0;

            if(row!=n-1)
            queen(b,row+1);

            if(row==n-1){
            for(int k=0;k<n;k++)cout<<arr[k]+1<<" ";cout<<endl;
            coun++;
            }
        }
    }
    for(int i=0;i<n;i++)
        delete b[i];

}
int main()
{
    cin>>n;
    int **m=new int*[n];
    for(int i=0;i<n;i++)
        m[i]=new int[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) m[i][j]=1;

    queen(m,0);
    //cout<<coun;
}
