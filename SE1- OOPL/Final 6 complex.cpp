#include<iostream>
using namespace std;

class complex
{
  private:
    int  real,img;

  public:
   	complex()							//default constructor
    { 
      real = img = 0;
    }
	  
    complex(int a,int b)						//parameterized constructor
    {
      real = a;
      img = b;
    }
    void accept();
    void display();
    friend complex operator+(complex, complex);
    friend complex operator-(complex, complex);
    complex operator*(complex c2);
    complex operator/(complex c2);
};


void complex::accept()
{
   cout<<"\n Enter real & Img:";
   cin>>real>>img;
}


void complex::display()
{
    cout<<"\n"<<real<<"+"<<img<<"i";
}


complex operator+(complex c1, complex c2)
{ 
   complex c3;
   c3.real = c1.real + c2.real;
   c3.img = c1.img + c2.img;
   return(c3);
}


complex operator-(complex c1, complex c2)
{  
   complex c3;
   c3.real=c1.real-c2.real;
   c3.img=c1.img-c2.img;
   return(c3);
}


complex complex::operator*(complex c2)
{	   complex c3;
   c3.real=(real*c2.real)-(img*c2.img);
   c3.img=(real*c2.img)+(img*c2.real);
   return(c3);
}
complex complex::operator/(complex c2)
{  	   complex c3;
   c3.real=((real*c2.real)+(img*c2.img))/((c2.real*c2.real)+(c2.img*c2.img));
   c3.img=(-(real*c2.img)+(img*c2.real))/((c2.real*c2.real)+(c2.img*c2.img));
   return(c3);
}

int main()
{  int ch;
   complex c1,c2,c3;
   cout<<"\nEnter first complex number=";
    c1.accept();
   cout<<"\nEnter second complex number=";
    c2.accept();
   cout<<"\nFirst complex number=";
    c1.display();
   cout<<"\nSecond complex number=";
    c2.display();

do
{      cout<<"\n1.+ operation\n2.- operation\n3.* operation\n4./ o peration";
      cout<<"\nEnter your choice:";	      cin>>ch;
switch(ch)
{	case 1:		c3=c1+c2;
			//c3= operator+  (c1,c2);
			//c5=c1+c2+c3+c4;
			//c5=c1.operator+(c2.operator+(c3.operator+(c4)));
			c3.display();
			break;
	case 2:		c3=c1-c2;
			//c3= operator-  (c1,c2);
			c3.display();
			break;
	case 3:		c3=c1*c2;
			//c3= c1.operator* (c2);
			c3.display();
			break;
	case 4:		c3=c1/c2;
			//c3= c1.operator/ (c2);
			c3.display();
			break;
}
}while(ch<5);
}
