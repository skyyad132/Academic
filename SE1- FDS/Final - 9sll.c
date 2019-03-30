#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
  int data;
  struct node *next;
}node;

node *getnode();
void display(node *head);
node *create(node *head);
node *addatbeg(node *head);
node *addatend(node *head);
node *addatmid(node *head);
node *delatbeg(node *head);
node *delatend(node *head);
node *delatmid(node *head);
node *rev(node *head);
void reverse(node *head);

int main()
{
  node *head = NULL;
  int ch;
  printf("Create a new singly linked list : \n");
  head = create(head);
  do
  {
    printf("\n1.Display\n2.Add at beginning\n3.Add at end\n4.Add at middle\n5.Delete at beginning\n6. Delete at Middle\n7.Delete at middle\n8.reverse\n9.reverse using recursion\n99.Exit");
    printf("\nEnter your choice : ");
    scanf("%d", &ch);
    printf("\n");
    switch(ch)
    {
      case 1:
        display(head);
        break;

      case 2:
        head = addatbeg(head);
        break;

      case 3:
        head = addatend(head);
        break;

      case 4: 
        head = addatmid(head);
        break;
    
      case 5:
        head = delatbeg(head);
        break;

      case 6:
        head = delatend(head);
        break;

      case 7:
        head = delatmid(head);
        break;
      
      case 8:
        head = rev(head);
        break;

      case 9:
        reverse(head);
        break;

      case 99:
        printf("Ending program.");
        break;

      default:
        printf("Try again...");
    }
  }
  while (ch != 99);
}

node *getnode()
{
  node *newnode;
  newnode = (node *)malloc(sizeof(node));
  newnode -> next = NULL;
  printf("Enter data : ");
  scanf("%d", &(newnode -> data));
  getchar();
  return newnode;
}

node *create(node *head)
{
  node *p, *newnode;
  char ch = 'y';

  while (ch == 'y')
  {
    newnode = getnode();
    if (head == NULL)
    {
      head = newnode;
      p = head;
    }
    else
    {
      p -> next = newnode;
      p = newnode;
    }
    printf("Do you want to continue [y/n] : ");
    scanf("%c", &ch);
  }//end of while
  return head;
}

void display(node *head)
{
  node *p;
  p = head;

  if (p == NULL)
  {
    printf("List empty");
    return;
  }
  while (p != NULL)
  {
    printf("%d -> ", p -> data);
    p = p -> next;
  }
  printf("NULL\n");
}

node *addatbeg(node *head)
{
  node *p;
  p = getnode();
  p -> next = head;
  head = p;
  return head;
}

node *addatend(node *head)
{
  node *p, *q;
  p = getnode();
  q = head;
  while(q -> next != NULL)
  {
    q = q -> next;
  }

  q -> next = p;
  return head;
}

node *addatmid(node *head)
{
  int key;
  node *p, *q;
  printf("\nEnter after which node you want to enter : ");
  scanf("%d", &key);

  p = getnode();
  q = head;

  while (q != NULL)
  {
    if (q -> data == key)
    {
      p -> next = q -> next;
      q -> next = p;
      break;
    }
    q = q -> next;
  }//end of while
  return head;
}

node *delatbeg(node *head)
{
	node *q;
	q = head;          //temp points to 1st node
	head = head -> next;//move head  to next node 
	q -> next = NULL;
	free(q);
	return head;
}


node *delatend(node *head)
{
	node *t1,*t2;
	t1 = head;
	t2 = head -> next;
	while (t2 -> next != NULL)
	{
		t1 = t1 -> next;
		t2 = t2 -> next;
	}
	t1 -> next = NULL;
  free(t2);
	return head;
}


node *delatmid(node *head)
{
	node *t1, *t2;
	t1 = head;
	t2 = head -> next;
	int val;
	printf("\nEnter the node you want to Delete : ");
	scanf("%d", &val);
	while (t2 != NULL)
	{
		if (t2 -> data == val)
		{
			t1 -> next = t2 -> next;
			t2 -> next = NULL;
			free(t2);
      return head;
		}
		t1 = t1 -> next;
		t2 = t2 -> next;
  }
	return head;
}


node *rev(node *head)
{
  node *p, *q, *r;

  p = NULL;
  q = head;
  r = q -> next;

  while (q != NULL)
  {
    q -> next = p;
    p = q;
    q = r;
    if (r != NULL)
    {
      r = r -> next;
    }
  }//end of while
  head = p;
  return head;
}


void reverse(node *head)
{
  if (head != NULL)
  {
    reverse(head -> next);
    printf("%d ", head -> data);
  }
}