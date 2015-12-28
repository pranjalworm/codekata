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

//PAIR WISE SWAPPING OF NODES USING LINKS
void pairswaplinks(struct node **start)
{
    struct node *p1, *p2, *pv;

    pv = *start;
    p1 = *start;
    p2 = p1 -> link;

    while(p2 != NULL)
    {
        p1 -> link = p2 -> link;
        p2 -> link = p1;

        if(pv == p1) //CONFIRM THIS
        {
            *start = p2;
        }
        else
        {
            pv -> link = p2;
        }
        pv = p1;
        p1 = p1 -> link;
        if(p1 != NULL)
        {
            p2 = p1 -> link;
        }
        else break;
    }
}

//PAIR WISE SWAPPING OF NODE ELEMENTS WITHOUT USING LINKS
void pairswapnolinks(struct node *start)
{
  struct node *p1, *p2;
  p1 = start;
  p2 = p1 -> link;

  int temp;

  while(p2 != NULL)
  {
    temp = p1 -> data;
    p1 -> data = p2 -> data;
    p2 -> data = temp;

    p1 = p2 -> link;
    if(p1 == NULL)
    {
      break;
    }
    p2 = p1 -> link;
  }
}


//REMOVING DUPLICATE NODES IN UNSORTED LINKED LIST
void removedup(struct node *start)
{
    struct node *p1, *p2, *dup, *pv;

    p1 = start;

    while(p1 -> link != NULL)
    {
        p2 = p1 -> link;
        pv = p1;

        while(p2 != NULL)
        {
            if(p1 -> data == p2 -> data)
            {
                pv -> link = p2 -> link;
                dup = p2;
                free(dup);
                continue;
            }

            pv = p2;
            p2 = p2 -> link;
        }
        p1 = p1 -> link;
    }
}


//DELETE ALTERNATE NODES
void deletealternate(struct node *start)
{
    struct node *p1, *pv, *dup;
    p1 = start;

    int count = 1;

    while(p1 != NULL)
    {
        if(count % 2 == 0)
        {
            pv -> link = p1 -> link;
            dup = p1;
            free(dup);
        }
        else
        {
            pv = p1;
        }

        p1 = p1 -> link;
        count++;
    }
}


//REVERSE LINKED LIST
void reverse(struct node **start)
{
  if(*start == NULL)
  {
    printf("\nLinked List is Empty\n");
    return;
  }

  struct node *p1, *p2, *temp;
  p1 = NULL;
  p2 = *start;

  while(p2 != NULL)
  {
    temp = p2 -> link;
    p2 -> link = p1;
    p1 = p2;
    p2 = temp;
  }

  *start = p1;
}


//POINT TO NEXT HIGHER VALUE WITH ARBITRARY POINTER
void nexthigher(struct node *ptr)
{

}


//MAIN FUNCTION
int main()
{
    struct node *start;
    start = NULL;

    int choice, value;

    while(1)
    {
        printf("Choose:-\n\n\t1. Insert\n\t2. Traverse\n\t3. Pair Swap (links)\n\t4. Pair Swap (no links)\n\t5. Next Higher\n\t6. Delete Alternate\n\t7. Remove Duplicate\n\t8. Reverse\n\t10. Exit\n\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("Enter element: ");
            scanf("%d",&value);
            insert(&start, value);
            break;

            case 2:
            traverse(start);
            break;

            case 3:
            pairswaplinks(&start);
            break;

            case 4:
            pairswapnolinks(start);
            break;

            case 5:
            nexthigher(start);
            break;

            case 6:
            deletealternate(start);
            break;

            case 7:
            removedup(start);
            break;

            case 8:
            reverse(&start);
            break;

            case 10:
            printf("\nExiting program!\n");
            exit(0);
            break;

            default:
            printf("\nInvalid Input!\n");
        }
    }
    return 0;
}
