//program to perform quicksort
//status: executed successfully; optimum solution
#include<stdio.h>

int swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int f, int r)
{
  int i, j, pivot = arr[r];
  j = f-1;

  for(i = f; i <= r-1; i++)
  {
    if(arr[i] <= pivot)
    {
      j++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[j+1], &arr[r]);

  return (j+1);
}

void quicksort(int arr[], int f, int r)
{
  if(f < r)
  {
    int p = partition(arr, f, r);
    quicksort(arr, f, p-1);
    quicksort(arr, p+1, r);
  }
}

int main()
{
  int i, n, arr[] = {6,5,4,3,2,};
  n = sizeof(arr) / sizeof(arr[0]);

  //printing given array
  for(i = 0; i < n; i++)
    printf("%d\t",arr[i]);

  quicksort(arr, 0, n-1);

  //printing sorted arrya
  printf("\n\n");

  for(i = 0; i < n; i++)
    printf("%d\t",arr[i]);

  return 0;
}
