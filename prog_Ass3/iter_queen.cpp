#include<bits/stdc++.h>
using namespace std;
struct queen{
int r;
int c;
int flag;     // 1 for safe position, -1 for unsafe position, 0 for uncertain position
};
void unmark(int m[50][50],int r,int c,int n)
{
    for(int j=1;j<=n;j++){if(m[r][j]==r)m[r][j]=0; if(m[j][c]==r)m[j][c]=0;}
    int row=r,col=c;
    while(row<=n&&col<=n){if(m[row][col]==r)m[row][col]=0; row++;col++;}
    row=r,col=c;
    while(row>=1&&col>=1){if(m[row][col]==r)m[row][col]=0; row--;col--;}
    row=r,col=c;
    while(row>=1&&col<=n){if(m[row][col]==r)m[row][col]=0; row--;col++;}
    row=r,col=c;
    while(col>=1&&row<=n){if(m[row][col]==r)m[row][col]=0; row++;col--;}
}
int main()
{
    stack<queen> myqueen;
    int n;
    cin>>n;
    int m[50][50];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)m[i][j]=0;
    queen t;
    t.r=1; t.c=1; t.flag=1;
    myqueen.push(t);

    for(int i=1;i<=n;i++){m[1][i]=1;m[i][1]=1;m[i][i]=1;}

    queen get;
    int f=1;
    while(!myqueen.empty())
    {
        get=myqueen.top();
        int flag=get.flag;
        int r=get.r;
        int c=get.c;
        switch(flag){
            case 0 :    myqueen.pop();
                        if(!m[r][c]){
                        get.flag=1;
                        myqueen.push(get);
                        for(int j=1;j<=n;j++){if(!m[r][j])m[r][j]=r; if(!m[j][c])m[j][c]=r;}
                        int row=r,col=c;
                        while(row<=n&&col<=n){if(!m[row][col])m[row][col]=r; row++;col++;}
                        row=r,col=c;
                        while(row>=1&&col>=1){if(!m[row][col])m[row][col]=r; row--;col--;}
                        row=r,col=c;
                        while(row>=1&&col<=n){if(!m[row][col])m[row][col]=r; row--;col++;}
                        row=r,col=c;
                        while(col>=1&&row<=n){if(!m[row][col])m[row][col]=r; row++;col--;}
                        }
                      else
                        {
                            get.flag=-1;
                            myqueen.push(get);
                        }
                        break;
             case 1 : if(r==n){
                        stack<queen> myqueen2;
                        while(!myqueen.empty())
                            {
                                get=myqueen.top();
                                myqueen2.push(get);
                                myqueen.pop();
                            }
                        while(!myqueen2.empty()){

                            get=myqueen2.top();
                            cout<<get.c<<" ";
                            myqueen.push(get);
                            myqueen2.pop();
                        }
                        cout<<endl;
                        get=myqueen.top();
                        unmark(m,get.r,get.c,n);
                        myqueen.pop();
                        if(get.c!=n){
                            get.c++;
                            get.flag=0;
                            myqueen.push(get);
                        }
                        else{
                            get=myqueen.top();
                            unmark(m,get.r,get.c,n);
                            get.c++;
                            get.flag=0;
                            myqueen.pop();
                            myqueen.push(get);
                        }
                        }
                        else
                        {
                            get.r=r+1;
                            get.c=1;
                            get.flag=0;
                            myqueen.push(get);
                        }
                        break;
              case -1 : myqueen.pop();
                        if(c!=n){
                            get.c=c+1;
                            get.flag=0;
                            myqueen.push(get);
                        }
                        else{
                            if(myqueen.empty()){f=0;break;}
                            get=myqueen.top();
                            myqueen.pop();
                            unmark(m,get.r,get.c,n);
                            get.flag=-1;
                            myqueen.push(get);
                        }
                        break;
        }
        if(!f)break;
    }
    return 0;
}
