		//Assignment no. 2 Book database
#include<iostream>
#include <string.h>

using namespace std;

class Book
{
	char *Name,*Author,*Publisher;
	int Stock,n;
	float Price;
	static int valid_transactions;

  public:
	  Book()   //default constructer
	{
		Name = new char[0];
		Author = new char[0];
		Publisher = new char[0];
		Stock = Price = 0;
	}
	
  void Accept();
	void Display();
	int Search(char key[20]);
	void Update();
	void Purchase(int);
	
  static void Transactions()
	{
		cout<<"\nSuccessful transaction count= "<<valid_transactions;
	}
};


int Book :: valid_transactions = 0;


void Book::Accept()
{
	cout<<"\nEnter Book data";
	cout<<"\nBook Name: "; cin>>Name;
	cout<<"\nAuthor: ";    cin>>Author;
	cout<<"\nPublisher: "; cin>>Publisher;
	cout<<"\nPrice: ";     cin>>Price;
	cout<<"\nStock: ";     cin>>Stock;
}


void Book::Display()
{
    cout<<"\n"<<Name<<"\t"<<Author<<"\t"<<Publisher<<"\t"<<Price<<"\t"<<Stock;
}


int Book :: Search(char key[20])
{
	if(strcmp(Name,key)==0)
		return 1;
	else
		return 0;
}


void Book :: Update()
{
	int ch;
	cout<<"\nUpdate: 1:Stock 2:Price";
	cin>>ch;
	if (ch == 1)
	{
	  cout<<"\nEnter new stock";
	  cin>>ch;
	  Stock = Stock + ch;
	}
	else
	{
		cout<<"\nEnter new Price";
		cin>>Price;
	}
}


void Book :: Purchase(int N)
{
  if (N <= Stock)
	{
	  cout<<"\nTotal Price of Books: "<<N*Price;
	  Stock-=N;
	  valid_transactions++;
	}
  else 
    cout<<"\nBook out of Stock";
}


int main()
{
  int ch, n, i, No;
  Book B[25];
  char key[20];
  do
  {
    cout<<"\n1:Accept\n2:Display\n3:Insert\n4:Search\n5:Update\n6:Purchase\n7:Valid transactions";
    cout<<"\nEnter the choice : ";
    cin>>ch;
    switch(ch)
    {
      case 1:
        cout<<"\nEnter number of records=";
        cin>>n;
        for (i = 0; i < n; i++)
          B[i].Accept();
        break;
      
      case 2:
        cout<<"\nBook data";
        cout<<"\nName\tAuthor\tPublisher\tPrice\tStock";
        for (i = 0; i < n; i++)
            B[i].Display();
        break;

      case 3:
        cout<<"\nAdd New Book Data=";
        B[n++].Accept();
        break;

      case 4:
        cout<<"\nEnter Book name to Search ";
        cin>>key;
        for (i = 0; i < n; i++)
        {
          if(B[i].Search(key) == 1)
          {
            cout<<"\nBook present";
            B[i].Display();
            break;
        }
        }
        if (i == n)
            cout<<"\nBook does not present";
        break;
      
      case 5:
        cout<<"\nEnter Book name to Update ";
        cin>>key;
        for (i = 0; i < n; i++)
        {
          if(B[i].Search(key) == 1)
          {
            //B[i].Accept();   //Modify complete record
            B[i].Update();
            break;
          }
        }
        
        if (i == n)
            cout<<"\nBook does not present";
        break;

      case 6:
        cout<<"\nEnter Book name to purchase ";
        cin>>key;
        cout<<"\nEnter Number of Books Customer Purchased";
        cin>>No;
        for (i = 0; i < n; i++)
        {
          if(B[i].Search(key) == 1)
          {
            B[i].Display();
            B[i].Purchase(No);
            break;
          }
        }
        
        if (i == n)
        cout<<"\nBook does not present";
        break;

      case 7:
        Book :: Transactions();
        break;
    }
  }
  while (ch < 8);
}

