#include<bits/stdc++.h>
using namespace std;
int n;
int coun=0;
int **m;
int *arr;
void unmark(int r,int c)
{
    for(int j=0;j<n;j++){if(m[r][j]==r)m[r][j]=-1; if(m[j][c]==r)m[j][c]=-1;}
    int row=r,col=c;
    while(row<n&&col<n){if(m[row][col]==r)m[row][col]=-1; row++;col++;}
    row=r,col=c;
    while(row>=0&&col>=0){if(m[row][col]==r)m[row][col]=-1; row--;col--;}
    row=r,col=c;
    while(row>=0&&col<n){if(m[row][col]==r)m[row][col]=-1; row--;col++;}
    row=r,col=c;
    while(col>=0&&row<n){if(m[row][col]==r)m[row][col]=-1; row++;col--;}
}
void queen(int row)
{
    for(int i=0;i<n;i++)
    {
        if(m[row][i]==-1)
        {
            arr[row]=i;
            for(int j=0;j<n;j++){
                if(m[row][j]==-1)m[row][j]=row;
                if(m[j][i]==-1)m[j][i]=row;
            }

            int r=row,c=i;
            while(r<n&&c<n){if(m[r][c]==-1)m[r][c]=row; r++;c++;}

            r=row,c=i;
            while(r>=0&&c>=0){if(m[r][c]==-1)m[r][c]=row; r--;c--;}

            r=row,c=i;
            while(r>=0&&c<n){if(m[r][c]==-1)m[r][c]=row; r--;c++;}

            r=row,c=i;
            while(c>=0&&r<n){if(m[r][c]==-1)m[r][c]=row; r++;c--;}

            if(row!=n-1)
            queen(row+1);

            if(row==n-1){
            for(int k=0;k<n;k++)cout<<arr[k]+1<<" ";cout<<endl; //coun++;
            }
            unmark(row,i);
        }
    }
}
int main()
{
    cin>>n;
    arr=new int[n];
    m=new int*[n];
    for(int i=0;i<n;i++)
        m[i]=new int[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) m[i][j]=-1;

    queen(0);
    //cout<<coun;
}
