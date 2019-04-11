#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
using namespace std;

class stack
{
	typedef struct node
	{
		int data;
		node *next;
	} node;
	node *top;

public:
	stack()
	{
		top = NULL;
	} //constructor

	int empty();
	void push(int);
	int pop();
	void display();
};

int stack::empty()
{
	if (top == NULL)
		return 1;
	return 0;
}

void stack::push(int x)
{
	node *p;
	p = new node;
	p->data = x;
	p->next = top;
	top = p;
}

int stack::pop()
{
	int x;
	node *p;
	p = top;
	x = p->data;
	top = top->next;
	delete p;
	return x;
}

void stack::display()
{
	int i = 0;
	node *p;
	p = top;
	cout << "\n>>>>>>>Elemets in Stack<<<<<<<";
	while (p != NULL)
	{
		cout << "\n | " << p->data << " |";
		p = p->next;
	}
	cout << "\n\n";
}

int priority(char x)
{
	static int flag = 3;

	if (x == '*' || x == '/')
	{
		return 2;
	}
	if (x == '+' || x == '-')
	{
		return 1;
	}
	if (x == '^')
	{
		return flag++;
	}
	else
		return 0;
}

void itopost(char str[])
{
	char post[25], opr;
	int i = 0;
	int j = 0, count;
	stack s;

	for (i = 0; i < strlen(str); i++)
	{
		if (isalnum(str[i]))
		{
			post[j++] = str[i];
		}
		else
		{
			if (str[i] == ')')
			{
				opr = s.pop();
				while (opr != '(')
				{
					post[j++] = opr;
					opr = s.pop();
				}
			}
			else
			{
				if (str[i] == '(')
				{
					s.push(str[i]);
				}
				else
				{
					while (!s.empty())
					{
						opr = s.pop();
						if (opr != '(' && priority(opr) >= priority(str[i]))
						{
							post[j++] = opr;
						}
						else
						{
							s.push(opr);
							break;
						}
					}
					s.push(str[i]);
				}
			}
		}
	}

	while(!s.empty())
	{
		post[j++] = s.pop();
	}
	post[j] = '\0';
	cout<<"\nPost : " << post;
}

void itopre(char str[])
{
	char pre[25], opr;
	int i = 0;
	int j = 0, count;
	stack s;

	for (i = strlen(str) - 1; i >= 0; i--)
	{
		if (isalnum(str[i]))
		{
			pre[j++] = str[i];
		}
		else
		{
			if (str[i] == '(')
			{
				opr = s.pop();
				while (opr != ')')
				{
					pre[j++] = opr;
					opr = s.pop();
				}
			}
			else
			{
				if (str[i] == ')')
				{
					s.push(str[i]);
				}
				else
				{
					while (!s.empty())
					{
						opr = s.pop();
						if (opr != ')' && priority(opr) >= priority(str[i]))
						{
							pre[j++] = opr;
						}
						else
						{
							s.push(opr);
							break;
						}
					}
					s.push(str[i]);
				}
			}
		}
	}

	while (!s.empty())
	{
		pre[j++] = s.pop();
	}
	pre[j] = '\0';
	cout << "\npre : " << pre;
}



int main()
{
	char prefix[25];
	cout << "Enter infix : ";
	cin >> prefix;
	itopost(prefix);
	itopre(prefix);
}