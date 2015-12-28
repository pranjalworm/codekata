//program to determine if two trees are identical or not
//status : executed successfully

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


//FUNCTION TO DETERMINE IF TWO TREES ARE IDENTICAL OR NOT
int compare(struct node *node1, struct node *node2)
{
  if(node1 == NULL && node2 == NULL)
  {
    return 1;
  }

  if(node1 != NULL && node2 != NULL)
  {
    return (node1 -> data == node2 -> data && compare(node1 -> left, node2 -> left) && compare(node1 -> right, node2 -> right));
  }

  return 0;
}


//MAIN FUNCTION
int main()
{
  struct node *root1, *root2;

  root1 = createnode(3);
  root1 -> left = createnode(1);
  root1 ->  right = createnode(4);
  root1 -> left -> left = createnode(0);
  root1 -> left -> right = createnode(2);
  root1 -> right -> right = createnode(5);
  root1 -> right -> right -> right = createnode(7);

  printf("First tree: ");
  inorder(root1);

  root2 = createnode(3);
  root2 -> left = createnode(1);
  root2 ->  right = createnode(4);
  root2 -> left -> left = createnode(0);
  root2 -> left -> right = createnode(2);
  root2 -> right -> right = createnode(5);
  root2 -> right -> right -> right = createnode(6);

  printf("\nSecond tree: ");
  inorder(root2);

  if(compare(root1, root2))
  {
    printf("\nTrees are identical!\n");
    exit(0);
  }
  printf("\nTrees are not identical!\n");

  return 0;
}
