//program to perform (non-basic) operations on linked list

//header files
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *link;
};

struct node *start = NULL;

//FUNCTION TO INSERT VALUES
struct node * insert(struct node *start, int value)
{
  struct node *newnode, *temp;
  newnode = (struct node*) malloc(sizeof(struct node));
  newnode -> data = value;
  newnode -> link = start;
  start = newnode;
}


//FUNCTION TO TRAVERSE
void traverse(struct node *start)
{
  struct node *temp;
  int count = 0;
  if(start == NULL)
  {
    printf("\nLinked list is empty!\n");
    return;
  }

  temp = start;
  while(temp != NULL)
  {
    count++;
    printf("Node: %d\tData: %d\n",count, temp->data);
    temp = temp -> link;
  }
}


//FUNCTION TO COUNT NODES
int count(struct node *start)
{
  if(start == NULL)
  {
    return 0;
  }
  else
    return 1 + count(start->link);
}


//FUNCTION TO SEARCH
void search(struct node *start, int value)
{
  if(start == NULL)
  {
    printf("\nElement not found!\n");
    return;
  }
  else
  {
    if(start -> data == value)
    {
      printf("\nElement found: %d\n", start->data);
      return;
    }
    else
    {
      search(start->link,value);
    }
  }
}


//FUNCTION TO SWAP NODES
struct node * swap(struct node *start, int a, int b)
{
  if(a == b)
  {
    printf("\nElements are equal! No need to swap!\n");
    return;
  }

  struct node *ap, *bp, *an, *bn, *temp;
  ap = NULL;
  bp = NULL;

  //printing before swapping sequence
  temp = start;
  printf("Before:\n");
  while(temp != NULL)
  {
    printf("%d\t",temp->data);
    temp = temp -> link;
  }

  an = start;
  bn = start;

  //searching for 'a'
  while(an -> data != a)
  {
    ap = an;
    an = an -> link;
    if(an == NULL)
    {
      printf("\nNode with element not found! Swapping not possible!\n");
      return;
    }

  }

  //searching for 'b'
  while(bn -> data != b)
  {
    bp = bn;
    bn = bn -> link;
    if(bn == NULL)
    {
      printf("\nNode with element not found! Swapping not possible!\n");
      return;
    }
  }

  //SWAPPING NODES
  //if bn is first node
  if(bp == NULL)
  {
    start = an;
    ap -> link = bn;
  }
  //if an is first node
  else if(ap == NULL)
  {
    start = bn;
    bp -> link = an;
  }
  //if neither is first node
  else
  {
    ap -> link = bn;
    bp -> link = an;
  }

  temp = an -> link;
  an -> link = bn -> link;
  bn -> link = temp;

  //printing before swapping sequence
  temp = start;
  printf("\nAfter:\n");
  while(temp != NULL)
  {
    printf("%d\t",temp->data);
    temp = temp -> link;
  }
  return start;
}


//PRINT MIDDLE NODE OF LINKED LIST

//solution #1
void middle1(struct node *start)
{
  struct node *ptr1, *ptr2;
  ptr1 = start;
  ptr2 = start;

  while(ptr2 -> link != NULL && (ptr2 -> link) -> link != NULL)
  {
    ptr1 = ptr1 -> link;
    ptr2 = (ptr2 -> link) -> link;
  }
  printf("\nMiddle Element: %d\n",ptr1 -> data);
}

//solution #2
void middle2(struct node *start)
{
  struct node *ptr1, *ptr2;
  ptr1 = start;
  ptr2 = start;

  int count = 0;
  while(ptr1 != NULL)
  {
    if(count & 1)
    {
      ptr2 = ptr2 -> link;
    }
    count++;
    ptr1 = ptr1 -> link;
  }
  printf("\nMiddle Element: %d\n",ptr2 -> data);
}


//MAKE LAST NODE FIRST NODE
struct node *last_first(struct node *start)
{
  if(start == NULL)
  {
    printf("\nLinked List is Empty!\n");
    return;
  }
  else if(start -> link == NULL)
  {
    printf("\nOnly one element is present!\n");
    return;
  }
  else
  {
    struct node *temp, *temp2;
    temp = start;
    while(temp -> link != NULL)
    {
      temp2 = temp;
      temp = temp -> link;
    }

    temp2 -> link = NULL;
    temp -> link = start;
    start = temp;
  }
}

//MAIN FUNCTION
int main()
{
  int choice, value, num, a, b;
  while(1)
  {
    printf("Choose:-\n\n");
    printf("\t1. Insert\n\t2. Count (recursively)\n\t3. Traverse\n\t4. Search (recursively)\n\t5. Swap\n\t6. Middle1\n\t7. Middle2\n\t8. Last as First\n\t9. Exit\n\n");
    scanf("%d",&choice);

    switch (choice)
    {
      case 1:
      printf("Enter value: ");
      scanf("%d",&value);
      start = insert(start, value);
      break;

      case 2:
      num = count(start);
      printf("\nNode: %d\n",num);
      break;

      case 3:
      traverse(start);
      break;

      case 4:
      printf("Enter element to search: ");
      scanf("%d",&value);
      search(start, value);
      break;

      case 5:
      printf("Enter data of nodes to swap: ");
      scanf("%d %d",&a, &b);
      start = swap(start,a,b);
      break;

      case 6:
      middle1(start);
      break;

      case 7:
      middle2(start);
      break;

      case 8:
      start = last_first(start);
      break;

      case 9:
      printf("\nExiting Program!\n");
      exit(0);
      break;

      default:
      printf("\nInvalid Input!\n");
      break;
    }
  }
  return 0;
}
