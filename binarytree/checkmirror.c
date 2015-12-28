//program to check if two trees are mirror images of each other or not
//status : executed successfully

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


//FUNCTION TO CHECK IF TWO TREES ARE MIRROR IMAGES
int checkmirror(struct node *node1, struct node *node2)
{
  if(node1 == NULL && node2 == NULL)
  {
    return 1;
  }

  else if(node1 != NULL && node2 != NULL)
  {
    return (node1 -> data == node2 -> data && checkmirror(node1->left, node2->right) && checkmirror(node1->right, node2->left));
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
  root1 -> right -> right -> right = createnode(6);

  root2 = createnode(3);
  root2 -> left = createnode(4);
  root2 ->  right = createnode(1);
  root2 -> left -> left = createnode(5);
  root2 -> right -> left = createnode(2);
  root2 -> right -> right = createnode(0);
  root2 -> left -> left -> left = createnode(6);



  printf("Tree 1:");
  inorder(root1);

  printf("\nTree 2:");
  inorder(root2);

  if(checkmirror(root1, root2))
  {
    printf("\n\nTrees are mirror images!\n");
    exit(0);
  }
  printf("\n\nTrees are NOT mirror images!\n");

  return 0;
}
