//program to find armstrong numbers in a given range
//status: in progress

//header files
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

//main program
int main()
{
  int i, i_copy, j, min, max, count, sum, arr[5];
  printf("Enter min: ");
  scanf("%d",&min);

  printf("\nEnter max: ");
  scanf("%d",&max);

  printf("\n");

  for(i=min;i<=max;i++)
  {
    i_copy = i;

    for(j=0; j<5; j++)
      arr[j] = 0;

    sum = count = 0;
    while(i_copy)
    {
      arr[count] = i_copy % 10;
      i_copy = i_copy/10;
      count++;
    }

    for(j=0; j<count; j++)
    {
      sum = sum + pow(arr[j],count);
    }

    if(sum == i)
      printf("%d\n",i);
  }

  return 0;
}
