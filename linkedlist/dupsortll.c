//program to remove duplicates from a sorted linked list

#include<stdio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *link;
};


//FUNCTION TO INSERT AT THE BEGINNING OF THE LINKED LIST
void insert(struct node **start, int value)
{
  struct node *newnode;
  newnode = (struct node*) malloc(sizeof(struct node));
  newnode->data = value;
  newnode->link = *start;
  *start = newnode;
}


//FUNCTION TO REMOVE DUPLICATES
void remove_duplicates(struct node *start)
{
  if(start == NULL)
  {
    printf("\nLinked List is Empty!\n");
    return;
  }
  struct node *ptr, *temp;
  ptr = start;

  while(ptr -> link != NULL)
  {
    if(ptr -> data == (ptr -> link) -> data)
    {
      temp = ptr -> link;
      ptr -> link = temp -> link;
      free(temp);
      continue;
    }
    ptr = ptr -> link;
  }

}

//FUNCTION TO TRAVERSE LINKED LIST
void traverse(struct node *start)
{
  if(start == NULL)
  {
    printf("\nLinked List is Empty!\n");
    return;
  }
  struct node *temp;
  int count=1;
  temp = start;

  while(temp != NULL)
  {
    printf("Node: %d\tData: %d\n",count,temp->data);
    temp = temp->link;
    count++;
  }
}


//MAIN FUNCTION
int main()
{
  struct node *start; int choice, value;
  start = NULL;

  while(1)
  {
    printf("choose:-\n\n\t1. Insert\n\t2. Remove Duplicates\n\t3. Traverse\n\t4. Exit\n\n");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:
      printf("Enter element: ");
      scanf("%d",&value);
      insert(&start, value);
      break;

      case 2:
      remove_duplicates(start);
      break;

      case 3:
      traverse(start);
      break;

      case 4:
      printf("\nExiting program...\n");
      exit(0);
      break;

      default:
      printf("\nInvalid Input!\n");
      break;
    }
  }
  return 0;
}
