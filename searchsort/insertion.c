//perform insertion sort
//status: executed successfully
#include<stdio.h>

int main()
{
  int n, i, j, key, arr[] = {5,2,3,7,1,9,3,8,4,};

  n = sizeof(arr) / sizeof(arr[0]);

  for(i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;
    while(j >= 0 && arr[j] > key)
    {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }

  for(i = 0; i < n; i++)
  {
    printf("%d\t",arr[i]);
  }
  return 0;
}
