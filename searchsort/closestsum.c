/*
Given two sorted arrays and a number x, find the pair whose sum is closest to x and the pair has an element from each array.
status: executed successfully
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
  int ar1[] = { 1, 4, 5, 7}, ar2[] = { 10, 20, 30, 40}, x, m, n;
  printf("Enter X: ");
  scanf("%d", &x);
  n = sizeof(ar2) / sizeof(ar2[0]);
  m = sizeof(ar1) / sizeof(ar1[0]);

  int diff = 1000;
    int res_l, res_r;

    int l = 0, r = n-1;
    while (l < m && r >= 0)
    {
       if (abs(ar1[l] + ar2[r] - x) < diff)
       {
           res_l = l;
           res_r = r;
           diff = abs(ar1[l] + ar2[r] - x);
       }

       if (ar1[l] + ar2[r] > x)
           r--;
       else
          l++;
    }

    printf("Pair: %d %d", ar1[res_l], ar2[res_r]);
    return 0;
}
