#include<stdio.h>
#include<stdlib.h>
#include<string.h>


union dataorptr
{
  char data;
  struct GLL *dwn_ptr;
};


typedef struct GLL
{
  int flag;
  union dataorptr dp;
  struct GLL *next;
}GLL;


GLL* create(char[]);
void display(GLL *);

int main()
{
  GLL *header;
  char input_str[50];
  
  printf("Enter the book index");
  scanf("%s",input_str);
  
  printf("\n\n CREATE A GLL : \n");
  header = create(input_str);
  
  printf("\n\n THE ENTERED GLL HAS BEEN ACCEPTED.");
  
  if (header == NULL)
    printf("\n\nGLL IS EMPTY \n");
  else
  {
    printf("\n\n DISPLAYING THE GLL :\n");
    display(header);
  }
  return 0;
}


//Function to create GLL .A recursive function which calls itself to create a list if down pointer is encountered
GLL* create(char input_str[])
{
  GLL *curr = NULL; // defining the local variable(s)
  static int i = 0; //To keep a track of string
  if (input_str[i] =='\0')
    return NULL;
  for (; input_str[i] == ',' || input_str[i] == ' '; i++);
    curr = (GLL *)malloc(sizeof(GLL)) ; // dynamic memory allocation
  
  if (curr == NULL ) // checking if the memory is full
  {
    printf("\n\n\t NOT ENOUGH MEMORY AVAILABLE.....TERMINATING...");
    exit(0); // if enough memory not obtained then quit
  }
  
  if (input_str[i] =='(') //Generate down link and corresponding list
  {
    curr -> flag = 1;
    curr -> next = NULL;
    i++;
    curr -> dp.dwn_ptr = create(input_str);
    
    if (input_str[i] != '\0')
      curr -> next = create(input_str);
    else
      i = 0; 
  }
  
  else if (input_str[i] != ')' && input_str[i] !=',') //Character is data
  {
    curr -> flag = 0;
    curr -> dp.data = input_str[i];
    i++;
    curr -> next = create(input_str);
  }
  
  else if (input_str[i] ==')') //if closing )
  {
    i++;
    free(curr);
    return NULL;
  }
  return curr;
}


void display(GLL *header)
{
  if(header==NULL)
  {
    return ;
  }
  
  if (header -> flag == 1)
  {
    printf("( ");
    display(header -> dp.dwn_ptr);
    printf(" )");
    
    if (header -> next != NULL)
      display(header -> next);
  }
  
  else
  {
    printf("%c ",header -> dp.data);
    display(header -> next);
  }
}