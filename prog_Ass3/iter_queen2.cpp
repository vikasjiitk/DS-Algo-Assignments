#include<bits/stdc++.h>
using namespace std;
int **m;
int n;
struct queen{
int r;
int c;
int flag;     // 1 for safe position, -1 for unsafe position, 0 for uncertain position
};
queen *myqueen;
int top=-1;
int emptystack(queen *q,int &top)
{
    if(top==-1)return 1;
    return 0;
}
void pop(queen *q, int &top)
{
    if(top>=0)
    top--;
}
void push(queen *q,int &top, queen get)
{
    if(top<n-1)
        q[++top]=get;
}
queen topstack(queen *q, int &top)
{
    if(top>=0)
        return q[top];
}
void unmark(int **m,int r,int c,int n)
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
    cin>>n;
    m=new int*[n+1];
    for(int i=0;i<=n;i++)
        m[i]=new int[n+1];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)m[i][j]=0;
    myqueen = new queen[n];
    queen t;
    t.r=1; t.c=1; t.flag=1;
    push(myqueen,top,t);

    for(int i=1;i<=n;i++){m[1][i]=1;m[i][1]=1;m[i][i]=1;}

    queen get;
    int f=1;
    while(!emptystack(myqueen,top))
    {
        get=topstack(myqueen,top);
        int flag=get.flag;
        int r=get.r;
        int c=get.c;
        switch(flag){
            case 0 :    pop(myqueen,top);
                        if(!m[r][c]){
                        get.flag=1;
                        push(myqueen,top,get);
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
                            push(myqueen,top,get);
                        }
                        break;
             case 1 : if(r==n){
                        queen *myqueen2 = new queen[n];
                        int top2=-1;
                        while(!emptystack(myqueen,top))
                            {
                                get=topstack(myqueen,top);
                                push(myqueen2,top2,get);
                                pop(myqueen,top);
                            }
                        while(!emptystack(myqueen2,top2)){

                            get=topstack(myqueen2,top2);
                            cout<<get.c<<" ";
                            push(myqueen,top,get);
                            pop(myqueen2,top2);
                        }
                        cout<<endl;
                        delete myqueen2;
                        get=topstack(myqueen,top);
                        unmark(m,get.r,get.c,n);
                        pop(myqueen,top);
                        if(get.c!=n){
                            get.c++;
                            get.flag=0;
                            push(myqueen,top,get);
                        }
                        else{
                            get=topstack(myqueen,top);
                            unmark(m,get.r,get.c,n);
                            get.c++;
                            get.flag=0;
                            pop(myqueen,top);
                            push(myqueen,top,get);
                        }
                        }
                        else
                        {
                            get.r=r+1;
                            get.c=1;
                            get.flag=0;
                            push(myqueen,top,get);
                        }
                        break;
              case -1 : pop(myqueen,top);
                        if(c!=n){
                            get.c=c+1;
                            get.flag=0;
                            push(myqueen,top,get);
                        }
                        else{
                            if(emptystack(myqueen,top)){f=0;break;}
                            get=topstack(myqueen,top);
                            pop(myqueen,top);
                            unmark(m,get.r,get.c,n);
                            get.flag=-1;
                            push(myqueen,top,get);
                        }
                        break;
        }
        if(!f)break;
    }
    return 0;
}
