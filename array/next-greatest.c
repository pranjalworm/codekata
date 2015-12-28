//program to find the next greatest number
//status: executed successfully

#include<stdio.h>
int main()
{
  int i, j, k, m, max, n=10, arr[10]={9,2,5,6,8,7,0,3,1,5}, hash[10]={0};

  printf("Enter m: ");
  scanf("%d",&m);

  for(i=0;i<m;i++)
  {
    max = -1;

    for(j=0;j<n;j++)
    {
        if(arr[j] > max && hash[j] == 0)
        {
          max = arr[j];
          k = j;
        }
    }
    hash[k] = 1;
  }
  printf("mth greatest number: %d", max);

  return 0;
}
