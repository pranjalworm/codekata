//selection sort
//status: executed successfully

#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i, j, n = 5, min, temp, arr[] = {5,4,3,2,1};

  for(i=0; i<n-1; i++)
  {
    min = i;
    for(j=i+1; j<n; j++)
    {
      if(arr[j] < arr[min])
      {
        min = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }

  printf("\nSorted:\n");
  for(i=0;i<n;i++)
  {
    printf("%d\t",arr[i]);
  }
  return 0;
}
