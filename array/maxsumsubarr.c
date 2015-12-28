//program to find the largest sum subarray and print the indexes of that sub array
//status: executed successfully

#include<stdio.h>

int main()
{
  int arr[] = {-2, 5, -6, -9, 8, -7, 6, 5, -8};
  int sum = 0, max = 0, f = 0, r = 0, i, n = sizeof(arr) / sizeof(arr[0]);

  for(i = 0; i < n; i++)
  {
    sum = sum + arr[i];

    if(sum > max)
    {
      max = sum;
      r = i;
    }

    if(sum < 0)
    {
      sum = 0;
      f = i+1;
    }
  }

  printf("Start: %d\tEnd: %d\n", f, r);

  printf("Max sum: %d", max);
  return 0;
}
