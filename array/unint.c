//union and intersection of two sorted arrays
//status: executed successfully

#include<stdio.h>

int main()
{
  int i, m, n, arr1[] = {1, 3, 4, 5, 7}, arr2[] = {2, 3, 5, 6};
  int union_arr[20] = {0}, intersection_arr[20] = {0};

  m = sizeof(arr1) / sizeof(arr1[0]);
  n = sizeof(arr2) / sizeof(arr2[0]);

  for(i = 0; i < m; i++)
  {
    union_arr[arr1[i]]++;
    intersection_arr[arr1[i]]++;
  }

  for(i = 0; i < n; i++)
  {
    union_arr[arr2[i]]++;
    intersection_arr[arr2[i]]++;
  }

  //printing union of the two arrays
  printf("\n\nUnion: ");
  for(i = 0; i < 20; i++)
  {
    if(union_arr[i] != 0)
    {
      printf("%d\t",i);
    }
  }

  //printing intersection of the two arrays
  printf("\n\nIntersection: ");
  for(i = 0; i < 20; i++)
  {
    if(intersection_arr[i] == 2)
    {
      printf("%d\t",i);
    }
  }

  printf("\n\n");

  return 0;
}
