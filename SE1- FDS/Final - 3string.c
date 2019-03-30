#include<stdio.h>
#include<stdlib.h>


int length(char[20]);//function declaration
void copy(char [20],char [20]);//function declaration
void reverse(char[20],char [20],int );//function declaration
void palindrome(char[20],int );
int substring(char[20],char[20],int);
int compare_strings(char [20]);
void stringcat(char[20],int);


int main()
{
  char s[20],cop[20],rev[20],substr[20],b[20],count,compare;
  int l,choice;
  printf("enter the string:");
  scanf(" %s",s);//function call
  l = length(s);//function call
  
  while(1)
  {
    printf("\nwhat would you like to do \n1.display string length ");
    printf("\n 2.copy string");
    printf("\n 3.reverse the string");
    printf("\n 4.check if its a palindrome");
    printf("\n 5.check for a substring");
    printf("\n6.compare strings");
    printf("\n7.string concatnation ");
    printf("\n\n0.exit");
    scanf("%d",&choice);//accepts the choice from user
    switch(choice)
    {
    case 1:
      printf("\nthe length is %d",l);
      break;//stops further execution
    
    case 2:
      copy(s,cop);//calls copy function
      printf("%s",cop);
    break;
    case 3:
      reverse(s,rev,l);
      printf("%s",rev);
    break;
    
    case 4:
      palindrome(s,l);
    break;
    
    case 5:
      count = substring(s,substr,l);
      if (count>0)
        printf("the string is present %d times",count);
      else
        printf("string not present");
    break;
    
    case 6:
      compare = compare_strings(s);
      if (compare==0)
        printf("the strings are equal");
      else if (compare>0)
        printf("string 1 is greater");
      else
        printf("string 2 is greater");
      break;
    
    case 7:
      stringcat(s,l);
      break;
    default:
      exit(0);
    }//end of switch
  }//end of while
  return 0;
}//end of main


int length(char s[20])//function declaration
{
  int l=0,i;
  for(i=0;s[i]!='\0';i++)//increments l till the end of string
    l++;
  return l;
}


void copy(char s[20],char cop[20])
{
  int i;
  for(i=0;s[i]!='\0';i++)
  cop[i]=s[i];//assigns value from main string to copy,character by character
  cop[i]='\0';
  printf("copied string: ");
}


void reverse(char s[20],char rev[20],int l)
{
  int i;
  for (i = 0; i < l; i++)
   {
    rev[l-i-1]  = s[i] ;//assigns the end of string to the beginning of reverse
   } 
  
  rev[i]='\0';//to indicate the end of reverse string
  
  printf("reversed string: ");
}


void palindrome(char s[20],int l)
{
  int i;
  
  for (i = 0; i < l/2; i++)//since we compare half of the string
  { 
    if (s[i] != s[l-i-1])//if the elements from beginning and end are unequal
    break;
  }
  
  if (i == l/2)//indicates completion of the loop
    printf("\nthis is a palindrome");
  
  else
    printf("\nnot a palindrome");
}


int substring(char s[20],char substr[20],int l)
{
  int i=0,j,count=0,k;
  printf("\n enter the other string:");

  scanf("%s",substr);//accepts the substring from user
  
  for (i = 0; i < l; i++)
  {
    if (s[i] == substr[0])//scans entire string for the starting element of substring
    {
      k = i + 1;
      for(j = 1; substr[j] != '\0'; j++)
      {
        if (s[k++] != substr[j])
          {break;}
      }//end of inner for
    
    if(substr[j] == '\0')
        {count++;}
    }//end of if
}// end of outer for
return count;
}


int compare_strings(char a[20])
{
  int c = 0;
  char b[20];
  printf("enter second string: ");
  scanf("%s",b);//accepts second string
  
  while (a[c] == b[c]) //compares the two strings character by character
  {
      if (a[c] == '\0' || b[c] == '\0')//indicates end of one or both strings
      {
        break;
      }
      c++;
  }


  if (a[c] == '\0' && b[c] == '\0')//indicates equal strings
    {
      return 0;
    }
    
  else if (a[c] == '\0')
  {
    return 1;
  }
  
  else if (b[c] == '\0')
  {
    return -1;
  }

  else
  {
      return a[c] - b[c];  //returns the difference of string with reference to ASCII values
  }
}





void stringcat(char s[20],int l)
{
  int i,j;
  char b[20];
  printf("enter the second string: ");
  scanf("%s",b);
  char concat[20];
  for (i=0;i<l;i++)
  {
    concat[i]=s[i];//copies entire first string into concat
  }
  for(j=0;b[j]!='\0';j++)
  {
    concat[i+j]=b[j];//copies the entire second string in continuation to concat
  }
  concat[i+j]='\0';
  printf("th concat string is: %s",concat);//displays the concat//function call
}