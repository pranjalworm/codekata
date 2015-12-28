//program to implement doubly linked list
//status: executed successfully


#include<stdio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *prev;
  struct node *next;
};


//INSERT AT BEGINNING
void insert_beg(struct node **start, int value)
{
  struct node *temp, *newnode;
  newnode = (struct node*) malloc(sizeof(struct node));
  newnode -> data = value;

  if(*start == NULL)
  {
    newnode -> prev = *start;
  }
  else
  {
    temp = *start;
    newnode -> prev = NULL;
    temp -> prev = newnode;
  }

  newnode -> next = *start;
  *start = newnode;
}


//DELETE FROM BEGINNING
void delete_beg(struct node **start)
{
  if(*start == NULL)
  {
    printf("\nLinked List is Empty!\n");
    return;
  }

  struct node *temp;
  temp = *start;

  if(temp -> next == NULL)
  {
    free(temp);
    *start = NULL;
    return;
  }

  (temp -> next) -> prev = temp -> prev;
  *start = temp -> next;
  free(temp);
}


//INSERT AT END
void insert_end(struct node **start, int value)
{
  struct node *ptr, *newnode;
  newnode = (struct node*) malloc(sizeof(struct node));
  newnode -> data = value;

  if(*start == NULL)
  {
    newnode -> prev = NULL;
    *start = newnode;
  }
  else
  {
    ptr = *start;
    while(ptr -> next != NULL)
    {
      ptr = ptr -> next;
    }
    ptr -> next = newnode;
    newnode -> prev = ptr;
  }

  newnode -> next = NULL;
}


//DELETE AT END
void delete_end(struct node **start)
{
  struct node *ptr, *ptr2;
  ptr = *start;

  if(*start == NULL)
  {
    printf("\nLinked List is Empty!\n");
  }
  else if(ptr -> next == NULL)
  {
    ptr = *start;
    free(ptr);
    *start = NULL;
  }
  else
  {
    while((ptr -> next) -> next != NULL)
    {
      ptr = ptr -> next;
    }

    ptr2 = ptr -> next;
    free(ptr2);
    ptr -> next = NULL;
  }
}


//INSERT MIDDLE
void insert_mid(struct node **start, int pos, int value)
{
  struct node *newnode, *ptr;
  newnode = (struct node*) malloc(sizeof(struct node));
  newnode -> data = value;

  int count = 1;

  //in case linked list is empty
  if(*start == NULL)
  {
    //in case desired position is first
    if(pos == 1)
    {
      newnode -> prev = *start;
      newnode -> next = *start;
      *start = newnode;
    }
    else
    {
      printf("\nLinked List is Empty! Element cannot be inserted at desired position!\n");
      return;
    }
  }
  else
  {
    ptr = *start;

    //positon is 1
    if(pos == 1)
    {
      newnode -> next = ptr;
      newnode -> prev = ptr -> prev;
      ptr -> prev = newnode;
      *start = newnode;
    }
    else
    {
      while(count != pos-1 && ptr -> next != NULL)
      {
        ptr = ptr -> next;
        count++;
      }
      newnode -> next = ptr -> next;
      newnode -> prev = ptr;
      if(ptr -> next != NULL)
      {
        (ptr -> next) -> prev = newnode;
      }
      ptr -> next = newnode;
    }
  }
}

//DELETE MIDDLE
void delete_mid(struct node **start, int pos)
{
  if(*start == NULL)
  {
    printf("\nLinked list is empty!\n");
    return;
  }

  struct node *ptr;
  int count = 1;
  ptr = *start;

  if(pos == 1) //for deletion of first element
  {
    if(ptr -> next == NULL) //single element present in DLL
    {
      *start = NULL;
    }
    else
    {
      *start = ptr -> next;
      (ptr -> next) -> prev = ptr -> prev;
    }
  }
  else
  {
    while(count != pos && ptr -> next != NULL)
    {
      ptr = ptr -> next;
      count++;
    }
    if(count < pos)
    {
        printf("\nDLL doesn't contain node at that position!\n");
        return;
    }

    if(count != pos)
    {
      (ptr -> next) -> prev = ptr -> prev;
    }

    (ptr -> prev) -> next = ptr -> next;
  }
  free(ptr);
}

//TRAVERSE IN BOTH DIRECTIONS
void traverse(struct node *start)
{
  if(start == NULL)
  {
    printf("\nLinked List is Empty!\n");
    return;
  }

  struct node *ptr;
  ptr = start;
  int count = 1;

  printf("\nPrinting forwards:\t");
  while(ptr -> next != NULL)
  {
    printf("Node: %d  Data: %d\t->\t",count, ptr -> data);
    ptr = ptr -> next;
    count++;
  }
  printf("Node: %d  Data: %d",count, ptr -> data);


  printf("\nPrinting backwards:\t");
  while(ptr != NULL)
  {
    printf("Node: %d  Data: %d\t->\t",count, ptr -> data);
    ptr = ptr -> prev;
    count--;
  }
}

//MAIN FUNCTION
int main()
{
  int value, choice, pos;

  struct node *start;
  start = NULL;

  while(1)
  {
    printf("\nChoose:-\n\n\t1. Insert at Beginning\n\t2. Traverse\n\t3. Delete from Beginning\n\t4. Insert at End\n\t5. Delete at End\n\t6. Insert Middle\n\t7. Delete Middle\n\t10. Exit\n\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      printf("Enter element: ");
      scanf("%d",&value);
      insert_beg(&start, value);
      break;

      case 2:
      traverse(start);
      break;

      case 3:
      delete_beg(&start);
      break;

      case 4:
      printf("Enter element: ");
      scanf("%d",&value);
      insert_end(&start, value);
      break;

      case 5:
      delete_end(&start);
      break;

      case 6:
      printf("Enter pos & element: ");
      scanf("%d %d",&pos,&value);
      insert_mid(&start, pos, value);
      break;

      case 7:
      printf("Enter pos: ");
      scanf("%d",&pos);
      delete_mid(&start, pos);
      break;

      case 10:
      printf("\nExiting Program...\n");
      exit(0);
      break;

      default:
      printf("\nInvalid Input!\n");
      break;
    }
  }
  return 0;
}
