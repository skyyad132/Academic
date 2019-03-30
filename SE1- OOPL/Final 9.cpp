//Assignment no.8 Sequential file operations (Binary File)
#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class Student
{
  int roll;
  char name[10];
  
  public:
    void getdata();
    void putdata();
    int return_Roll(){return roll;}
};


void Student::getdata()
{
  cout<<"\nEnter roll number & name=";
  cin>>roll>>name;
}


void Student::putdata()
{
  cout<<"\n"<<roll<<"\t"<<name;
}    


class file
{
  char fname[10];
  public:
    void Create();
    void Display();
    void Add();
    void Remove(int);
    void Modify(int);
};


void file::Create()
{
  ofstream  fp;
  Student S;
  cout<<"\nenter file name=";
  cin>>fname;
  
  fp.open(fname);
  
  S.getdata();
  
  fp.write(reinterpret_cast<char*>(&S),sizeof(S));		
  fp.close();
}






void file::Display()
{
  ifstream  fp;
  Student S;
  
  fp.open(fname);
  cout<<"\nRoll No\t Student name";
  
  fp.read(reinterpret_cast<char*>(&S),sizeof(S));
 
  while(!fp.eof())
  {
    S.putdata();
    fp.read(reinterpret_cast<char*>(&S),sizeof(S));
  }
  fp.close();
}




void file::Add()
{	
  ofstream  fp;
  Student S;
  
  fp.open(fname, ios::app);
  int i,n;
  cout<<"\nHow many records";
  cin>>n;
  for (i = 0; i < n; i++)
    {
      S.getdata();
      fp.write(reinterpret_cast<char*>(&S),sizeof(S));
    }
  fp.close();
}	



void file::Remove(int Roll)
{
  ifstream fp;
  ofstream Temp;
  
  Student S;
  
  int Flag = 0;
  fp.open(fname);
  
  Temp.open("Temp.Txt");
  
  fp.read(reinterpret_cast<char*>(&S),sizeof(S));
  
  while(!fp.eof())
  {
    if (Roll == S.return_Roll())
    {   
      Flag = 1; 
    }
    else
    {  
      Temp.write(reinterpret_cast<char*>(&S),sizeof(S)); 
    }
    fp.read(reinterpret_cast<char*>(&S),sizeof(S));
  }
  
  if (Flag == 0) 
     cout<<"Record not found";      
  
  fp.close();
  Temp.close();
  
  remove(fname);
  rename("Temp.Txt",fname); 
}




void file :: Modify(int Roll)
{
  ifstream fp;
  ofstream Temp;
  
  Student S;
  int Flag = 0;

  fp.open(fname);
  
  Temp.open("Temp.Txt");
  
  fp.read(reinterpret_cast<char*>(&S),sizeof(S));
  
  while(!fp.eof())
  {
    if(Roll == S.return_Roll())
    {
      cout<<"\n Enter data to modify";
      S.getdata();
      Flag = 1;                                
    }     
    
    Temp.write(reinterpret_cast<char*>(&S),sizeof(S));
    fp.read(reinterpret_cast<char*>(&S),sizeof(S));
  }
  
  if (Flag == 0) 
      cout<<"Record not found";      
  
  fp.close();
  Temp.close();
  
  remove(fname);
  rename("Temp.Txt",fname); 
}



int main()
{
  int ch,key;
  file ob;      	
  
  do
  {
    cout<<"\n1: Create Database\n2:Display Database\n3: Add a record\n4: Delete \n5: Modify";
    cout<<"\nEnter your choice: ";
    cin>>ch;
    
    switch(ch)
    {
      case 1:
        ob.Create();
        break;
      
      case 2:               		                
        ob.Display();
        break;
      
      case 3:
        ob.Add();
        break;
      
      case 4:
        cout<<"\nEnter Roll No to delete";
        cin>>key;
        ob.Remove(key);
        break;
      
      case 5:                                                                
        cout<<"\nEnter Roll No to Modify";
        cin>>key;
        ob.Modify(key);
        break;
    }
  }
  while(ch<6);	            
}   