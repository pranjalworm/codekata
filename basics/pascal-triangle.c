//program to create pascal triangle
#include<stdio.h>

int fact(int i)
{
  if (i == 0 || i == 1)
  {
    return 1;
  }
  else
  {
    return i * fact(i-1);
  }
}

int main()
{
  int i, j, k, val, n = 5;

  for(i = 0; i < n; i++)
  {
    for(k = i; k < n; k++)
    {
      printf(" ");
    }

    for(j = 0 ; j <= i; j++)
    {
      val = fact(i)/(fact(j) * fact(i-j));
      printf("%d ", val);
    }
    printf("\n");
  }

 
  return 0;
}
