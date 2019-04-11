#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Student
{
  char Name[10];
  char Addr[20];
  int Roll_No;
  int Div;

public:
  Student()  
  {
    Name[0] = '\0';
    Addr[0] = '\0';
    Roll_No = -1;
    Div = -1;
  }
  void get_Data();
  void put_Data();
  int return_roll() {return Roll_No;}
};

void Student::get_Data()
{
  cout << "\nEnter Student Data";
  cout << "\nName : ";
  cin >> Name;
  cout << "\nAddress : ";
  cin >> Addr;
  cout << "\nRoll Number : ";
  cin >> Roll_No;
  cout << "\nDiv(1/2) : ";
  cin >> Div;
}

void Student::put_Data()
{
  cout << "\n"
       << Div << "\t" << Roll_No << "\t" << Name << "\t" << Addr;
}


class Seq_File
{
  char File_Name[15];

public:
  void Create();
  void Display();
  void Add();
  void Remove(int);
  int Search(int);
  void modify(int);
};


void Seq_File::Create()
{
  ofstream File;
  Student S;
  int i, n;
  cout << "Enter file name : ";
  cin >> File_Name;

  File.open(File_Name, ios::out); // or can use ios::app to append

  if (File)
  {
    cout << "How many student to add? : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
      S.get_Data();
      File.write((char*)(&S), sizeof(S));
    }
    File.close();
  }
  else
  {
    cout << "\nFile creation error";
  }
}


void Seq_File::Display()
{
  ifstream File;
  Student S;
  File.open(File_Name);
  if (File)
  {
    cout << "\n Student Database\nDiv\tRoll No\tName\tAddress";
    File.read((char*)(&S), sizeof(S));
    while (!File.eof())
    {
      S.put_Data();
      File.read((char*)(&S), sizeof(S));
    }
    File.close();
  }
  else
  {
    cout << "File opening error\n";
  }
}


void Seq_File::Add()
{
  ofstream File;
  Student S;
  File.open(File_Name, ios::app);
  if (File)
  {
    S.get_Data();
    File.write((char*)(&S), sizeof(S));
    File.close();
  }
  else
  {
    cout << "File opening error";
  }
}

void Seq_File::Remove(int Roll)
{
  ifstream File;
  ofstream Temp;
  Student S;
  int flag = 0;
  
  File.open(File_Name);
  Temp.open("temp.txt");

  if (File && Temp)
  {
    File.read((char*)(&S), sizeof(S));
    while (!File.eof())
    {
      if (Roll == S.return_roll())  // if we find a match, don't put it in temp
      {
        S.put_Data();
        flag = 1;
      }
      else // if no match, put it in temp as it is
      {
        Temp.write((char*)(&S), sizeof(S));
      }
      // then read the next record from the original file
      File.read((char*)(&S), sizeof(S));
    }//while
    
    if (flag == 0)
    {
      cout << Roll <<  " is not present in data\n";
    }

    File.close();
    Temp.close();
    remove(File_Name);
    // remove() This is an operation performed directly on a file identified by its filename;
    // No streams are involved in the operation.
    // returns 0 if deleted successfully

    rename("Temp.txt", File_Name);
  }//if file opened successfully

  else
  {
    cout << "File opening error\n";
  }
}


void Seq_File::modify(int Roll)
{
  ifstream file;
  ofstream temp;

  Student S;
  int flag = 0;

  file.open(File_Name);
  temp.open("Temp.txt");

  if (file && temp)
  {
    file.read((char*)(&S), sizeof(S));
    while(!file.eof())
    {
      if (Roll == S.return_roll())
// if entry to be modified is found, then modify it and add to temp file
      {
        S.get_Data();
        temp.write((char*)(&S), sizeof(S));
        flag = 1;
      }
      else // if entry to be modified is not found, then write it as it is.
      {
        temp.write((char*)(&S), sizeof(S));
      }
      file.read((char *)(&S), sizeof(S));
    }//while
    
    if (flag == 1)
    {
      cout << "Modified successfully\n";
    }
    file.close();
    temp.close();
    remove(File_Name);
    rename("Temp.txt", File_Name);
  }//if opened successfully
  else
  {
    cout << "File opening error";
  }
}//function modify

int Seq_File::Search(int Roll)
{
  ifstream file;
  Student S;

  int flag = 0;

  file.open(File_Name);
  
  if (file)
  {
    file.read((char*)(&S), sizeof(S));
    while (!file.eof())
    {
      if (S.return_roll() == Roll)
      {
        S.put_Data();
        flag = 1;
      }
      file.read((char*)(&S), sizeof(S));
    }//while
    file.close();
  }//file successful
  else
  {
    cout << "File opening error \n";
  }
  
  return flag;
}//function


int main()
{
  int ch;
  char f[15];
  int r;

  Seq_File sfile;

  do
  {
    cout << "\n1. Create Database\n"
    << "2. Display Database\n"
    << "3. Add a record\n"
    << "4. Delete a record\n"
    << "5. Search a record\n"
    << "6. Modify a record\n"
    << "9. Exit\n"
    << "Enter your choice: ";
    cin >> ch;

    switch(ch)
    {
      case 1:
        sfile.Create();
        break;
      case 2:
        sfile.Display();
        break;
      case 3:
        sfile.Add();
        break;
      case 4:
        cout << "\nEnter roll number to be deleted : ";
        cin >> r;
        sfile.Remove(r);
        break;
      case 5:
        cout << "\nEnter roll number to be searched : ";
        cin >> r;
        if (!sfile.Search(r)) // return 0 if not found
        {
          cout << "Record not found\n";
        }
        break;
      case 6:
        cout << "\nEnter roll number to be modified : ";
        cin >> r;
        sfile.modify(r);
        break;
      case 9:
        return 0;
    }
  } while (ch != 9);
  cout << "\n";
  return 1;
}