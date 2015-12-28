//program to delete a tree
//status: executed successfully

#include<stdio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *left, *right;
};

struct node * newnode(int value)
{
  struct node *node = (struct node*) malloc(sizeof(struct node));
  node -> data = value;
  node -> left = NULL;
  node -> right = NULL;

  return node;
}

void postorder(struct node *node)
{
  if(node == NULL)
  {
    return;
  }
  if(node -> left != NULL)
  {
    postorder(node -> left);
  }

  if(node -> right != NULL)
  {
    postorder(node -> right);
  }

  printf("%d\t", node -> data);
}


//FUNCTION TO DELETE TREE
void delete(struct node *node)
{
  if(node == NULL)
  {
    printf("Tree is empty!");
    return;
  }

  if(node -> left != NULL)
  {
    delete(node -> left);
  }

  if(node -> right != NULL)
  {
    delete(node -> right);
  }

  free(node);
}

int main()
{
  struct node *root;

  root = newnode(5);
  root -> left = newnode(2);
  root ->  right = newnode(6);
  root -> left -> left = newnode(-1);
  root -> right -> right = newnode(7);
  root -> right -> right -> right = newnode(8);
  root -> right -> right -> right -> right = newnode(9);
  root -> right -> right -> right -> right -> right = newnode(10);
  root -> left -> right  = newnode(3);
  root -> left -> right -> right  = newnode(4);
  root -> left -> left -> left = newnode(-2);
  root -> left -> left -> right  = newnode(0);
  root -> left -> left -> right -> right  = newnode(1);

  printf("\n\nPostorder: ");
  postorder(root);

  printf("Deletion...\n");
  delete(root);

  root = NULL;

  delete(root);

  return 0;
}
