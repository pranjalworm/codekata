/*
count the number of smaller elements on the right hand side

status: executed; reduce complexity
*/

#include<stdio.h>

int main()
{
  int i, j, n, count, arr[] = {12, 1, 2, 3, 0, 11, 4};

  n = sizeof(arr) / sizeof(arr[0]);

  for(i = 0; i < n-1; i++)
  {
    count = 0;
    for(j = i+1; j < n; j++)
    {
      if(arr[i] > arr[j])
      {
        count++;
      }
    }
    printf("%d\t", count);
  }
  printf("0");
  return 0;
}
