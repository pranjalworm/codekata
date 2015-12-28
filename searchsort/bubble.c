//bubble sort
//status: executed successfully
#include<stdio.h>

int main()
{
  int i, j, n=5,temp,swapped,arr[] = {5,4,2,1,0};

  for(i=0;i<n;i++)
  {
    printf("%d\t",arr[i]);
  }

  for(i=0;i<n;i++)
  {
    swapped = 0;  //swapped is used for optimization
    for(j=0;j<n-1-i;j++)
    {
      if(arr[j] > arr[j+1])
      {
        temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
        swapped = 1;
      }
    }
    if(swapped == 0)
    {
      break;
    }
  }
  printf("\nafter\n");
  for(i=0;i<n;i++)
  {
    printf("%d\t",arr[i]);
  }

  return 0;
}
