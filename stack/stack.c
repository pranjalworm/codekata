//program to perform push pop operations on stack
//status: executed successfully

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct stack
{
  int data[10];
  int top;
};

void initstack(struct stack *s);
void push(struct stack *s, int value);
void pop(struct stack *s);


//MAIN FUNCTION
int main()
{
  int choice,value;
  struct stack s;

  initstack(&s);

  while(1)
  {
    printf("\n\nChoose:\n\t1. Push\n\t2. Pop\n\t3. Exit program\n\n");
    scanf("%d",&choice);

    switch (choice)
    {
      case 1:
      printf("Enter value: ");
      scanf("%d", &value);
      push(&s, value);
      break;

      case 2:
      pop(&s);
      break;

      case 3:
      printf("\nExiting program...\n");
      exit(0);
      break;

      default:
      printf("\n\n!!! Invalid choice !!!\n\n");
    }
  }
}


//FUNCTION TO INITIALISE STACK
void initstack(struct stack *s)
{
  s -> top = -1;
  printf("\nInitstack (top): %d\n", s -> top);
}


//FUNCTION TO PUSH ELEMENTS IN STACK
void push(struct stack *s, int value)
{
  if(s -> top == MAX-1)
  {
    printf("\n\nStack Full!\n\n");
  }
  else
  {
      s -> top++;
      s -> data[s -> top] = value;
      printf("\nPush (top): %d\n", s -> top);
  }
}


//FUNCTION TO POP ELEMENTS FROM STACK
void pop(struct stack *s)
{
  if(s -> top == -1)
  {
    printf("\n\nStack Empty!\n\n");
    return;
  }
  printf("Popped Element: %d\n",s -> data[s -> top]);
  s -> top--;
  printf("\nPop (top): %d\n", s -> top);
}
