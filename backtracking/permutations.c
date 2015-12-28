//Write a program to print all permutations of a given string
//status:

#include<stdio.h>

void swap(char *a, char *b)
{
  char temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void permute(char str, int l, int r)
{
  if(l == r)
  {
    printf("%s\n",str);
  }
  else
  {
    
  }
}

int main()
{
  char str[] = 'abc';
  int n = sizeof(str) / sizeof(str[0]);

  permute(str, 0, n-1);

  return 0;
}
