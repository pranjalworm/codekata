//floor and ceiling in a sorted array
//status: BUGS: below example: when x = 10

#include<stdio.h>

int main()
{
  int arr[] = { 1, 2, 8, 10, 10, 12, 19};

  int mid, f, r, x, n = sizeof(arr) / sizeof(arr[0]);
  f = 0;
  r = n - 1;

  printf("Enter x: ");
  scanf("%d",&x);

  for(mid = (f + r) / 2; f <= r; mid = (f + r) / 2)
  {
    if(arr[mid] == x)
    {
      printf("1 Floor: %d\tCeil: %d", arr[mid-1], arr[mid+1]);
      break;
    }
    else if(arr[mid] > x)
    {
      if(arr[mid - 1] < x)
      {
        printf("2 Floor: %d\tCeil: %d", arr[mid-1], arr[mid]);
        break;
      }
      else
      {
        r = mid - 1;
      }
    }
    else
    {
      if(arr[mid + 1] > x)
      {
        printf("3 Floor: %d\tCeil: %d", arr[mid], arr[mid+1]);
        break;
      }
      else
      {
        f = mid + 1;
      }
    }
  }
  return 0;
}
