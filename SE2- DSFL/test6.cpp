#include <iostream>
#include <string.h>
using namespace std;
class facebook
{
  struct user
  {
    char name[20], dob[20];
    int visit;
    int no_comments;
    user *next;
    user()
    {
      next = NULL;
      visit = -1;
      no_comments = 0;
    }
  } list[20];

  int pos;

public:
  facebook() { pos = -1; }

  int create();
  void display(int);
  int position(char[]);
  void dobmonth();
  void maxfriend();
  void comments();
  void resetflag(int);
};

int facebook::position(char s[])
{
  for (int i = 0; i < 10; i++)
  {
    if (strcmp(list[i].name, s) == 0)
    {
      return i;
    }
  }

  return -1; // outside the for loop. 
}

int facebook::create()
{
  user *nnode, *nnode1, *temp;

  int i = 0;
  int pos, no_users = 0;
  char frnd[15], ans, Ans;

  do
  {
    cout << "Enter username : ";
    cin >> list[i].name;

    cout << "Enter date of birth : ";
    cin >> list[i].dob;

    cout << "Enter number of comments : ";
    cin >> list[i].no_comments;


    i++;
    no_users++;

    cout << "Add more users [y/n] : ";
    cin >> ans;
  } while (ans == 'y');

  for (i = 0; i < no_users; i++)
  {
    cout << "\nEnter friend list of user : " << list[i].name;

    do
    {
      cout << "\nEnter friend name : ";
      cin >> frnd;
      pos = position(frnd);

      if (pos != -1)
      {
        // friend of i is pos
        nnode = new user;
        nnode->visit = pos;

        for (temp = &list[i];
             temp->visit != pos && temp->next != NULL;
             temp = temp->next);

        if (temp->visit != pos)
          temp->next = nnode;

        // friend of pos is i
        nnode1 = new user;
        nnode1->visit = i;

        for (temp = &list[pos];
             temp->visit != i && temp->next != NULL;
             temp = temp->next);

        if (temp->visit != pos)
          temp->next = nnode1;
      }
      else
      {
        cout << "\nUser does not exist\n";
      }
      cout << "\nAdd more frinds ? : "; cin >> Ans;

    } while (Ans == 'y');
  } // for

  return no_users;
}

void facebook ::display(int n)
{
  user *temp;
  cout << "\n=====  LIST OF USERS  =====";
  cout << "\nNAME\tDate Of Birth\tComments";

  for (int i = 0; i < n; i++)
  {
    temp = &list[i];
    cout << "\n"
         << list[i].name;
    cout << "\t" << list[i].dob;
    cout << "\t" << list[i].no_comments;
  } //for
} //display


void facebook::dobmonth() // uses dsf
{
  user *temp;
  int top = -1;
  int i;
  int stk[20];
  char month[2];
  char dob_month_of_user[3];

  cout << "\n\n*******Users of same birth month*******";
  cout << "\nEnter month : (01: Jan | 02: Feb | ... | 12: Dec ";
  cin >> month;
  
  list[0].visit = 1;

  stk[++top] = 0;

  cout << "\nUsers of birth month " << month << " are : \n";

  while (top > -1)
  {
    i = stk[top--];

    strncpy(dob_month_of_user, list[i].dob, 2);
    dob_month_of_user[2] = '\0';
    if (strcmp(dob_month_of_user, month) == 0)
        cout << list[i].name << "\n";

    temp = list[i].next;

    while (temp != NULL)
    {
      i = temp -> visit;
      if (list[i].visit != 1)
      {
        stk[++top] = temp -> visit;
        list[i].visit = 1;
      }
      temp = temp -> next;
    }
  }
}


void facebook::maxfriend() // uses dfs
{
  int i, j;
  int count;
  int maximum = 0;
  int stk[20];
  int top = -1;
  int pos;
  user *temp;

  list[0].visit = 1;
  stk[++top] = 0;

  while (top > -1)
  {
    i = stk[top--];
    temp = list[i].next;

    count = 0;
    while (temp != NULL)
    {
      count++;
      j = temp -> visit;
      
      if(list[j].visit != 1)
      {
        stk[++top] = temp -> visit;
        list[j].visit = 1;
      }
      temp = temp -> next;
    }

    if (count > maximum)
    {
      maximum = count;
      pos = i;
    }
  }

  cout << "\nMax friends is of : "<< list[pos].name <<" : "<< maximum;
}



void facebook::comments() // uses bfs ie queue
{
  user *temp;
  int q[20];
  int front = 0;
  int rear = 0;
  int max;
  int min;
  int maxuser;
  int minuser;

  list[0].visit = 1;
  q[0] = 0;

  //initialization
  max = min = list[0].no_comments;
  maxuser = 0;
  minuser = 0; 

  //checking
  while (front <= rear)
  {
    int i = q[front++];
    temp = list[i].next;

    while (temp != NULL)
    {
      i = temp -> visit;
      if (list[i].visit != 1)
      {
        if (max < list[i].no_comments)
        {
          maxuser = i;
          max = list[maxuser].no_comments;
        }
        else if (min > list[i].no_comments)
        {
          minuser = i;
          min = list[minuser].no_comments;
        }
        q[++rear] = i;
        list[i].visit = 1;
      }
      temp = temp -> next;
    }
  }

  cout << "\nMax comments is of user : " << list[maxuser].name << " : " << max;
  cout << "\nMin comments is of user : " << list[minuser].name << " : " << min;
}

void facebook::resetflag(int n)
{
  int i;

  for (i = 0; i < n; i++)
  {
    list[i].visit = 0;
  }
}


int main()
{
  facebook fb;
  int op, num;
  char ans;

  num = fb.create();
  fb.display(num);

  do
  {
    cout << "\n----------------------------------------------------------------------";
    cout << "\n*****   MENU  *****";
    cout << "\n1. Users having same birth month";
    cout << "\n2. User having maximum friends";
    cout << "\n3. User having maximum and minimum no. of comments ";
    cin >> op;
    switch(op)
    {
      case 1:
        fb.resetflag(num);
        fb.dobmonth();
        break;

      case 2:
        fb.resetflag(num);
        fb.maxfriend();
        break;

      case 3:
        fb.resetflag(num);
        fb.comments();
        break;

      default:
        cout << "\nInvalid input\n";
    }

    cout << "\nMore? [y/n] ";
    cin >> ans;
  } while (ans == 'y');
  
}