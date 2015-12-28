//program to implement a queue using an array
//status:

#include<stdio.h>

int main()
{
  int arr[10];
  int front, rear;

  while(1)
  {
    printf("Choose: 1. Enqueue\t2. Dequeue\t3. Exit\n\n");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:
      printf("Enter element: ");
      scanf("%d",&value);
      enqueue(value);
      break;

      case 2:
      dequeue();
      break;

      case 3:
      printf("Exiting program...");
      exit(0);
      break;

      default:
      printf("Invalid input!");
    }    
  }
  return 0;
}
