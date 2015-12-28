//program to check if a linked list is a palindrome
//status: in progress

#include<stdio.h>
#include<malloc.>

struct node
{
  int data;
  struct node *link;
};

struct stack
{
  int top;
  int data[10];
};


void palindrome(struct node *start)
{

}

void insert_beg(struct node **start, int value)
{
  struct node *newnode;
  newnode = (struct node*) malloc(sizeof(struct node));
  newnode->data = value;
  newnode->link = *start;
  *start = newnode;
}

int main()
{
  struct node *start;
  start = NULL;
  return 0;
}
