#include<bits/stdc++.h>
using namespace std;
int comparison=0;         //Global variable for calculating total no of comparisons to sort an array
int partition_a(double *a,int l,int r){   //function for partitioning array
    double x=a[l];                  //first element as pivot element
    double temp;
    for(int i=l+1;i<=r;i++)
    {
        if(a[i]<=x)                  //swapping x with the smaller element.
        {
            temp=a[i];
            a[i]=a[l];
            a[l]=temp;
            l=i;
        }
        else                       // swapping bigger element(than x) with last element.

        {
            temp=a[i];
            a[i]=a[r];
            a[r]=temp;
            i--;
            r--;
        }
        comparison++;             //incrementing comparison in each step
    }
    return l;                     //returning new position of pivot element x
}
void quicksort(double *a,int l,int r){
    if(l<r){
        int i;
        i=partition_a(a,l,r);       //partitioning array with first element as pivot element
        quicksort(a,l,i-1);         //recursive call of quick_sort after placing one element at proper place
        quicksort(a,i+1,r);
    }
}
int main(){
    clock_t begin=clock();
    int t;
    scanf("%d",&t);
    while(t--){
    comparison=0;
    int n;
    scanf("%d",&n);                   //size of array
    double arr[n];
    for(int i=0;i<n;i++){            //input array
        scanf("%lf",&arr[i]);
    }
    quicksort(arr,0,n-1);           //sorting array
    for(int i=0;i<n;i++){
        printf("%lf ",arr[i]);        //displaying array
    }
    printf("%d\n",comparison);       //printing total no. of comparison required for sorting array
    }
    clock_t end=clock();
	double time= double(end - begin) / CLOCKS_PER_SEC;
	printf("%lf\n",time);
    return 0;
}
