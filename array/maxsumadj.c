/*
Given an array of positive numbers, find the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence should be adjacent in the array. So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).

status: executed successfully
*/
#include<stdio.h>

int main()
{
  int n, i = 0, sum = 0, arr[] = {5,5,10,100,10,5};
  n = sizeof(arr) / sizeof(arr[0]);

  while(i < n-1)
  {
    if(arr[i] < arr[i+1])
    {
      i++;
    }

    sum = sum + arr[i];
    i = i + 2;

    if(i == n-1)
    {
      sum = sum + arr[n-1];
      break;
    }

  }

  printf("\n\nSum : %d",sum);
  return 0;
}
