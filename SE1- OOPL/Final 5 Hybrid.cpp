#include <iostream>
#include <string.h>
#include <stdio.h>


using namespace std;

class personal
{
  public:
    char *name = new char[20];
    char *dob = new char[20];

    void accept()
    {
      cout<<"\nEnter name : ";
      cin.getline(name, 20);
      cout<<"\nEnter date of birth : ";
      cin.getline(dob, 20);
    }

    void display()
    {
      cout<<"\nName : "<<name;
      cout<<"\nDate of birth : "<<dob;
    }
};


class academic : virtual public personal
{
  protected:
    char qual[30],grade[30];

  public:
    void accept()
    {
      cout<<"\n Enter Qualification : ";
      cin.getline(qual, 30);
      cout<<"\n Enter Grade=>";
      cin.getline(grade, 30);
    }
    
    void display()
    {
      cout<<"\nQualification :"<<qual;
      cout<<"\nGrade : "<<grade;
    } 
};


class professional:virtual public personal
{
  protected:
    int salary;
    char cmpname[30],post[30];
  
  public:
    void accept()
    {
      cout<<"\n Enter Company name=>";
      gets(cmpname);
      cout<<"\n Enter Post=>";
      gets(post);
      cout<<"\n Enter Salary=>";
      cin>>salary;
    }

    void display()
    {
      cout<<"\nCmpname=>"<<cmpname;
      cout<<"\nPost=>"<<post;
      cout<<"\nSalary=>"<<salary;
    }
};


class biodata : public academic, public professional
{
  public:
    void accept()
    {
      personal :: accept();
      academic :: accept();
      professional :: accept();
    }
    
    void display()
    {
      personal::display();
      academic::display();
      professional::display();
      cout<<"\n\n";
    }
    
    int search(char key[30])
    {
      if (strcmp(name, key) == 0)
        return 1;
      else
        return 0;    
    } 
};



int main()
{
  biodata B[30];
  int i, n, ch;
  char key[30];
  do
  {  
    cout<<"\n1.Create\n2:Display\n3:Insert new entry \n4.Search\n5.Modify \n6.Delete Record";
    cout<<"\n Enter your choice : ";	
    cin>>ch;
    
    switch(ch)
    {
      case 1: 
        cout<<"\n Enter number of records : ";
        cin>>n;
        for (i = 0; i < n; i++)
            B[i].accept();
        break;
    
      case 2:
        cout<<"\nBio Data : ";
        for (i = 0; i < n; i++)
            B[i].display();
        break;
    
      case 3:
        B[n++].accept();
        break;

      case 4: 
        cout<<"\nEnter person name to search";
        gets(key);
        for (i = 0; i < n; i++)
        {
          if (B[i].search(key) == 1)
          { 
            cout<<"\nRecord found";	
            B[i].display();
             break;
          }
        }
        
        if (i == n) 
            cout<<"\nrecord does not present";		 
        break;
    
      case 5: 
        cout<<"\nEnter person name to modify";
        gets(key);
        for (i = 0; i < n; i++)
        {
          if (B[i].search(key) == 1)
          {    
            B[i].accept();
            break;
          }
        }
        if (i == n) 
          cout<<"\nrecord does not present";		 
        break;

      case 6: 
      cout<<"\nEnter person name to delete";
      gets(key);
      for (i = 0; i < n; i++)
      {
        if(B[i].search(key) == 1)
        { 
          for ( ; i < n; i++)
          B[i] = B[i+1];
          n--;
        }
      }//for
      
      if (i ==n) 
          cout<<"\nrecord does not present";		 
      break;
    }
  }
  while (ch < 7);
}
