//Write a function which takes an array and emits the majority element (if it exists), otherwise prints NONE
//status: executed successfully:  not the most optimum solution

#include<stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
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
  int i, n, maj, final_maj, count, final_count, arr[] = {3, 3, 4, 2, 4, 4, 3, 3, 3, 3, 2, 3, 3, 4, 4};
  n = sizeof(arr) / sizeof(arr[0]);

  quicksort(arr, 0, n-1);

  maj = arr[0];
  final_count = count = 0;

  for(i = 0; i < n; i++)
  {
    if(arr[i] == maj)
    {
      count++;
      if(count > final_count)
      {
        final_count = count;
        final_maj = maj;
      }
    }
    else
    {
      maj = arr[i];
      count = 1;
    }
  }

  if(final_count >= (n/2 + 1))
    printf("\nMajority element: %d\n", final_maj);

  else
    printf("\nNo Majority element!\n");
}
