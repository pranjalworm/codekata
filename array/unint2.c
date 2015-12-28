//union and intersection of two sorted arrays
//status:

#include<stdio.h>

int main()
{
  int i, j, m, n, arr1[] = {1, 3, 4, 5, 7}, arr2[] = {2, 3, 5, 6};

  m = sizeof(arr1) / sizeof(arr1[0]);
  n = sizeof(arr2) / sizeof(arr2[0]);
   i = j = 0;

  while(1)
  {
    if(arr1[i] != arr2[j])
    {
      printf("%d\t", arr1[i]);
    }
    printf("%d\t", arr2[j]);

    if(j == n)
    {
      for( ; i < m; i++)
      {
        printf("%d\t", arr1[i]);
        break;
      }
    }

    if(i == m)
    {
      for( ; j < n; j++)
      {
        printf("%d\t", arr2[j]);
        break;
      }
    }

    i++; j++;

  }

  return 0;
}
