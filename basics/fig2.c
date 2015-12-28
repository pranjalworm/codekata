//program to generate figure below
/*

*****
****
***
**
*

*/
//status: in progress

#include<stdio.h>
int main()
{
  int n,i,j;
  printf("size of figure: ");
  scanf("%d",&n);

  for(i=n;i>0;i--)
  {
    for(j=i;j>0;j--)
    {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
