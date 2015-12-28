//program to generate figure below
/*

  *
 ***
*****

*/
//status: in progress

#include<stdio.h>
int main()
{
  int n,i,j;
  printf("size of figure: ");
  scanf("%d",&n);

  for(i = 1; i <= n; i++)
  {
    for(j = 1; j < n+i; j++)
    {
      if(j <= n-i)
      {
        printf(" ");
        continue;
      }
      else if(j <= i*2-1)
      {
        printf("*");
      }
    }
    printf("\n");
  }

  return 0;
}
