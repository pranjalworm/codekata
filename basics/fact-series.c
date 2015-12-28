//program to print the series below
/*
1/1! + 2/2! + 3/3! + ...
*/
//status: in progress

#include<stdio.h>
int main()
{
  int n,i;
  printf("Enter nth term: ");
  scanf("%d",&n);
  printf("\n\n");
  for(i=1;i<=n;i++)
  {
    printf("%d/%d!",i,i);
    if(i<n)
    {
      printf(" + ");
    }
  }
  return 0;
}
