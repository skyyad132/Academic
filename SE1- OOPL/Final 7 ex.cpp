#include<iostream>
using namespace std;

class test
{
	double x,y;
public:
	void accept()
	{
		 cout<<"Enter two numbers";
		 cin>>x>>y;
	}
	void divide()
	{
		try
		{
    		if (y == 0)
						throw(y);
				else  	
						cout<<"Division is:"<<x/y;
		} 
		catch(double p)
   		{
    			cout<<"Divide by zero exception: "<<p;
		}
	}
};

int main()
{
     test ob;
     ob.accept();
     ob.divide();
}