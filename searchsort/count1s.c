//Given a binary array sorted in non-increasing order, count the number of 1’s in it.
//status: executed successfully


#include<stdio.h>
#include<stdlib.h>

int main()
{
  int mid, upper, lower, n, arr[] = {1,1,1,1,1,1,1,1,1};
  n = sizeof(arr) / sizeof(arr[0]);

  upper = n-1;
  lower = 0;

  for(mid = (upper+lower)/2; lower <= upper; mid = (upper+lower)/2)
  {
    if(arr[mid] == 1 && (arr[mid+1] == 0 || mid == n-1))
    {
      printf("Number of 1s: %d",mid+1);
      exit(0);
    }
    else if(arr[mid] == 0)
    {
      upper = mid - 1;
    }
    else
    {
      lower = mid + 1;
    }
  }

  printf("Number of 1s: 0");
  return 0;
}
