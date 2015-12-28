//program to find the depth or height of a tree
//status: executed successfully

#include<stdio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *left, *right;
};

int height, temp_height;

//FUNCTION TO FIND THE LARGER VALUE
int max(int a, int b)
{
  return a>b?a:b;
}

//FUNCTION TO CREATE NEW NODE
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

  printf("%d\t",root -> data);

  if(root -> right != NULL)
  {
    inorder(root -> right);
  }
}

//FUNCTION TO FIND THE DEPTH OF A NODE
//number of edges from the root to the node
/*void depth(struct node *node)
{

}
*/

//FUNCTION TO FIND THE HEIGHT OF A NODE
//number of edges from the node to the deepest leaf
void height_tree(struct node *node)
{
  if(node -> left != NULL)
  {
    temp_height++;
    height_tree(node -> left);
  }

  if(node -> right != NULL)
  {
    temp_height++;
    height_tree(node -> right);
  }

  if(node -> left == NULL && node -> right == NULL)
  {
    if(temp_height > height)
    {
      height = temp_height;
    }
  }
  temp_height--;
}

//A BETTER FUNCTION TO FIND THE HEIGHT OF TREE
int height_tree2(struct node *node)
{
  if(node == NULL)
  {
    return 0;
  }

  int l = height_tree2(node -> left) + 1;
  int r = height_tree2(node -> right) + 1;

  return max(l,r);
}

//MAIN FUNCTION
int main()
{
  struct node *root;

  root = createnode(5);
  root -> left = createnode(2);
  root ->  right = createnode(6);
  root -> left -> left = createnode(-1);
  root -> right -> right = createnode(7);
  root -> right -> right -> right = createnode(8);
  root -> right -> right -> right -> right = createnode(9);
  root -> right -> right -> right -> right -> right = createnode(10);
  root -> left -> right  = createnode(3);
  root -> left -> right -> right  = createnode(4);
  root -> left -> left -> left = createnode(-2);
  root -> left -> left -> right  = createnode(0);
  root -> left -> left -> right -> right  = createnode(1);


  inorder(root);

  height_tree(root);

  printf("Height (v2) : %d",height_tree2(root)-1);

  printf("\nHeight: %d\n",height);
  return 0;
}
