//Find the smallest and second smallest element in an array
//status : executed successfully


#include<stdio.h>

int main()
{
  int i, min1=0, min2, arr[] ={10,2,-1,4,1,6,7,0,9,10};

  for(i=1;i<10;i++)
  {
    if(arr[i] < arr[min1])
    {
      min2 = min1;
      min1 = i;
    }
    else if(arr[i] < arr[min2] && i != min1)
    {
      min2 = i;
    }
    printf("M1: %d\tM2: %d\n",min1,min2);
  }

  printf("\nSmallest element: %d\n",arr[min1]);
  printf("2nd Smallest element: %d\n",arr[min2]);

  return 0;
}
