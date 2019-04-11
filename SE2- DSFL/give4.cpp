/*Expression Tree Travelsal*/
//Input//

#include <iostream>
#include <string.h>
#include <ctype.h>
#define MAX 20
using namespace std;

struct tree
{
  char data;
  struct tree *left;
  struct tree *right;
};

class stack
{
  tree *stk[20];
  int top;

public:
  stack()
  {
    top = -1;
  }
  tree *pop();
  int is_full();
  int is_empty();
  void push(tree *);
};

int stack::is_empty()
{
  if (top == -1)
    return 1;
  return 0;
}

int stack::is_full()
{
  if (top == MAX - 1)
    return 1;
  return 0;
}

void stack::push(tree *D)
{
  if (!is_full())
    stk[++top] = D;
}

tree *stack::pop()
{
  if (!is_empty())
  {
    tree *temp = stk[top--];
    return temp;
  }
}



tree *create()
{
  stack s;
  char post[20], token;
  cout << "\n Write postfix expression:";
  cin >> post;
  for (int i = 0; post[i] != '\0'; i++)
  {
    token = post[i];
    tree *node = new tree;
    node->data = token;
    node->left = node->right = NULL;

    if (isalnum(token))
      s.push(node);

    else
    {
      node->right = s.pop();
      node->left = s.pop();
      s.push(node);
    } //else
  }   //for
  return s.pop();
} //create



void PreTrav(tree *temp)
{
  if (temp != NULL)
  {
    cout << "  " << temp->data;
    PreTrav(temp->left);
    PreTrav(temp->right);
  }
}

void INTrav(tree *temp)
{
  if (temp != NULL)
  {
    INTrav(temp->left);
    cout << "  " << temp->data;
    INTrav(temp->right);
  }
}

void PostTrav(tree *temp)
{
  if (temp != NULL)
  {
    PostTrav(temp->left);
    PostTrav(temp->right);
    cout << "  " << temp->data;
  }
}

void NO_PreTrav(tree *temp)
{
  stack s;
  while (!s.is_empty() || temp != NULL)
  {
    while (temp != NULL)
    {
      cout << "  " << temp->data;
      s.push(temp);
      temp = temp->left;
    }
    temp = s.pop();
    temp = temp->right;
  }
}

void NO_INTrav(tree *temp)
{
  stack s;
  while (!s.is_empty() || temp != NULL)
  {
    while (temp != NULL)
    {
      s.push(temp);
      temp = temp->left;
    }
    temp = s.pop();
    cout << "  " << temp->data;
    temp = temp->right;
  }
}

void NO_PostTrav(tree *temp)
{
  stack s;
  int p, i, l = 0;
  char str[25];
  while (!s.is_empty() || temp != NULL)
  {
    while (temp != NULL)
    {
      str[l++] = temp->data;
      s.push(temp);
      temp = temp->right;
    }
    temp = s.pop();
    temp = temp->left;
  }
  str[l] = '\0';
  p = strlen(str);
  for (i = p; i >= 0; i--)
    cout << str[i] << "  ";
}

int main()
{
  struct tree *root = NULL;
  int ch;
  char ans;
  root = create();
  do
  {
    cout << "\n1:Resursive Travesals";
    cout << "\n2:Non Resursive Travesals";
    cout << "\nEnter Your Choice: ";
    cin >> ch;
    switch (ch)
    {
    case 1:
      cout << "\nYour Recursive Prefix Traversal is: ";
      PreTrav(root);
      cout << "\nYour Recursive Infix Traversal is: ";
      INTrav(root);
      cout << "\nYour Recursive Postfix Traversal is: ";
      PostTrav(root);
      break;
    case 2:
      cout << "\nYour Non_Recursive Prefix Traversal is: ";
      NO_PreTrav(root);
      cout << "\nYour Non_Recursive Infix Traversal is: ";
      NO_INTrav(root);
      cout << "\nYour Non_Recursive Postfix Traversal is: ";
      NO_PostTrav(root);
      break;
    default:
      cout << "Invalid Choice";
      break;
    }
    cout << "\nDo You want to continue..... Y/N: ";
    cin >> ans;
  } while (ans == 'Y' || ans == 'y');
} //main
