//BASIC PROGRAM: program to create a binary tree and traverse it
//status: executed successfully

#include<stdio.h>
#include<malloc.h>

//DATA TYPE OF A NODE
struct node
{
  int data;
  struct node *left;
  struct node *right;
};


//FUNCTION TO CREATE A NEW NODE
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


//FUNCTION FOR PREORDER TRAVERSAL
void preorder(struct node *root)
{
  printf("%d\t", root -> data);

  if(root -> left != NULL)
  {
    preorder(root -> left);
  }

  if(root -> right != NULL)
  {
    preorder(root -> right);
  }
}


//FUNCTION FOR POSTORDER TRAVERSAL
void postorder(struct node *root)
{
  if(root -> left != NULL)
  {
    postorder(root -> left);
  }

  if(root -> right != NULL)
  {
    postorder(root -> right);
  }

  printf("%d\t", root -> data);
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

  printf("\n");

  preorder(root);

  printf("\n");

  postorder(root);

  return 0;
}
