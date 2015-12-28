//program to create a linked list which contains elements in ascending order
//status: executed successfully

#include<stdio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *link;
};

//FUNCTION TO TRAVERSE
void traverse(struct node *start)
{
  if(start == NULL)
  {
    printf("\nLinked list is empty!\n");
    return;
  }

  struct node *temp;
  temp = start;
  int count = 1;
  while(temp != NULL)
  {
    printf("Node: %d\tData: %d\n",count, temp -> data);
    temp = temp -> link;
  }
}

//FUNCTION TO INSERT NODES IN ASCENDING ORDER
void insert(struct node **start, int value)
{
  struct node *temp, *temp2, *newnode;
  temp = *start;
  newnode = (struct node*) malloc(sizeof(struct node));
  newnode -> data = value;

  //linked list is empty
  if(*start == NULL)
  {
    newnode -> link = *start;
    *start = newnode;
  }
  //linked list is not empty
  else
  {
    if(temp -> data > newnode -> data)
    {
      newnode -> link = temp;
      *start = newnode;
    }
    else
    {
      while(temp && temp -> data < newnode -> data)
      {
        temp2 = temp;
        temp = temp -> link;
      }
      newnode -> link = temp2 -> link;
      temp2 -> link = newnode;
    }
  }
}

//MAIN FUNCTION
int main()
{
  int value, choice;
  struct node * start;
  start = NULL;

  while(1)
  {
    printf("Choose:-\n\n");
    printf("1. Insert\n\t2. Traverse\n\t3. Exit\n\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      printf("\nEnter element: ");
      scanf("%d",&value);
      insert(&start,value);
      break;

      case 2:
      traverse(start);
      break;

      case 4:
      printf("\nExiting program!\n");
      exit(0);

      default:
      printf("\nInvalid input!\n");
      break;
    }
  }
  return 0;
}
