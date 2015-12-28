//program to reverse an array
//status: executed successfully

#include<stdio.h>


//function to reverse array through recursion
int reverse(int start, int end, int arr[])
{
  int temp;
  if(start < end)
  {
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverse(start+1,end-1,arr);
  }
  else
    return;
}

int main()
{
  int i, j, k, n=7, temp, arr[] ={1,2,3,4,5,6,7};
  int method;
  printf("Method: 1. Loop\t2. Recursion\n\n");
  scanf("%d",&method);
  if(method==1)
  {
    for(i=0, j=n-1; i<j; i++, j--)
    {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  else
  {
    i=0;
    j=n-1;
    reverse(i,j,arr);
  }

  printf("\nAfter:\n");
  for(i=0;i<n;i++)
  {
    printf("%d\t",arr[i]);
  }

  return 0;
}
