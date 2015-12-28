//program to find the size of a tree
//status: executed successfully

#include<stdio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *left, *right;
};

struct node * createnode(int value)
{
  struct node *newnode;
  newnode = (struct node*) malloc(sizeof(struct node));

  newnode -> data = value;
  newnode -> left = NULL;
  newnode -> right = NULL;

  return newnode;
}

int size(struct node *node)
{
  if(node == NULL)
  {
    return 0;
  }

  return (size(node -> left) + 1 + size(node -> right));
}

int main()
{
  struct node *root;

  root = createnode(3);
  root -> left = createnode(1);
  root ->  right = createnode(4);
  root -> left -> left = createnode(0);
  root -> left -> right = createnode(2);
  root -> right -> right = createnode(5);
  root -> right -> right -> right = createnode(6);

  printf("Size of tree: %d",size(root));
  return 0;
}
