/*
Write a C program that, given an array A[] of n numbers and another number x, determines whether or not there exist two elements in S whose sum is exactly x.
*/

//status: executed successfully

#include<stdio.h>

void main()
{
  int arr[] = {5,4,1,2,0,3};
  int i, j, temp, sum, swapped, n=6;

  printf("Enter sum: ");
  scanf("%d",&sum);

  for(i=0;i<n;i++)
  {
    swapped = 0;
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
      break;
  }

  i = 0;
  j = 5;

  while(i < j)
  {
    if(arr[i] + arr[j] == sum)
    {
      printf("\nPair: %d\t%d\n",arr[i],arr[j]);
      i++;
      j--;
    }
    else if(arr[i] + arr[j] < sum)
    {
      i++;
    }
    else
    {
      j--;
    }
  }

}
