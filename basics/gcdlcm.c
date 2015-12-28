//program to find the gcd of two numbers
//status: executed successfully

#include<stdio.h>

int main()
{
  int a, b, at, bt;
  printf("Enter A & B: ");
  scanf("%d %d", &a, &b);
  at = a;
  bt = b;

  while(a != b)
  {
    if(a > b)
    {
      a = a - b;
    }
    else
    {
      b = b - a;
    }
  }

  printf("GCD: %d\nLCM: %d", a, (at*bt)/a);
  return 0;
}
