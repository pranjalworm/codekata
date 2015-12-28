//BASIC PROGRAM: program to search in a bst
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


//FUNCTION TO SEARCH IN BST
struct node* search(struct node *root, int value)
{
  if(root == NULL || root -> data == value)
    return root;

  if(root -> data > value)
    return search(root -> left, value);

  if(root -> data  < value)
    return search(root -> right, value);
}


//MAIN FUNCTION
int main()
{
  int value;
  struct node *root, *temp;
  root = NULL;

  root = createnode(3);
  root -> left = createnode(1);
  root ->  right = createnode(4);
  root -> left -> left = createnode(0);
  root -> left -> right = createnode(2);
  root -> right -> right = createnode(5);
  root -> right -> right -> right = createnode(6);

  printf("Enter value to search: ");
  scanf("%d",&value);

  //call to search function
  temp = search(root, value);
  if(temp != NULL)
  {
    printf("temp -> data (validation): %d\n",temp -> data);
  }
  else
  {
    printf("Element not found!\n");
  }

  //traversals
  inorder(root);

  return 0;
}
