//leaders in array
//status: executed successfully

#include<stdio.h>

int main()
{
  int arr[] = {16, 17, 4, 3, 5, 2};

  int i, n = sizeof(arr) / sizeof(arr[0]), max = arr[n-1];

  printf("Leaders: %d\t", arr[n-1]);

  for(i = n-2; i >=0; i--)
  {
    if(arr[i] > max)
    {
      max = arr[i];
      printf("%d\t",max);
    }
  }
  return 0;
}
