#include<iostream>
#include<string.h>
using namespace std;

class tree
{
	struct node
	{
		char data;
		node *left,*right;
		
	};
	node *root;
	
	public:
		tree()
		{
			root=NULL;
		}
	
	void create_post();
	void create_pre();
	void pre(node*);
	void in(node*);
	void post(node*);
	void preN();
	void inN();
	void postN();
	
	node *return_root()
	{
		return root;
	}
};

void tree::create_post()
{
	node *s[100];
	int top=-1;
	char post[100],token;
	cout<<"\n Enter postfix=>";
	cin>>post;
	for(int i=0;post[i]!='\0';i++)
	{
		token=post[i];
		node *newnode=new node;
		newnode->data=token;
		newnode->left=newnode->right=NULL;
		
		if(isalnum(token))
			s[++top]=newnode;
		else
		{
			newnode->right=s[top--];
			newnode->left=s[top--];
			s[++top]=newnode;
		}
	}
	root=s[top];
}
void tree::create_pre()
{
	node *s[100];
	int top=-1;
	char pre[100],token;
	cout<<"\n Enter prefix=>";
	cin>>pre;
	for(int i=strlen(pre)-1;i>=0;i--)
	{
		token=pre[i];
		node *newnode=new node;
		newnode->data=token;
		newnode->left=newnode->right=NULL;
		
		if(isalnum(token))
			s[++top]=newnode;
		else
		{
			newnode->left=s[top--];
			newnode->right=s[top--];
			s[++top]=newnode;
		}
	}
	root=s[top];
}
void tree::pre(node *temp)
{
	if(temp!=NULL)
	{
		cout<<"\t"<<temp->data;
		pre(temp->left);
		pre(temp->right);
	}
}

void tree::in(node *temp)
{
	if(temp!=NULL)
	{
		in(temp->left);
		cout<<"\t"<<temp->data;
		in(temp->right);
	}
}
void tree::post(node*temp)
{
	if(temp!=NULL)
	{
		post(temp->left);
		post(temp->right);
		cout<<"\t"<<temp->data;
	}
}

void tree::preN()
{
	node *s[100],*temp=root;
	int top=-1;
	while(temp!=NULL||top>-1)
	{
		while(temp!=NULL)
		{
			cout<<"\t"<<temp->data;
			s[++top]=temp;
			temp=temp->left;
		}
		temp=s[top--];
		temp=temp->right;
		
	}
}
void tree::inN()
{
	node *s[100],*temp=root;
	int top=-1;
	while(temp!=NULL||top>-1)
	{
		while(temp!=NULL)
		{
			
			s[++top]=temp;
			temp=temp->left;
		}
		temp=s[top--];
		cout<<"\t"<<temp->data;
		temp=temp->right;
		
	}
}
void tree::postN()
{
	node *s[100],*temp=root;
	char post[100];
	int i=0,top=-1;
	while(temp!=NULL||top>-1)
	{
		while(temp!=NULL)
		{
			post[i++]=temp->data;
			s[++top]=temp;
			temp=temp->right;
		}
		temp=s[top--];
		
		temp=temp->left;
		
	}
	for(i=strlen(post)-1;i>=0;i--)
		cout<<"\t"<<post[i];
}
int main()
{
	tree ob;
	int ch;
	//cout<<"\n create expression tree using postfix expression";
	//ob.create_post();
	cout<<"\n create expression tree using prefix expression";
	ob.create_pre();
	do
	{
		cout<<"\n1:Recursive traversal\n2:non recursive traversal";
		cout<<"\n:Enter your choice";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"\n Recursive preorder=>";
				ob.pre(ob.return_root());
				cout<<"\n Recursive inorder=>";
				ob.in(ob.return_root());
				cout<<"\n Recursive postorder=>";
				ob.post(ob.return_root());
			break;
			case 2:
				cout<<"\npreorder=>";
				ob.preN();
				cout<<"\ninorder=>";
				ob.inN();
				cout<<"\npostorder=>";
				ob.postN();
				
			break;
		}
	}while(ch<3);
}
