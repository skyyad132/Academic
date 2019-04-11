Assignment 1-Application Of Stack as ADT

#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
using namespace std;

class stack
	{
		typedef struct node
		{
			int data;
			node *next;
	
		}node;
		node *top;
		public:
			stack()
			{
			top=NULL;
			}//constructor
		
				int empty();
				void push(int );
				int pop();
				void display();
	};//stack class
	
int stack::empty()
{
if(top==NULL)
return 1;
return 0;
}

void stack::push(int x)
{ 
	node *p;
	p=new node;
	p->data=x;
	p->next=top;
	top=p;
}

int stack::pop()
{
	int x;
	node *p;
	p=top;
	x=p->data;
	top=top->next;
	delete p;
	return x;
}

void stack::display()
{
int i=0;
node *p;
p=top;
cout<<"\n>>>>>>>Elemets in Stack<<<<<<<";
while(p!=NULL)
{cout<<"\n | "<<p->data<<" |";
p=p->next;
}
cout<<"\n\n";
}

int eval(char sign,int n1,int n2)
{
if(sign=='+')
return(n1+n2);
if(sign=='-')
return(n1-n2);
if(sign=='*')
return(n1*n2);
if(sign=='/')
return(n1/n2);
if(sign=='^')
return(n1^n2);
}

void eval_postfix(char postfix[])
{
	stack s;
	char x;
	int n1,n2,val,i;
	for(i=0;i<=strlen(postfix)-1;i++)
	{
		x=postfix[i];
		if(isalpha(x))
		{
		cout<<"PLease Enter Value of "<<x<<":";
		cin>>val;
		s.push(val);
		}	
		else if(isdigit(x))
		{
		s.push(x-48);
		}	
		else
		{
		n1=s.pop();
		n2=s.pop();
		val=eval(x,n1,n2);
		s.push(val);
		
		}
}
val=s.pop();
cout<<"\n>>>>>>>>Value Of Expression( "<<postfix<<" ) is :"<<val<<endl;
}

void eval_prefix(char prefix[])
{
	stack s;
	char x;
	int n1,n2,val,i;
	for(i=strlen(prefix)-1;i>=0;i--)
	{
		x=prefix[i];
		if(isalpha(x))
		{
		cout<<"PLease Enter Value of "<<x<<":";
		cin>>val;
		s.push(val);
		}	
		else if(isdigit(x))
		{
		s.push(x-48);
		}	
		else
		{
		n1=s.pop();
		n2=s.pop();
		val=eval(x,n1,n2);
		s.push(val);
		
		}
}
val=s.pop();

cout<<"\n>>>>>>>>Value Of Expression( "<<prefix<<" ) is :"<<val<<endl;
}

int Priority(char x)
{
static int flag=3;

if(x=='*' || x=='/')
return 2;
if(x=='+' || x=='-')
return 1;
if(x=='^')
return flag++;
else return 0;

}

void coninfpos(char String[])
{
    char PostExpression[25],opr;
    int I=0,J=0,count;
    stack s;

    for(I=0;I<strlen(String);I++ )
    {
	if(isalnum(String[I]))
		PostExpression[J++]=String[I];
	else
	{
		if(String[I]==')')
		{
			opr=s.pop();
			while(opr!='(')
			{
				PostExpression[J++]=opr;
				opr=s.pop();
			}
		}
		else
		{
			if(String[I]=='(')
			s.push(String[I]);
			else
			{
				while(!s.empty())
				{
				opr=s.pop();
				if(opr!='('&& Priority(opr)>=Priority(String[I]))
				{
				  PostExpression[J++]=opr;
				}
				else
				{
				  s.push(opr);
				  break;
				}
				}//while
			    s.push(String[I]);
			}
		} //else
	      }
}  //for

while(!s.empty())
  {
	PostExpression[J++]=s.pop();
  }
	PostExpression[J]='\0';

cout<<"\nPost: "<<PostExpression;
}


void coninfpre(char String[])
{
char PreExpression[20],opr;
 int I=0,J=0;
 I=strlen(String);
 I--;
 stack s;

     for(I=strlen(String);I>=0;I-- )
    {
	if(isalnum(String[I]))
		PreExpression[J++]=String[I];
	else
	{
		if(String[I]=='(')
		{
			opr=s.pop();
			while(opr!=')')
			{
				PreExpression[J++]=opr;
				opr=s.pop();
			}
		}
		else
		{
			if(String[I]==')')
			s.push(String[I]);
			else
			{
			     	while(!s.empty())
				{
				opr=s.pop();
				if(opr!=')'&& Priority(opr)>=Priority(String[I]))
				{
				  PreExpression[J++]=opr;
				}
				else
				{
				  s.push(opr);
				  break;
				}
				}//while
			    s.push(String[I]);
			}
		} //else
	      }
}  //for

while(!s.empty())
   PreExpression[J++]=s.pop();
 PreExpression[J]='\0';
cout<<" prefix is ";//<<PreExpression;
for(I=J-1;I>=0;I--)
 cout<<PreExpression[I];

};

int main()
{
stack s;
int ch,p;

char postfix[30],prefix[30],infix[30];
	while(1)
	{
		cout<<"\nMenu";
		cout<<"\n1)Infix to Prefix\n2)Infix to Postfix\n3)Evaluation of Prefix\n4)Evaluation of Postfix\n5)Exit\nChoice:";
		cin>>ch;
		switch(ch)
		{
		case 1:	cout<<"\n\n-------------Infix To Prefix Expression----------------\n\nPlease Enter Infix Expression(1+2-3*4 or a+b-c*d)\nExpression:";
				cin>>infix;
				coninfpre(infix);
				break;
	
		case 2:	cout<<"\n\n-------------Infix To Postfix Expression----------------\n\nPlease Enter Infix Expression(1+2-3*4 or a+b-c*d)\nExpression:";
				cin>>infix;
				coninfpos(infix);
				break;
	
		case 3:	cout<<"\n\n-------------Evaluation of Prefix Expression----------------\n\nPlease Enter Prefix Expression(+-*1234 or +-*abcd)\nExpression:";
				cin>>prefix;
				eval_prefix(prefix);				
				
		
				break;
	
		case 4:	cout<<"\n\n-------------Evaluation of Postfix Expression----------------\n\nPlease Enter Postfix Expression(59+3* or ab+c*)\nExpression:";
				cin>>postfix;
				eval_postfix(postfix);				
				
				break;
	
		case 5:	return 0;
		
		default:	cout<<">>>>>>>>>Wrong Choice<<<<<<<<<<<<";
				break;
	
		}//switch
	
	}//while

}

