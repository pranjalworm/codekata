//program to print fibonacci series upto nth term
//status: in progress

#include<stdio.h>

//fibonacci series through loop
void loop(int n)
{
  int fn, term = 0, f1 = 1, f2 = 1;

  while(term != n-2)
  {
    fn = f1 + f2;
    f1 = f2;
    f2 = fn;
    printf("%d\t",fn);
    term++;
  }
}


//fibonacci series through recursion
void recursion(int n, int f1, int f2)
{
  static int term = 0;
  if(term == n-2)
  {
    return;
  }
  term++;
  printf("%d\t", f1 + f2);

  recursion(n, f2, f1+f2);
}


//fibonacci series using a better recursive algo
int fib(int n)
{
  int f;
  if(n <= 2)
  {
    f = 1;
  }
  else
  {
    f = fib(n-1) + fib(n-2);
  }
  return f;
}

int bottomup(int n)
{
  int i, fib[100] = {0};

  for(i = 1; i <= n; i++)
  {
    if(i <= 2)
    {
      fib[i] = 1;
    }
    else
    {
      fib[i] = fib[i-1] + fib[i-2];
    }
  }

  return fib[n];
}

//MAIN FUNCITON
int main()
{
  int n, i, j, method;
  printf("Enter N: ");
  scanf("%d",&n);

  printf("Choose method: 1. Loop\t2. Recursion\t3. Recursion (Memoized algo)\t4. Bottom-up algo\n\n");
  scanf("%d",&method);

  switch(method)
  {
    case 1:
    printf("1\t1\t");
    loop(n);
    break;

    case 2:
    printf("1\t1\t");
    recursion(n, 1, 1);
    break;

    case 3:
    printf("%dth fibonacci term: %d", n, fib(n));
    break;

    case 4:
    printf("%dth fibonacci term: %d",n, bottomup(n));
    break;

    default:
    printf("invalid input!");
  }

  return 0;
}
