//Given two numbers represented by two lists, write a function that returns sum list. The sum list is list representation of addition of two input numbers.

/*
Input:
  First List: 5->6->3  // represents number 365
  Second List: 8->4->2 //  represents number 248
Output
  Resultant list: 3->1->6  // represents number 613
*/

#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *link;
};


//INSERTING ELEMENTS
void insert(struct node **start, int value)
{
    struct node *newnode;
    newnode = (struct node*) malloc(sizeof(struct node));
    newnode -> data = value;
    newnode -> link = *start;
    *start =  newnode;
}


//TRAVERSING LINKED LIST
void traverse(struct node *start)
{
  if(start == NULL)
  {
    printf("\nLinked List is Empty!\n");
    return;
  }
    struct node *p;
    p = start;

    printf("\n");

    while(p != NULL)
    {
        printf("%d\t",p -> data);
        p = p -> link;
    }

    printf("\n");
}

//FUNCTION TO SUM ONE LINKED LIST
int sumll(struct node *start)
{
  if(start == NULL)
  {
    printf("\nLinked List is empty!\n");
    return;
  }

  struct node *ptr;
  ptr = start;

  int i = 1,sum = 0;

  while(ptr != NULL)
  {
    sum = ptr -> data * i + sum;
    i = i * 10;
  }

  return sum;
}

//FUNCTION TO SUM BOTH LISTS
void sumboth(struct node *start1, struct node *start2)
{
  printf("\nSum of both: %d\n", sumll(start1) + sumll(start2));
}


int main()
{
  int ln, value, op;
  struct node *start1, *start2, *temp_start;
  start1 = NULL;
  start2 = NULL;

  while(1)
  {
    printf("\nChoose Linked List:\t1\t2\n");
    scanf("%d",&ln);
    printf("\nChoose Operation:\n\n\t1. Insert\n\t2. Traverse\n\t3. Sum LinkedList1\n\t4. Sum LinkedList2\n\t5. Sum Both\n\n");
    scanf("%d",&op);

    if(ln == 1)
      temp_start = start1;
    else
      temp_start = start2;

    switch(op)
    {
      case 1:
      printf("\nEnter element: ");
      scanf("%d",&value);
      insert(&temp_start, value);
      break;

      case 2:
      traverse(temp_start);
      break;

      case 3:
      case 4:
      printf("\nSum: %d\n", sumll(temp_start));
      break;

      case 5:
      sumboth(start1, start2);
      break;

      case 10:
      printf("\nExiting Program!\n");
      exit(0);
      break;

      default:
      printf("\nInvalid Input!\n");
    }
  }
}
