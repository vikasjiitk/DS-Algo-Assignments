#include<bits/stdc++.h>
using namespace std;
struct tree{
    int val;
    tree *left;
    tree *right;
};
tree *T=NULL;
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

    if(T==NULL){ T=node; return; }

    while(1)
    {
        if(p->val > x){
            if(p->left==NULL){p->left=node; return; }
            else p=p->left;
        }
        else{
            if(p->right==NULL){ p->right=node; return; }
            else p=p->right;
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
