//find minimum value in bst
//status: executed successfully

#include<stdio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
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

void minimum(struct node *node)
{
  if(node -> left == NULL)
  {
    printf("min: %d", node -> data);
  }
  else
  {
    minimum(node -> left);
  }
}

//MAIN FUNCTION
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

  inorder(root);
  minimum(root);
  return 0;
}
