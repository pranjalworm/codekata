//inorder traversal in a binary tree
//status: in progress, problem with creating the threaded tree

#include<stdio.h>
#include<malloc.h>

//DATATYPE OF A NODE
struct node
{
  int data;
  struct node *left, *right;
  int flag;
};

//FUNCTION TO CREATE A NEW NODE
struct node *createnode(int value)
{
  struct node *newnode;
  newnode = (struct node*) malloc(sizeof(struct node));
  newnode -> data = value;
  newnode -> left = NULL;
  newnode -> right = NULL;
  return newnode;
}

//FUNCTION FOR INORDER TRAVERSAL
void inorder(struct node *node)
{
  if(node -> left != NULL)
  {
     inorder(node -> left);
  }

  printf("%d\t",node -> data);

  if(node -> right != NULL)
  {
    inorder(node -> right);
  }
}

//FUNCTION TO FIND THE LEFT MOST NODE FROM A GIVEN NODE
struct node * leftmost(struct node *node)
{
  if(node == NULL)
  {
    return NULL;
  }

  while(node -> left != NULL)
  {
    node = node -> left;
  }

  return node;
}

//FUNCTION FOR INORDER TRAVERSAL IN THREADED BINARY TREE
void inorder_threaded(struct node *node)
{
  if(node == NULL)
  {
    printf("Tree is empty!");
    return;
  }

  node = leftmost(node);

  while(node != NULL)
  {
    printf("%d\t", node -> data);

    if(node -> flag == 1)
    {
      node = node -> right;
    }

    else
    {
      node = leftmost(node);
    }
  }
}

//MAIN FUNCTION
int main()
{
  struct node *root;

  //creating a threaded binary search tree
  root = createnode(3);
  root -> flag = 0;

  root -> left = createnode(1);
  root -> left -> flag = 0;

  root ->  right = createnode(5);
  root -> right -> flag = 0;

  root -> left -> left = createnode(0);
  root -> left -> left -> flag = 1;
  root -> left -> left -> right = root -> left;

  root -> left -> right = createnode(2);
  root -> left -> right -> flag = 1;
  root -> left -> right -> right = root;

  root -> right -> right = createnode(6);
  root -> right -> right -> flag = 0;

  root -> right -> left = createnode(4);
  root -> right -> left -> flag = 1;
  root -> right -> left -> right = root -> right;

  inorder_threaded(root);


  return 0;
}
