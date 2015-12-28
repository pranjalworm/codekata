/*
Write a C program that, given an array A[] of n numbers and another number x, determines whether or not there exist two elements in S whose sum is exactly x.
*/

//status: executed successfully
#include<stdio.h>
#include<math.h>

int main()
{
  int hashp[100] = {0},hashn[100] = {0}; //hashp(+ve) and hashn(-ve)
  int arr[] = {-8,10,-2,-10,2,0,8};
  int i, temp,temp2,sum,n=7;
  printf("Enter sum: ");
  scanf("%d",&sum);

  for(i=0;i<n;i++)
  {
    temp = sum - arr[i];

    if(temp < 0)
    {
      temp2 = abs(temp);
      if(hashn[temp2] == 1)
      printf("\nPair: %d %d",temp, arr[i]);
    }

    if(temp >= 0 && hashp[temp] == 1)
    {
      printf("\nPair: %d %d",temp, arr[i]);
    }


    if(arr[i]>=0)
     hashp[arr[i]] = 1;
    else
    {
      temp2 = abs(arr[i]);
      hashn[temp2] = 1;
    }
  }
  return 0;
}
