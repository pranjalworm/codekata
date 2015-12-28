//BASIC PROGRAM: program to insert a node in bst tree
//status: executed successfully, but doubts in insert function [return node statement]

#include<stdio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};


//FUNCTION FOR INORDER TRAVERSAL
void inorder(struct node *root)
{
  if(root -> left != NULL)
  {
    inorder(root -> left);
  }

  printf("%d\t", root -> data);

  if(root -> right != NULL)
  {
    inorder(root -> right);
  }
}

//FUNCITON TO CREATE A NEWNODE WITH GIVEN VALUE
struct node * createnode(int value)
{
  struct node *newnode;
  newnode = (struct node*) malloc(sizeof(struct node));

  newnode -> data = value;
  newnode -> left = newnode -> right = NULL;

  return newnode;
}


//FUNCTION TO INSERT NODE IN BST
struct node * insert(struct node *node, int value)
{
  if(node == NULL)
  {
    return createnode(value);
  }

  if(node -> data > value)
  {
    node -> left = insert(node -> left, value);
  }
  else if(node -> data < value)
  {
    node -> right = insert(node -> right, value);
  }

  return node;
}


//MAIN FUNCTION
int main()
{
  int value, choice;
  struct node *root = NULL;

  root = insert(root, 3);

  while(1)
  {
    printf("\nChoose: 1. Enter value\t2. Traverse\t3. Exit\n\n");
    scanf("%d",&choice);
    switch (choice)
    {
      case 1:
      printf("Enter value: ");
      scanf("%d",&value);
      insert(root, value);
      break;

      case 2:
      inorder(root);
      break;

      case 3:
      printf("Exiting program...");
      exit(0);
      break;

      default:
      printf("Invalid Input!");
    }
  }

  return 0;
}
