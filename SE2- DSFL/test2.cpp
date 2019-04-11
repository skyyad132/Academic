#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

class q
{ 
	struct node
	{
		char name[20];
		int q_node_priority;
		node *next;
	};
	node *front;

	public:
		q() {front = NULL;}
		void nq(char [], int);
		void dq();
		void display();
		int isempty() {if (front == NULL) return 1; return 0;}
};

void q::nq(char name[20], int current_priority) 
{
	node *n = new node;
	node *temp, *prev;
	strcpy(n -> name, name);
	n -> q_node_priority = current_priority;
	n -> next = NULL;
	if (isempty()) {front = n;}
	else
	{
		temp = front;
		while (temp != NULL && current_priority <= temp -> q_node_priority)
		{
			prev = temp;
			temp = temp -> next;
		}
		
		if (temp == front) // there was only one element in the q and its pr was less than current new node
		{
			n -> next = front;
			front = n;
		}
		
		else // there was more than element in the q 
		{
			prev -> next = n;
			n -> next = temp;
		}	
	}
}

void q::dq()
{
	if (front == NULL) 
	{
		cout << "Queue already empty.\n";
		return;
	}
	node *temp = front;
	front = front -> next;
	int x  = temp -> q_node_priority;

	switch(x) 
	{
		case 1:
			cout << "\nGeneral checkup\n";
			break;
		case 2:
			cout << "\nNon-serious patient\n";
			break;
		case 3:
			cout << "\nSerious patient\n";
			break;
	}

	if (temp -> q_node_priority > 3) { cout << "\nUnknown patient\n"; }
	else { cout << "\nPatient " << temp -> name << " has been treated\n";}
	
	delete temp;
	if (temp -> next == NULL) {cout << "\nThe queue is now empty.";}
}

void q::display()
{
	if (front != NULL)
	{
		node *temp = front;
		cout << left;

		cout << "\n" << setw(10) << "Name"<<  "|" << setw(10)  << "Priority" << "|\n";
		
		for (int i = 0; i < 22; i++) {cout << "-";}
		
		while (temp != NULL)
		{
			cout << "\n" << setw(10) << temp -> name << "|" << setw(10) << temp -> q_node_priority << "|";
			temp = temp -> next;
		}
	}
	else 
	{
		return;
	}
}


int main() 
{
	q Q;
	int p, ch;
	char i;
	char n[20];

	do
	{
		cout << "\n\nEnter the choice : \n";
		cout<<"1. Enqueue\n2. Dequeue\n9. Exit\n";
		cin >> ch;
		switch(ch)
		{
			case 1:
				cout << "Enter the name : ";
				cin >> n;
				cout << "\nEnter the Priority (1. General ; 2. Non-serious ; 3. Serious) : ";
				cin >> p;
				Q.nq(n,p);
				Q.display();
				break;
			case 2:
				Q.dq();
				Q.display();
				break;
		}
	} while (ch != 9);
}