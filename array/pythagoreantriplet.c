//Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.
//status:

#include<stdio.h>
#include<stdlib.h>

int main()
{
  int arr[] = {3, 1, 4, 6, 5}, n, i;

  n = sizeof(arr) / sizeof(arr[0]);

  int *square = (int*) calloc(n, sizeof(int));

  for(i = 0; i < n; i++)
  {
    printf("%d\t", square[i]);
  }


  return 0;
}
