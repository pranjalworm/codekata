/*
Given an array A[] consisting 0s, 1s and 2s, write a function that sorts A[]. The functions should put all 0s first, then all 1s and all 2s in last.
status: can be solved using counting sort solution in O(n) time; find another solution  
*/

#include<stdio.h>

int main()
{
  int f, r, n, arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};

  n = sizeof(arr) / sizeof(arr[0]);
  f = 0;
  r = n-1;

  while(f != n-1)
  {
    if(arr[f] == 2)
    {

    }
  }
  return 0;
}
