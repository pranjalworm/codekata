//program to convert a binary tree into its mirror tree
//status: executed successfully


#include<stdio.h>
#include<malloc.h>

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


//FUNCTION TO CONVERT A TREE INTO ITS MIRROR TREE
void mirror(struct node *node)
{
  if(node == NULL)
  {
    return;
  }

  mirror(node -> left);
  mirror(node -> right);

  struct node *temp;
  temp = node -> left;
  node -> left = node -> right;
  node -> right = temp;

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

  printf("Before: ");
  inorder(root);

  mirror(root);

  printf("\n\nAfter: ");
  inorder(root);

  return 0;
}
