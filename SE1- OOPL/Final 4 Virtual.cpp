#include <iostream>

using namespace std;

class shape  //abstract class
{
  protected:
    double a, b;

  public:
    
    virtual void accept()
    {
      cout<<"\nEnter a & b ";
      cin>>a>>b;
    }

    virtual void area() = 0; //pure virtual function
};


class triangle : public shape
{
  public:
   
    void area()
    {
      double ans;
      ans = 0.5 * a * b;
      cout<<"\nArea of triangle : ";
      cout<<ans;
    }
};


class rectangle : public shape
{
  public:

    void area()
    {
      double ans;
      ans = a * b;
      cout<<"\nArea of rectangle : ";
      cout<<ans;
    }
};


int main()
{
  shape *ptr; //since cannot create of object of abstract class
  triangle T;
  rectangle R;
  int ch;

  do
  {
    cout<<"\nCalculate \n1. Triangle 2. Rectangle\n";
    cin>>ch;

    switch(ch)
    {
      case 1:
        ptr = &T;
        ptr->accept();
        ptr->area();
        break;

      case 2:
        ptr = &R;
        ptr->accept();
        ptr->area();
        break;

      default:
        cout<<"\nCan't you read? Enter either 1 or 2 you stupid fucking idiot\n";      
    }
  }
  while (ch < 3);
  return 0;
}