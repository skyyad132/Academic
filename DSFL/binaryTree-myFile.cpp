#include <iostream>
#include <stdio.h>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;
};

class tree {
	node *root;
	
	public:
		tree() {
			root = NULL;
		}
		node *create();
		void insert(int);
		void preorder(node *);
		void inorder(node *);
		void postorder(node *);
		node *copy(node *);
		void DFS();
};


node *tree :: create() {
	node *temp;
	int value;
	char direction, answer;
	
	do {
		node *newNode = new node;
		cout<<"Enter value : ";
		cin>>value;
		newNode -> data = value;
		
		if (root == NULL) {
			root = newNode;
		}
		else {
			temp = root;
			
			while(1)
			{
			cout<<"Enter direction [L/R]";
			cin>>direction;
			
			if (direction == 'l' || direction == 'L') {
				if (temp -> left == NULL) {
					temp -> left = newNode;
					break;
				} else {
					temp = temp -> left;
				}	
			} 
			
			else if (direction == 'r' || direction == 'R') {
					if (temp -> right == NULL) {
						temp -> right = newNode;
						break;
					} else {
						temp = temp -> right;
					}
				}
			}
		}
		
		cout<<"Continue [Y/N] : ";
		cin>>answer; 	
	} while (answer == 'Y' || answer == 'y');
	
	return root;
}


void tree :: insert(int n) {
	node *temp;
	node *newNode = new node;
	int value;
	char direction;
	
	if (root == NULL) {
		root = newNode;
	}
	else {
		temp = root;
		while(1)
		{
			cout<<"Enter direction [l/r] : ";
			cin>>direction;
		
			if (direction == 'l' || direction == 'L') {
				if (temp -> left == NULL) {
					temp -> left = newNode;
					break;
				} else {
					temp = temp -> left;
				}
			}
			else if (direction == 'r' || direction == 'R') {
				if (temp -> right == NULL) {
					temp -> right = newNode;
					break;
				} else {
					temp = temp -> right;
				}
			}
		}
	}
}


void tree :: preorder(node *temp) {
	if (temp != NULL) {
		cout<<" "<<temp->data<<" ";
		preorder(temp -> left);
		preorder(temp -> right);
	}
}


void tree :: inorder(node *temp) {
	if (temp != NULL) {
		inorder(temp -> left);
		cout<<" "<<temp->data<<" ";
		inorder(temp -> right);
	}
}


void tree :: postorder(node *temp) {
	if (temp != NULL) {
		postorder(temp -> left);
		postorder(temp -> right);
		cout<<" "<<temp->data<<" ";
	}
}



int main() {
	tree B;
	int choice, val, n;
	node *root = NULL;
	cout<<"First create tree\n";
	root = B.create();
	
	do {
		cout<<"\n\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n9. Exit\n";
		cout<<"Enter choice : ";  cin>>choice;
		
		switch(choice) {
			case 1:
				cout<<"Enter value : ";
				cin>>n;
				B.insert(n);
				break;
				
			case 2:
				cout<<"Preorder : ";
				B.preorder(root);
				break;
				
			case 3:
				cout<<"Inorder : ";
				B.inorder(root);
				break;
				
			case 4:
				cout<<"Postorder : ";
				B.postorder(root);
				break;
		} 
	} while (choice != 9);
}
