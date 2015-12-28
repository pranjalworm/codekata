//You are given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side of the array. Traverse array only once.

//status: executed successfully

#include<stdio.h>

int main()
{
  int i, j, temp, n, arr[] = {0, 0, 0, 0, 0, 0, 1, 1, 1};
  n = sizeof(arr)/sizeof(arr[0]);

  for(i=0; i<n; i++)
    printf("%d\t",arr[i]);

  printf("\n\n");

  i = 0;
  j = n-1;

  while(i != j)
  {
    if(arr[i] == 1 && arr[j] == 0)
    {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
    if(arr[i] == 0)
    {
      i++;
    }
    if(arr[j] == 1)
    {
      j--;
    }
  }

  for(i=0; i<n; i++)
    printf("%d\t",arr[i]);

  return 0;
}
