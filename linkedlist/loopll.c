//program to detect loop in linked list
//status: in progress


#include<stdio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node * link;
};

void loop(struct node *start)
{
  if(start == NULL)
  {
    printf("\nLinked list is empty!\n");
    return;
  }

  struct node *ptr1, *ptr2;
  ptr1 = start;
  ptr2 = start;

  while(ptr1 != NULL)
  {
    ptr1 = ptr1 -> link;
    ptr2 = (ptr2 -> link) -> link;

    if(ptr1 -> data == ptr2 -> data)
    {
      printf("\nLoop exists in Linked List!\n");
      return;
    }
  }
}

int main()
{
  struct node *start;
  start = NULL;
  
  return 0;
}
