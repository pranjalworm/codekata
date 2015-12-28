//Given a binary tree, print out all of its root-to-leaf paths one per line.
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

int seq[10];
int pos;

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


void printrootleafpath(struct node *node)
{
  if(node -> left == NULL && node -> right == NULL)
  {
    int i;
    for(i = 0; i < pos; i++)
    {
      printf("%d\t", seq[i]);
    }
    printf("%d\n", node -> data);
    return;
  }

  if(node -> left != NULL)
  {
    seq[pos++] = node -> data;
    printrootleafpath(node -> left);
    pos--;
  }

  if(node -> right != NULL)
  {
    seq[pos++] = node -> data;
    printrootleafpath(node -> right);
    pos--;
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
  root -> left -> left -> left = createnode(-4);
  root -> left -> left -> left -> left = createnode(-5);
  root -> left -> left -> left -> right = createnode(-3);
  root -> left -> right = createnode(2);
  root -> right -> right = createnode(5);
  root -> right -> right -> right = createnode(6);

  inorder(root);
  printf("\n\nRoot to leaf paths:-\n\n");
  printrootleafpath(root);

  return 0;
}
