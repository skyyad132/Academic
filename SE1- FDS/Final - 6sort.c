#include<stdio.h>
#include<string.h>




void accept(char string[20][20],int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("\n enter the string:-");
    scanf("\n%s", string[i]);
  }
}//end of accept




void display(char string[20][20], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("\n%s",string[i]);
  }
}//end of display




void bubblesort(char s[20][20],int n)
{
  char temp[20];
  int i, j, flag = 0, pass;
  printf("\nlist after");
  
  for (pass = 0; pass < n - 1; pass++)      //no. of passes
  {
    flag = 0;
    for (j = 0; j < (n - pass - 1); j++)    //no. of comparisons
    {
      if (strcmp(s[j], s[j+1]) > 0)
      {
        strcpy(temp, s[j]);
        strcpy(s[j], s[j+1]);
        strcpy(s[j+1], temp);               //pushes the heavier bubble towards the end of the list
        flag = 1;
      }//end of if
    }//end of inner for
    
    printf("\n pass %d", pass + 1);
    display(s, n);
    printf("no. of comparisons:-%d", j);  //number of comparisons not swaps
    
    if(flag == 0)
    break;//indicates the list is sorted
  }//end of outer for
}//end of bubblesort




void selection(char x[20][20],int n)
{
  char min[20], temp[20], com = 0;
  int k, j, index,i;

  for (i = 0; i < n - 1; i++)
  {
    strcpy(min, x[i]);
    com = 0;
    index = i;
    
    for (j = i + 1; j < n; j++, com++)
    {
      if (strcmp(min, x[j]) > 0)    //finding lowest
      {
        strcpy(min,x[j]);
        index = j;
      }  //end if
    }//end of inner for
   
   
    strcpy(temp,x[i]);
    strcpy(x[i],x[index]);
    strcpy(x[index],temp);
    printf("\n pass %d:",i+1);
    display(x,n);
  }//end of outer for
}//end of selection




void main()
{
int n;
char s[20][20];
printf("\nenter the no. of elements:-");
scanf("%d",&n);
accept(s,n);
display(s,n);
printf("\nentering selection sort:-");
selection(s,n);
printf("\nsorted list through selection sort:-");
display(s,n);
printf("\nentering bubble sort:-");
bubblesort(s,n);
printf("\nsorted list through bubble sort:-");
display(s,n);
}//end of main()