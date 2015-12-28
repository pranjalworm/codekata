//Given an array, find an element before which all elements are smaller than it, and after which all are greater than it. Return index of the element if there is such an element, otherwise return -1.

//status: executed successfully

#include<stdio.h>

int main()
{
  int i = 1, j = 0, k = -1, n, arr[] = {5, 1, 4, 3, 6, 8, 10, 7, 9};
  n = sizeof(arr) / sizeof(arr[0]);

  while(i != n-1)
  {
    while(j != n)
    {
      if(i == j)
      {
        j++;
      }

      if((i > j && arr[i] > arr[j]) || (i < j && arr[i] < arr[j]))
      {
        k = i;
        j++;
      }
      else
      {
        i++;
        j = 0;
      }
    }
    if(j == n)
    {
      break;
    }
  }

  if(k == -1)
  {
    printf("\nNo such element found!\n");
  }
  else
  {
    printf("\nElement found: %d\n", arr[k]);
  }

  for(i = 0 ; i < n; i++)
  {
    printf("%d\t", arr[i]);
  }
  return 0;
}
