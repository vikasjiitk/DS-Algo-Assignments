#include<bits/stdc++.h>
using namespace std;
struct tree{
    int val;
    int siz;
    tree *left;
    tree *right;
};
tree *T=NULL;
int k;
void give_array(int *arr, tree *t,int n)
{
    tree *p = t;
    if(p==NULL) return;
    else{
            if(p->left != NULL) give_array(arr, p->left,n);
            arr[k++]=p->val;
            if(p->right != NULL) give_array(arr,p->right,n);
            if(p->siz!=n) delete p;
         }
}
void make_tree(int *arr,int i,int j,tree *t,int n)
{
    int mid=(i+j)/2;
    if(j-i==n-1){
        t->val=arr[mid];
        t->left=NULL;
        t->right=NULL;
        t->siz=n;
    }else{
        t->val=arr[mid];
        t->left=NULL;
        t->right=NULL;
        t->siz=j-i+1;
    }
    if(i<mid){ tree *m = new tree; m->val=0; m->left=NULL; m->right=NULL; m->siz=0; t->left=m; make_tree(arr,i,mid-1,t->left,n);}
    if(j>mid){ tree *m = new tree; m->val=0; m->left=NULL; m->right=NULL; m->siz=0; t->right=m; make_tree(arr,mid+1,j,t->right,n);}
    return;
}
void balance(tree *p)
{
    int n= p->siz;
    int *arr= new int[n];
    k=0;
    give_array(arr,p,n);
    make_tree(arr,0,n-1,p,n);
    delete[] arr;
    return;
}
void search_tree(int x)
{
    if(T==NULL){ printf("0\n"); return;}
    tree *p=T;
    while(p!=NULL)
    {
        if(p->val==x){printf("1\n"); return; }
        if(p->val > x) p=p->left;
        else p=p->right;
    }
    printf("0\n");
    return;
}
void insert_tree(int x)
{
    tree *p=T;
    tree *node = new tree;
    node->left=NULL;
    node->right=NULL;
    node->val=x;
    node->siz=1;
    int f=0;
    tree *unbalanced;
    if(T==NULL){ T=node; return; }
    while(1)
    {
        p->siz+=1;
        if(p->val > x){
            if(p->left==NULL){p->left=node; if(f) balance(unbalanced); return; }
            else {
                    if(!f){
                            tree *temp=p->left;
                        if(temp->siz+1 > 3.0/4*(p->siz)){ unbalanced=p; f=1; }
                    }
                     p=p->left;
            }
        }
        else{
            if(p->right==NULL){ p->right=node; if(f) balance(unbalanced); return; }
            else {
                    if(!f){
                            tree *temp=p->right;
                        if(temp->siz+1 > 3.0/4*(p->siz)){ unbalanced=p; f=1; }
                    }
                    p=p->right;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char ch;int x;
        cin>>ch;
        cin>>x;
        if(ch=='S')
        search_tree(x);
        else insert_tree(x);
    }
    return 0;
}
