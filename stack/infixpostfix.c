//infix to postfix conversion using stack
//status:

#include<stdio.h>

struct stack
{
  int top;
  int exp[15];
};

void initstack(struct stack *s)
{
  s -> top = -1;
}

int main()
{
  struct stack s;

  initstack(&s);

  
}
