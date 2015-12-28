//binary search
//status: executed successfully
#include<stdio.h>
#include<stdlib.h>

int bin(int num, int lower, int upper, int arr[])
{
  static int count = 0;
  int middle;
  if(lower <= upper)
  {
    middle = (upper + lower)/2;
    printf("\nCount: %d\tMiddle: %d\n",++count, arr[middle]);

    if(arr[middle] == num)
    {
      return middle;
    }
    else if(arr[middle] < num)
    {
      bin(num, middle + 1, upper, arr);
    }
    else
    {
      bin(num, lower, middle - 1, arr);
    }
  }
  else
  {
    return -1;
  }
}

int main()
{
  int arr[10] = {1,2,3,4,5,6,7,8,9,10};
  int num, middle, upper, lower, count = 0, method, pos;
  upper = 9;
  lower = 0;


  printf("Enter num to search: ");
  scanf("%d",&num);

  printf("\n\t1. Loop\t2. Recursion\n\n");
  scanf("%d",&method);
  if(method == 1)
  {
    for(middle = (upper + lower)/2; lower <= upper; middle = (upper + lower)/2)
    {
      count++;
      printf("\nCount: %d\tMiddle: %d",count, arr[middle]);

      if(arr[middle] == num)
      {
        printf("\nElement found: %d at Position: %d\n",arr[middle], middle);
        exit(0);
      }
      else if (arr[middle] < num)
      {
        lower = middle + 1;
      }
      else
      {
        upper = middle - 1;
      }
    }
  }
  else
  {
    pos = bin(num,lower,upper,arr);
    if(pos == -1)
      printf("Element not found!");
    else
      printf("\nElement: %d\tPosition: %d\n",num, pos);

    exit(0);
  }

  printf("element not found!");
  return 0;
}
