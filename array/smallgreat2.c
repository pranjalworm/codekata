//Given an array, find an element before which all elements are smaller than it, and after which all are greater than it. Return index of the element if there is such an element, otherwise return -1.

//status:

#include<stdio.h>

int main()
{
  int i, j, n, arr[] = {5, 1, 4, 3, 6, 8, 10, 7, 9};
  n = sizeof(arr) / sizeof(arr[0]);

  

  for(i = 0 ; i < n; i++)
  {
    printf("%d\t", arr[i]);
  }
  return 0;
}
