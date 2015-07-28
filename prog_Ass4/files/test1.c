#include<stdio.h>
int main()
{
int i;
printf("%d\n",5000002);
for(i=0;i<=2500000;i++)
printf("I %d\n",i);

for(i=2500000-1;i<=2500000+2500000-1;i++)
printf("S %d\n",i);
}
