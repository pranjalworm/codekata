//Check for Children Sum Property in a Binary Tree.
//status: in progress

#include<stdio.h>
#include<malloc.h>

//DATA TYPE OF A NODE
struct node
{
  int data;
  struct node *left, *right;
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

int sum(struct node *left, struct node *right)
{
  if(left != NULL && right != NULL)
  {
    return left -> data + right -> data;
  }
  else if(left == NULL)
  {
    return right -> data;
  }
  else
  {
    return left -> data;
  }
}

int check_childsum(struct node *node)
{
  if(node == NULL || (node -> data != sum(node -> left, node -> right)) || (node -> left == NULL && node -> right == NULL))
  {
    return 0;
  }
  else
  {
    check_childsum(node -> left);
    check_childsum(node -> right);
  }

  return 1;
}

//MAIN FUNCTION
int main()
{
  struct node *root;

  root = createnode(10);
  root -> left = createnode(8);
  root ->  right = createnode(2);
  root -> left -> left = createnode(3);
  root -> left -> right = createnode(5);
  root -> right -> right = createnode(2);

  inorder(root);

  if(check_childsum(root))
  {
    printf("\nTree follows child sum Property\n");
    exit(0);
  }

  printf("\nTree does not follow child sum Property\n");

  return 0;
}
