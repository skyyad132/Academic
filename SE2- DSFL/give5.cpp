/*----------------------------------------------------------------------------------------------------------------------------
			     ASSIGNMENT NO. - 5
		        OPERATIONS ON BINARY SEARCH TREE
----------------------------------------------------------------------------------------------------------------------------*/

#include<iostream>
using namespace std;

class BST
{
	struct node
	{
		int data;
		node *left, *right;
		
		node()
		{
			left=right=NULL;
		}	
	}*root;

   public:
	
	BST()
	{
		root=NULL;	
	}
	node *return_root()
	{
		return root;
	}
	void insert(int);
	void display(node*);
	int search(int);
	void leveldisp(node*);
	void mirrorimg(node*);
	void del(int);
};//class

void BST :: insert(int d)
{
	node *temp=root, *Nnode=new node;
	Nnode->data=d;
	
	if(root==NULL)
	{
			root=Nnode;
			cout<<"\nRoot node created!!!\n";
	}//if
				
	else
	{
		while(1)
		{		
			if(d<temp->data)
			{			
				if(temp->left==NULL)
				{
					
					temp->left=Nnode;
					break;
				}//if
				else
					temp=temp->left;
			}//if
			
			else if(d>temp->data)
			{
				if(temp->right==NULL)
				{
					temp->right=Nnode;
					break;
				}//if
				else
					temp=temp->right;
			}//else if
			
			else
			{
				cout<<"Entry is Repeated... REENTER !!!\t";
				break;
			}//else			
		}//while
	}//else
}//insert

void BST :: display(node *temp)
{	
	if(temp!=NULL)
	{		
		display(temp->left);
		cout<<temp->data<<"  ";
		display(temp->right);	
	}//if
}//display

int BST :: search(int key)
{
	node *temp=root;
	int flag=0;
	
	while(temp!=NULL)
	{
		if(key<temp->data)
			temp=temp->left;
			
		else if(key>temp->data)
			temp=temp->right;
			
		else
		{
			flag=1;
			break;
		}//else			
	}//while
	return flag;
}//search

void BST :: leveldisp(node *temp)
{
	node* Q[20];
	int front=0,rear=1;
	
	if(temp==NULL)
		cout<<"Tree is Empty";
		
	else
	{
		Q[0]=temp,Q[1]=NULL;
	
		while(front<rear)
		{
			temp=Q[front++];
		
			if(temp==NULL)
			{
				cout<<endl;
				Q[++rear]=NULL;
			}//if
			else
			{
				cout<<temp->data<<"  ";
				if(temp->left!=NULL)
					Q[++rear]=temp->left;
				
				if(temp->right!=NULL)
					Q[++rear]=temp->right;
	
			}//else
		}//while
	}//else
}//leveldisp

void BST :: mirrorimg(node *temp)
{
	node* Q[20];
	int front=0,rear=1;
	
	if(temp==NULL)
		cout<<"Tree is Empty";
		
	else
	{
		Q[0]=temp,Q[1]=NULL;
	
		while(front<rear)
		{
			temp=Q[front++];
		
			if(temp==NULL)
			{
				cout<<endl;
				Q[++rear]=NULL;
			}//if
			else
			{
				cout<<temp->data<<"  ";
				if(temp->right!=NULL)
					Q[++rear]=temp->right;
				
				if(temp->left!=NULL)
					Q[++rear]=temp->left;
			}//else
		}//while
	}//else
}//mirrorimage

void BST :: del(int num)
{
	node *s[20], *ptemp=root,*temp=root,*rtemp,*prtemp;
	char flag;

	while(temp->data!=num && temp!=NULL)
	{
		if(num>temp->data)
		{	
			ptemp=temp;
			flag='r';
			temp=temp->right;
		}//if
		else
		{	
			ptemp=temp;
			flag='l';
			temp=temp->left;
		}//else
	}//while

	if(temp!=NULL)
	{
		if(temp->left==NULL && temp->right==NULL)
		{
			if(root==temp)
				root==NULL;
			if(flag=='r')
				ptemp->right=NULL;
			else
				ptemp->left=NULL;
		}//if


		else if(temp->left!=NULL && temp->right!=NULL)
		{
			prtemp=temp->right;
			rtemp=temp->right;
		
			while(rtemp->left!=NULL)
			{
				prtemp=rtemp;
				rtemp=rtemp->left;
			}//while
			
			prtemp->left=rtemp->right;

			if(temp==root)
				root=rtemp;
			else if(flag=='l')
				ptemp->left=rtemp;
			else if(flag=='r')
				ptemp->right=rtemp;
			
			rtemp->left=temp->left;
			if(rtemp!=prtemp)
				rtemp->right=temp->right;
		}//else if
		
		
		else if(temp->right!=NULL && temp->left==NULL)
		{
			if(root==temp)
				root=root->right;
			if(flag=='l')
				ptemp->left=temp->right;
			else
				ptemp->right=temp->right;
		}//else if
		
		
		else if(temp->left!=NULL && temp->right==NULL)
		{
			if(root==temp)
				root=root->left;
			if(flag=='l')
				ptemp->left=temp->left;
			else
				ptemp->right=temp->left;
		}//else if
	}//if

	else
		cout<<"\nNode not present to be deleted";
	delete temp;
}//del

int main()
{
	BST tree;
	int i,num,key,op;
	char ans,ANS;
	
	do
	{
		cout<<"\nEnter the node value : ";
		cin>>num;
	
		tree.insert(num);
		
		cout<<"Do more (Y/N)???   ";
		cin>>ans;
	}while(ans=='Y'||ans=='y');
	
	do
	{
	
		cout<<"\n----------------------------------------------------------------------";
		cout<<"\n*****   MENU  *****";
		cout<<"\n1. Display the tree";
		cout<<"\n2. Display level wise";
		cout<<"\n3. Mirror Image";
		cout<<"\n4. Search";
		cout<<"\n5. Delete\t";

		cin>>op;
		
		switch(op)
		{
			case 1 :
				cout<<"\n**********  Tree Display  **********\n";
				tree.display(tree.return_root());
				break;
				
			case 2 :
				cout<<"\n**********  Levelwise Display  **********\n";				
				tree.leveldisp(tree.return_root());
				break;
				
			case 3 :
				cout<<"\n**********  Mirror Image  **********\n";
				tree.mirrorimg(tree.return_root());
				break;
			
			case 4 :
				cout<<"\n**********  Search node  **********\n";
				cout<<"\nEnter the node value to search : ";
				cin>>key;
	
				i=tree.search(key);
				if(i==1)
					cout<<"\nThe node with value "<<key<<" is present";
				else 
					cout<<"\nSearched node is absent !!!";

				break;	

			case 5 :
				cout<<"\n**********  Delete a node  **********\n";
				cout<<"\nEnter the no. you want to delete : ";
				cin>>num;
				tree.del(num);
				cout<<"\nTree after deletion of node is : \n";	
				tree.display(tree.return_root());
				break;
			
				
			default: cout<<"\nInvalid Input !!!";
		}//switch
		
		cout<<"\nDo more (Y/N) ???";
		cin>>ANS;
	 
	}while(ANS=='Y'||ANS=='y');	
}//main
