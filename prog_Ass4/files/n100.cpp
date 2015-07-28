#include<bits/stdc++.h>
int main(){
double t;
int n=10;
uint64_t m;
int p=5;
printf("%d\n",p);
srand ( time(NULL) );
while(p--){
printf("%d\n",n);
for(int i=0;i<n;i++)
{
	m=rand();
	m = (m << 32) | rand();
	m=m%10000000000;
	t=m/10000000000.0;
	printf("%.10lf ",t);
}
printf("\n");
}
return 0;
}
