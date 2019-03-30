#include<stdio.h>

typedef struct student
{
  int r_no;
  char name[20];
}student;


void accept(student s[20],int m)
{
  int i;
  for (i = 0; i < m; i++)
  {
    printf("\nRecord %d:- ",i+1);
    printf("\nEnter the Roll no. and Name: ");
    scanf("%d %s",&s[i].r_no,&s[i].name);
  }//end of for
}//end of accept


void display(student s[20],int m)
{
  int i;
  printf("\nRoll No.\t Name");
 
  for (i = 0; i < m; i++)
  {
    printf("\n%d \t\t %s", s[i].r_no, s[i].name);
  }//end of for
 
  printf("\n");
}//end of display


int search(student s[20],int m,int find)
{
  int i;
  for(i = 0; i < m; i++) // m records will be searched
  {
    if (s[i].r_no == find)
    return i; //Record Found
  }//end of for
  
  if (i == m)
    return -1; //Record Not Found
}//end of search


int add(student s[20],int m)
{
  printf("\nAdd a new Record ");
  printf("\nEnter Roll no. and Name : ");
  scanf("%d %s", &s[m++].r_no, &s[m].name); 
  return m;
}//end of add


void modify(student s[20],int m)
{
  int i, mod, k;
  printf("\n\nEnter Roll No. to be modified: ");
  scanf("%d", &mod);
  
  k = search(s, m, mod);
  
  if (k == -1)
    printf("\nRecord Not Found!");

  else
  {
    printf("\nRecord Found!");
    printf("\nEnter new name: ");
    scanf("%s", &s[k].name);
  }//end of else
}//end of modify


int delete(student s[20],int m)
{
  int i, del, p, q, j;
  printf("\n\nEnter Roll No. to be deleted: ");
  scanf("%d",&del);
  
  p = search(s, m, del);
  
  if (p == -1)
    printf("\nRecord Not Found!");
  
  else
  {
    //q=p+1;
    while (p < m)
    {
      s[p]=s[p+1]; //shift the record
      p++;
    }
  }
  
  m = m - 1;
  return m;
}

int main()
{
  student s[20];
  int ch;
  int a;
  int m,find,loc,w;
 
  printf("\nEnter the total no. of records: ");
  scanf("%d",&m);
 
  printf("\nEnter the roll no. & name of each record: ");
  accept(s,m);//Accept
 
  do
  {
    printf("\n1.Display\n2.Search\n3.Add");
    printf("\n4.Modify\n5.Delete");
    printf("\nEnter your choice: ");
    
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
      display(s,m);
    break;//display
    
    case 2:
      printf("\n\nEnter the roll no. to be searched: ");
      scanf("%d", &find);//Display
      loc = search(s,m,find);
      if (loc == -1)
        printf("\nNo Record Found!");
    
      else
      {
        printf("\nRecord Found!");
        printf("\nRoll No. : %d",s[loc].r_no);
        printf("\nName: %s\n",s[loc].name);
      }//end of else
    break;//end of Search
    
    case 3:
      m = add(s,m);
      display(s,m);
      break;//Add
    
    case 4:
      modify(s,m);
      printf("\nModified Record-");
      display(s,m);
    break;//Modify
    
    case 5:
      w = delete(s,m);
      printf("Record Deleted!!"); //will also print if the record not found and technically not deleted
      display(s,w);
      break;//Delete
    }
    printf("\nWould you like to continue(0/1): ");
    scanf("%d",&a);
  }while(a == 1);
}//end of main