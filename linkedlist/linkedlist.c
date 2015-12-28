//program to perform operations on linked list
//status: in progress

//header files
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *link;
};


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

  while(temp->link != NULL)
  {
    printf("Node: %d\tData: %d\n",count,temp->data);
    temp = temp->link;
    count++;
  }

  printf("Node: %d\tData: %d\n",count,temp->data);

}


//FUNCTION TO INSERT AT THE BEGINNING OF THE LINKED LIST
void insert_beg(struct node **start, int value)
{
  struct node *newnode;
  newnode = (struct node*) malloc(sizeof(struct node));
  newnode->data = value;
  newnode->link = *start;
  *start = newnode;
}


//FUNCTION TO DELETE FROM BEGINNING OF THE LINKED LIST
void delete_beg(struct node **start)
{
  if(*start == NULL)
  {
    printf("\n\nLinked List Empty!\n\n");
    return;
  }
  struct node *temp;
  temp = *start;
  *start = temp->link;
  printf("Deleted value: %d",temp->data);
  free(temp);
}


//FUNCTION TO INSERT AT END OF LINKED LIST
void insert_end(struct node **start, int value)
{
  printf("start");
  struct node *newnode,*temp;
  if(*start == NULL)
  {
    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = value;
    newnode->link = NULL;
    *start = newnode;
  }
  else
  {
    temp = *start;
    while(temp->link != NULL)
    {
      temp = temp->link;
    }
    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = value;
    newnode->link = NULL;
    temp -> link = newnode;
  }
}

//FUNCTION TO DELETE FROM THE END OF LINKED LIST
void delete_end(struct node **start)
{
  struct node *temp,*temp2;
  int count = 1;

  temp = *start;

  if(*start == NULL)
  {
    printf("\nLinked List is Empty!\n");
    return;
  }

  while(temp->link != NULL)
  {
    temp2 = temp;
    temp = temp->link;
    count++;
  }

  printf("Deleted value: %d\n",temp->data);
  free(temp);
  if(count == 1)
  {
    *start = NULL;
  }
  else
  {
    temp2->link = NULL;
  }
}


//FUNCTION TO INSERT NODE AT SPECIFIC POSTION
//BUG: pos is equal to pos(last node + 1)
void insert_at(struct node **start, int pos, int value)
{
  struct node *temp, *newnode;
  int count = 1;

  if(*start == NULL)
  {
    if(pos == 1)
    {
      newnode = (struct node*) malloc(sizeof(struct node));
      newnode->link = *start;
      newnode->data = value;
      *start = newnode;
    }
    else
    {
      printf("\nLinked list is empty! Node cannot be inserted at desired position!\n");
    }
  }
  else
  {
    temp = *start;

    while(count != pos-1 )
    {
      temp = temp -> link;
      count++;
    }

    newnode->link = temp->link;
    temp->link = newnode;
    newnode->data = value;
  }

}


//FUNCTION TO DELETE NODE AT SPECIFIC POSTION
void delete_at(struct node **start, int pos)
{
  if(*start == NULL)
  {
    printf("\nLinked List is Empty!\n");
  }
  else
  {
    struct node *temp;
    temp = *start;
    if(pos == 1)
    {
      *start = temp->link;
      free(temp);
    }
    else
    {
      int count = 1;
      struct node *temp2;
      while(count != pos && temp->link != NULL)
      {
        temp2 = temp;
        temp = temp->link;
        count++;
      }
      if(count < pos)
      {
        printf("\nNode at position %d doesn't exist!\n",pos);
        return;
      }
      temp2->link = temp->link;
      free(temp);
    }
  }
}


//FUNCTION TO REVERSE LINKED LIST
void reverse(struct node **start)
{
  if(*start == NULL)
  {
    printf("\nLinked List is Empty!\n");
    return;
  }

  struct node *temp1, *temp2, *temp3;

  temp3 = *start;
  temp2 = NULL;
  while(temp3 != NULL)
  {
    temp1 = temp2;
    temp2 = temp3;
    temp3 = temp3->link;
    temp2->link = temp1;
  }
  *start = temp2;
}


//FUNCTION TO SEARCH ELEMENT IN LINKED LIST
void search(struct node *start, int value)
{
  if(start == NULL)
  {
    printf("\nLinked List is Empty!\n");
    return;
  }
  struct node *temp;
  temp = start;

  int count = 1;

  while(temp != NULL && temp->data != value)
  {
    temp = temp->link;
    count++;
  }
  if(temp == NULL)
    printf("\nElement not found!\n");
  else
    printf("\nElement: %d found at Node: %d\n",value, count);
}


//LENGTH OF LINKED LIST
void length(struct node *start)
{
  if(start == NULL)
  {
    printf("\nLength: 0\n");
    return;
  }
  struct node *temp;
  temp = start;
  int count = 1;
  while(temp != NULL)
  {
    temp = temp->link;
    count++;
  }
  printf("\nLength: %d\n",count-1);
}


//MAIN FUNCTION
int main()
{
  int choice, value, value_del,pos;
  struct node *start;
  start = NULL;

  while(1)
  {
    printf("\nChoose:\n\t1. Insert at Beginning\n\t2. Delete from Beginning\n\t3. Traverse\n\t4. Insert at End\n\t5. Delete from End\n\t6. Insert At\n\t7. Delete At\n\t8. Reverse\n\t9. Search\n\t10. Length\n\t11. Exit\n\n");
    scanf("%d",&choice);

    switch(choice)
    {
      //INSERT AT BEGINNING
      case 1:
      printf("Enter value: ");
      scanf("%d",&value);
      insert_beg(&start, value);
      break;

      //DELETE AT BEGINNING
      case 2:
      delete_beg(&start);
      break;

      //TRAVERSE
      case 3:
      traverse(start);
      break;

      //INSERT AT END
      case 4:
      printf("Enter value: ");
      scanf("%d",&value);
      insert_end(&start, value);
      break;

      //DELETE AT END
      case 5:
      delete_end(&start);
      break;

      //INSERT AT POSITION
      case 6:
      printf("Enter pos & value: ");
      scanf("%d %d",&pos,&value);
      insert_at(&start, pos, value);
      break;

      //DELETE AT POSITION
      case 7:
      printf("Enter pos: ");
      scanf("%d",&pos);
      delete_at(&start, pos);
      break;

      //REVERSE LINKED LIST
      case 8:
      reverse(&start);
      break;

      //SEARCH ELEMENT
      case 9:
      printf("Enter element to search: ");
      scanf("%d",&value);
      search(start, value);
      break;

      //LENGTH OF LINKED LIST
      case 10:
      length(start);
      break;

      //EXIT PROGRAM
      case 11:
      printf("\n\nExiting program!\n\n");
      exit(0);
      break;

      default:
      printf("\n\n!!! Invalid choice entered !!!\n\n");
      break;
    }
  }
}
