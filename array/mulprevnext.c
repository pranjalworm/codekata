// program to replace each element in the array with the multiplication of prev and next elements
// status : executed, reduce space complexity

#include<stdio.h>

int main()
{
  int i, prev, next, n, arr[] = {2, 3, 4, 5, 6};

  n = sizeof(arr) / sizeof(arr[0]);
  temp = arr[0];
  prev = 0;
  next = 1;

  for(i = 0; i < n; i++)
  {
    temp = arr[i];
    
    arr[i] = arr[prev] * arr[next];

    if(i != 0)
    {
      prev++;
    }

    if(i != n-1)
    {
      next++;
    }
  }

  for(i = 0; i < n; i++)
    printf("%d\t",arr[i]);

  return 0;
}
