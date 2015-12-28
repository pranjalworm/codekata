//program to implement naive pattern searching algo
//status: 

#include<stdio.h>
#include<stdlib.h>

int main()
{
  char txt[] = "THIS IS A TEST TEXT", pat[] = "TEST";
  int i, it, j = 0, n = sizeof(txt) / sizeof(txt[0]), m = sizeof(pat) / sizeof(pat[0]);

  for(i = 0; i < n; i++)
  {
    if(txt[i] == pat[j])
    {
      for(j = 1, it = i+1; j < m; j++)
      {
        if(txt[it] == pat[j])
        {
          it++;
        }
        else
        {
          j = 0;
          break;
        }
        if(j == m-1)
        {
          printf("Found!\n");
          exit(0);
        }
      }
    }

  }

  return 0;
}
