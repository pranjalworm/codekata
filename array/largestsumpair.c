//Find the largest pair sum in an unsorted array
//status: executed successfully

#include<stdio.h>

int main()
{
  int arr[] = {12, 34, 10, 6, 40}, i, max1 = -1, max2 = -1, n;

  n = sizeof(arr) / sizeof(arr[0]);

  for(i = 0; i < n; i++)
  {
    if(arr[i] > max1)
    {
      max2 = max1;
      max1 = arr[i];
    }
    else if(arr[i] > max2)
    {
      max2 = arr[i];
    }
  }

  printf("Max1: %d\tMax2: %d", max1, max2);

  printf("\nMax Sum: %d", max1 + max2);
  return 0;
}
