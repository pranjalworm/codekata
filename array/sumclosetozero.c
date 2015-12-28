//An Array of integers is given, both +ve and -ve. You need to find the two elements such that their sum is closest to zero.
//status: executed successfully; optimum solution

#include<stdio.h>
#include<math.h>
#define SIZE sizeof(arr) / sizeof(arr[0])

int swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int l, int h)
{
  int i, j, pivot = arr[h];
  j = l-1;

  for(i = l; i <= h-1; i++)
  {
    if(arr[i] <= pivot)
    {
      j++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[j+1], &arr[h]);

  return (j+1);
}

void quicksort(int arr[], int l, int r)
{
  if(l < r)
  {
    int p = partition(arr, l, r);
    quicksort(arr, l, p-1);
    quicksort(arr, p+1, r);
  }
}


int main()
{
  int i, f, r, ff, rf, sum, temp, arr[] = {1, 60, -10, 70, -80, 85};

  quicksort(arr, 0, SIZE-1);

  sum = arr[SIZE-1];
  f = 0;
  r = SIZE - 1;

  while(f < r)
  {
    temp = abs(arr[f] + arr[r]);
    if(temp < sum)
    {
      sum = temp;
      ff = f;
      rf = r;
    }

    if(temp > 0)
    {
      r--;
    }
    else if(temp < 0)
    {
      f++;
    }
    else
    {
      break;
    }
  }

  printf("Pair: %d\t%d",arr[ff], arr[rf]);
  return 0;
}
