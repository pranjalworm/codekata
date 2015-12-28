//Write a function which takes an array and emits the majority element (if it exists), otherwise prints NONE
//status: executed successfully

#include<stdio.h>


//solution using moore's voting algorithm
int find_candidate(int arr[], int n)
{
  int i, maj_index = 0;
  int count = 1;

  for(i = 1; i < n; i++)
  {
    if(arr[maj_index] == arr[i])
    {
      count++;
    }
    else
    {
      count --;
    }
    if(count == 0)
    {
      maj_index = i;
      count = 1;
    }
  }

  return arr[maj_index];
}

int main()
{
  int i, arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  int candidate = find_candidate(arr, n);

  int count = 0;

  for(i = 0; i < n; i++)
  {
    if(arr[i] == candidate)
    {
      count++;
    }
  }

  if(count == n/2 + 1)
  {
    printf("majority element: %d", candidate);
  }
  else
  {
    printf("No Majority element exists!\n");
  }
  return 0;
}
