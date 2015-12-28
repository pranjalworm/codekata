//Inorder Tree Traversal without Recursion using stack
//status: in progress

#include<stdio.h>
#include<malloc.h>

struct stack
{
  int top;
  int arr[10];
};

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

///TO PUSH DATA ONTO THE STACK
void push(struct stack *stack, int value)
{
  if(stack -> top == 10)
  {
    printf("STACK IS FULL!");
    return;
  }
  stack -> top++;
  stack -> arr[stack -> top] = value;
}

//TO POP DATA OFF THE STACK
void pop(struct stack *stack)
{
  if(stack -> top == -1)
  {
    printf("No more elements to delete!");
    return;
  }
  printf("Data: %d\n",stack -> arr[stack -> top]);
  stack -> top--;
}

///TO INITIALISE THE STACK
void initstack(struct stack *stack)
{
  stack -> top = -1;
}

//FUNCTION TO TRAVERSE TREE USING STACK
void stack_traversal(struct stack *stack, struct node *node)
{

}

//MAIN FUNCTION
int main()
{
  struct node *root;
  struct stack stack;

  root = createnode(3);
  root -> left = createnode(1);
  root ->  right = createnode(4);
  root -> left -> left = createnode(0);
  root -> left -> right = createnode(2);
  root -> right -> right = createnode(5);
  root -> right -> right -> right = createnode(6);

  initstack(&stack);

  inorder(root);
  //stack_traversal(root);

  printf("\n\n");

  return 0;
}
