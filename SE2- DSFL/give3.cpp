#include <iostream>
using namespace std;
struct node
{
  char data;
  node *left;
  node *right;
  node()
  {
    left = right = NULL;
  }
}; //struct
class tree
{

  node *root;

public:
  tree()
  {
    root = NULL;
  }
  node *create();
  void insert(char);
  void preorder(node *);
  void inorder(node *);
  void postorder(node *);
  void bfs();
  node *copy(node *);
}; //class

node *tree::create()
{
  node *temp;
  char dir;
  char val, ans = 'y';

  do
  {
    cout << "\nEnter value : ";
    cin >> val;

    node *Nnode = new node;
    Nnode->data = val;

    if (root == NULL)
      root = Nnode;
    else
    {
      temp = root;

      while (1)
      {
        cout << "\nEnter direction (l/r): ";
        cin >> dir;
        if (dir == 'L' || dir == 'l')
        {
          if (temp->left == NULL)
          {
            temp->left = Nnode;
            break;
          } //if
          else
            temp = temp->left;
        } //if
        else if (dir == 'R' || dir == 'r')
        {
          if (temp->right == NULL)
          {
            temp->right = Nnode;
            break;
          } //if
          else
            temp = temp->right;
        } //if

      } //while 1

    } //else
    cout << "\nDo you want to add more(y/n) : ";
    cin >> ans;
  } while (ans == 'y' || ans == 'Y');
  return root;
} //create

void tree::insert(char val)
{
  node *temp = root;
  char dir;

  node *Nnode = new node;
  Nnode->data = val;

  if (root == NULL)
    root = Nnode;
  else
  {
    temp = root;

    while (1)
    {
      cout << "\nEnter direction (l/r): ";
      cin >> dir;
      if (dir == 'L' || dir == 'l')
      {
        if (temp->left == NULL)
        {
          temp->left = Nnode;
          break;
        } //if
        else
          temp = temp->left;
      } //if
      else if (dir == 'R' || dir == 'r')
      {
        if (temp->right == NULL)
        {
          temp->right = Nnode;
          break;
        } //if
        else
          temp = temp->right;
      } //if

    } //while 1

  } //else

} //insert

void tree::preorder(node *temp)
{
  if (temp != NULL)
  {
    cout << temp->data << "\t";
    preorder(temp->left);
    preorder(temp->right);

  } //if

} //preorder





void tree::bfs()
{
  node *queue[50], *temp = root; // made an array of queue and a temporary node now points to the node of the tree
  int front = 0, rear = 1, level = 0, leaf = 0; // front is 0, rear is 1
  // in queue, we add at rear end and delete from front
  queue[0] = temp; // first element of queue (front) is made the root node now
  queue[1] = NULL; // next element is made NULL, NULL in queue indicates the end of level
  cout << "\nLevel : " << level++ << " => "; // printing the level number which will printed next
  do // execute it atleast one time
  {
    temp = queue[front++]; // temp is now pointing to element in the front and front is then incremented
    if (temp == NULL) // if the element pointedd by temp which was previously in front is null then :
    {
      queue[++rear] = NULL; 
      cout << "\nLevel : " << level++ << " => ";
    } //if

    else
    {
      cout << "\t" << temp->data;
      if (temp->left != NULL)
        queue[++rear] = temp->left;

      if (temp->right != NULL)
        queue[++rear] = temp->right;

      else if (temp->left == NULL && temp->right == NULL)
        leaf++;

    }                     //else
  } while (front < rear); // execute while front < rear i.e. until queue empty

  cout << "\nDeapth of tree is: " << level;
  cout << "\nNumber of leaf nodes : " << leaf;

} //bfs





node *tree::copy(node *temp)
{
  node *temp1 = NULL;
  if (temp != NULL)
  {
    temp1 = new node;
    temp1->data = temp->data;
    temp1->left = copy(temp->left);
    temp1->right = copy(temp->right);
  }
  return temp1;
} //copy

int main()
{
  tree b;
  int ch;
  char ans = 'y', val;
  node *Root = NULL, *Root1 = NULL;

  Root = b.create();
  do
  {
    cout << "\n1.Insert an node\n2.preorder display\n3.bfs\n4.copy ";
    cout << "\nEnter your choice : ";
    cin >> ch;
    switch (ch)
    {
    case 1:
      cout << "\nEnter value : ";
      cin >> val;
      b.insert(val);
      break;
    case 2:
      b.preorder(Root);
      break;
    case 3:
      b.bfs();
      break;
    case 4:
      Root1 = b.copy(Root);
      b.preorder(Root1);
      break;

    } //switch
    cout << "\nDo you want to continue(y/n) : ";
    cin >> ans;
  } while (ans == 'y' || ans == 'Y');
} //main