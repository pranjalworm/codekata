//implement a queue
//status: some bugs

#include<stdio.h>
#include<stdlib.h>

struct queue
{
  int data[10];
  int front;
  int rear;
};

void initqueue(struct queue *q)
{
  q -> rear = -1;
  q -> front = -1;
}

void enqueue(struct queue *q, int value)
{
  if(q -> rear == 10)
  {
    printf("\nQueue is full!\n");
    return;
  }
  q -> rear++;
  q -> data [q -> rear] = value;
}

void dequeue(struct queue *q)
{
  if(q -> front == q -> rear)
  {
    printf("\nQueue is empty!\n");
    return;
  }
  q -> front++;
  printf("\nDeleted data: %d\n", q -> data[q -> front]);

}

int main()
{
  struct queue q;
  initqueue(&q);

  int choice, value;
  while(1)
  {
    printf("Choose:-\n\n1. Enqueue\t2. Dequeue\t3. Exit\n\n");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:
      printf("\nEnter element: ");
      scanf("%d",&value);
      enqueue(&q, value);
      break;

      case 2:
      dequeue(&q);
      break;

      case 3:
      printf("Exiting program...!");
      exit(0);
      break;

      default:
      printf("invalid input");
    }
  }
  return 0;
}
