//program to check if a given binary tree is bst or not
//status: in progress

#include<stdio.h>
#include<malloc.h>

int min = -1;

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


int check(struct node *node)
{
  if(node -> left != NULL)
  {
    check(node -> left);
  }

  if(node -> data > min)
  {
    min = node -> data;
  }
  else
  {
    return -1;
  }

  if(node -> right != NULL)
  {
    check(node -> right);
  }
}

//MAIN FUNCTION
int main()
{
  int flag;
  struct node *root;

  root = createnode(3);
  root -> left = createnode(1);
  root ->  right = createnode(4);
  root -> left -> left = createnode(0);
  root -> left -> right = createnode(2);
  root -> right -> right = createnode(5);
  root -> right -> right -> right = createnode(6);

  inorder(root);
  flag = check(root);
  if(flag == -1)
  {
    printf("\nTree is not binary search tree!\n");
  }
  else
  {
    printf("flag: %d", flag);
    printf("Tree is binary tree");
  }
  return 0;
}
