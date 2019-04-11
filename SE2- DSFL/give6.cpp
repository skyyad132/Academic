#include<iostream>
#include<string.h>
// initiallize stack // while stack iss n not empty // i = pop()s) ddddoooobbbb____mmmmoooonnnntttthhhh____ooooffff____uuuusssseeeerrrr
using namespace std;
class facebook
{
	struct user
	{
		char name[20],dob[20];
		int visit,no_comments;
		user *next;
		
		user()
		{
			next=NULL;
			visit=-1;
			no_comments=0;
		}	
	}list[20];//structure
	int pos;
	
    public :
    	facebook()
    	{
    		pos=-1;
    	}
	int create();
	void display(int);
	int position(char[]);
	void dobmonth(); 
	void maxfriend();
	void comments();
	void resetflag(int);
};//class

int facebook :: position(char s[])
{
	for(int i=0;i<10;i++)
		if(strcmp(list[i].name,s)==0)
			return i;
	return -1;
}//position

int facebook :: create()
{
	user *Nnode, *Nnode1, *temp;
	
	int i = 0, pos, no_users = 0;
	char frnd[15], ans, Ans;
	
	do
	{
		cout<<"\nEnter Username : ";
		cin>>list[i].name;
		
		cout<<"Enter Date of Birth(mm/dd/yyyy) : ";
		cin>>list[i].dob;
		
		cout<<"Enter No. of Comments: ";
		cin>>list[i].no_comments;
		
		i++;
		no_users++;
		
		cout<<"\nAdd more users (Y/N) ???";
		cin>>ans;
	} while (ans == 'y' || ans == 'Y');
	

	for (i = 0; i < no_users; i++)
	{
		cout << "\nEnter friend list of user " << list[i].name;
		
		do
		{
			cout << "\nEnter friend name : ";
			cin >> frnd;
			
			pos = position(frnd);
			
			if (pos != -1)
			{
				Nnode = new user;
				Nnode -> visit = pos;
				
				for (temp = &list[i];    																// initialization
						 temp -> visit != pos && temp -> next != NULL;     	// condition
						 temp = temp -> next);															// increment/decrement
				
				if (temp -> visit != pos)
					   temp -> next = Nnode;
				
				Nnode1 = new user;
				Nnode1 -> visit = i;
				
				for (temp = &list[pos]; 
						 temp -> visit != i && temp -> next != NULL; 
						 temp = temp -> next);
				
				if (temp -> visit != i)
					temp -> next = Nnode1;
		
			}//if

			else
				cout<<"\nUser does not exist";
				
			cout<<"\nAdd more friend of the user (Y/N) ???";
			cin>>Ans;
		
		} while (Ans == 'y' || Ans == 'Y');
	}//for	
	return no_users;
}//create



void facebook :: display(int n)
{	
	user *temp;
	cout<<"\n=====  LIST OF USERS  =====";
	cout<<"\nNAME\tDate Of Birth\tComments";
	
	for (int i = 0; i < n; i++)
	{
		temp = &list[i];
		cout << "\n" << list[i].name;
		cout << "\t" << list[i].dob;
		cout << "\t" << list[i].no_comments;		
	}//for
}//display




void facebook :: dobmonth() // uses dfs
{
	user *temp;
	int top = -1, i, stk[20];
	char month[2], dob_month_of_user[3];
	
	cout << "\n\n===== Users of same birth month =====";
	cout << "\nEnter month : (01:Jan | 02:Feb | .... | 12:Dec) ";
	cin >> month;
	list[0].visit = 1;
	
	stk[++top] = 0; // initiallize stack
	
	cout << "\nUsers of birth month " << month << " are : \n";	
	while (top > -1) // while stack is not empty
	{
		i = stk[top--]; // i = pop()
		
		strncpy(dob_month_of_user, list[i].dob, 2); // 2  indicates the number of characters to be copied from source
		dob_month_of_user[2] = '\0'; 
		
		if (strcmp(dob_month_of_user, month) == 0)
			cout << list[i].name << "\n";
		
		temp = list[i].next; // go to node
		
		while (temp != NULL)
		{	
			i = temp -> visit; // go to next adjacent node
			if (list[i].visit != 1) // if not visited then add it to the stack
			{
				stk[++top] = temp -> visit;
				list[i].visit = 1;
			}//if
			temp = temp -> next;
		}//while
	}//while

}//dobmonth


void facebook :: maxfriend() // uses dfs
{
	int i, j, count, maximum = 0;
	int stk[20], top = -1, pos;
	user *temp;

	list[0].visit = 1;
	stk[++top] = 0;

	while(top>-1)
	{
		i = stk[top--];
		temp = list[i].next;

		count = 0;
		while (temp != NULL)
		{
			count++;
			j = temp -> visit;
			
			if (list[j].visit != 1)
			{
				stk[++top] = temp -> visit;
				list[j].visit = 1;
			}//if	
			temp = temp -> next;
		}//while
		if (count > maximum)
		{
			maximum = count;
			pos = i;
		}//if
	}//while
	cout<<"\nMax friends is of : "<<list[pos].name<<" : "<<maximum;
}//maxfriend





void facebook :: comments() // uses bfs i.e. queue
{
	user *temp;
	int Q[20], front = 0, rear = 0, max, min, maxuser, minuser;

	list[0].visit = 1;
	Q[0] = 0;
	
	max = min = list[0].no_comments;
	maxuser = 0;
	minuser = 0;

	while (front <= rear)
	{	
		int i = Q[front++];

		temp = list[i].next;

		while (temp != NULL)
		{
			cout << "Y";
			i = temp -> visit;
			
			if(list[i].visit != 1)
			{
				if(max < list[i].no_comments)
				{
					maxuser = i;
					max = list[maxuser].no_comments;
				}
				else if (min > list[i].no_comments)
				{
					minuser = i;
					min = list[minuser].no_comments;
				}
				Q[++rear]=i;
				list[i].visit = 1;
			}//if	
			
			temp = temp -> next;		
		}//while
		
	}//while
	cout<<"\nMax comments is of user : " << list[maxuser].name <<" : "<<max;
	cout<<"\nMin comments is of user : " << list[minuser].name <<" : "<<min;
}//comments



void facebook :: resetflag(int n)
{
	int i;

	for(i=0;i<n;i++)
		list[i].visit=0;
}//resetflag

int main()
{
	facebook fb;
	int op,num;
	char ANS;

	num=fb.create();
	fb.display(num);
	
	do
	{
	
		cout<<"\n----------------------------------------------------------------------";
		cout<<"\n*****   MENU  *****";
		cout<<"\n1. Users having same birth month";
		cout<<"\n2. User having maximum friends";
		cout<<"\n3. User having maximum and minimum no. of comments ";
		
		cin>>op;
		
		switch(op)
		{
			case 1 :
				fb.resetflag(num);
				fb.dobmonth();
				break;
				
			case 2 :
				fb.resetflag(num);
				fb.maxfriend();
				break;
				
			case 3 :
				fb.resetflag(num);
				fb.comments();
				break;
				
				
			default: cout<<"\nInvalid Input !!!";
		}//switch
		
		cout<<"\nDo more (Y/N) ???";
		cin>>ANS;
	 
	}while(ANS=='Y'||ANS=='y');	

}//main