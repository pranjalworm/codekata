/*
Given an array arr[] of integers, find out the difference between any two elements such that larger element appears after the smaller number in arr[]
*/

//status: executed successfully

#include<stdio.h>

int main()
{
  int i, max, min, n, arr[] = {2, 3, 10, 6, 4, 8, 1};

  n = sizeof(arr) / sizeof(arr[0]);

  for(i=0; i<n; i++)
  {
    if(arr[i] > arr[max] && i > min)
    {
      max = i;
    }
    if(arr[i] < arr[min] && i < max)
    {
      min = i;
    }
  }

  printf("difference: %d", arr[max] - arr[min]);
  return 0;
}
