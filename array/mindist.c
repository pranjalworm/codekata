/*
Given an unsorted array arr[] and two numbers x and y, find the minimum distance between x and y in arr[]. The array might also contain duplicates. You may assume that both x and y are different and present in arr[].
status: executed successfully
*/

#include<stdio.h>

int minDist(int arr[], int n, int x, int y)
{
   int i = 0;
   int min_dist = 100;
   int prev;

   for (i = 0; i < n; i++)
   {
     if (arr[i] == x || arr[i] == y)
     {
       prev = i;
       break;
     }
   }

   for ( ; i < n; i++)
   {
      if (arr[i] == x || arr[i] == y)
      {
          if ( arr[prev] != arr[i] && (i - prev) < min_dist )
          {
             min_dist = i - prev;
          }
          prev = i;
      }
   }

   return min_dist;
}


int main()
{
  int arr[] = {2, 5, 3, 5, 4, 4, 2, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Minimum Distance: %d", minDist(arr, n, 3, 2));
  return 0;
}
