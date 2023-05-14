#include <stdio.h>
#define max 100
void main()
{
printf("First defined value for max : %d\n",max);
int i;
for(i=0;i<max;i++)
{
printf("%d\n",i);
}
// #undef max // undefining variable
#define max 6 // redefining the same for new value
printf("value of max after undef \& redefine:%d\n",max);
// int i;
for(i=0;i<max;i++)
{
printf("%d\n",i);
}
}