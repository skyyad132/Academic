#include <stdio.h>
#include <string.h>

void accept(char string[20][20], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("Enter the string : ");
    scanf("%s", string[i]);
  }
}




void display(char string[20][20], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("\n%s", string[i]);
  }
}





int binary(char string[20][20], int n, char key[20])
{
  int low, mid, high;

  low = 0;
  high = n - 1;
  
  while (high >= low)
  {
    mid = (high + low)/2;

    if (strcmp(string[mid], key) == 0)
      return mid;
    
    else if (strcmp(string[mid], key) > 0)  //means middle string is greater than key, so key must lie in left side
      high = mid - 1;

    else  
      low = mid + 1;
  }
  return -1;
}





int binaryRecursion(char string[20][20], int low, int high, char key[20])
{
  int mid;

  if (high < low)
    return -1;

  mid = (high + low)/2;

  if (strcmp(string[mid], key) > 0)
        return binaryRecursion(string, low, mid - 1, key);
  
  else if (strcmp(string[mid], key) < 0)
        return binaryRecursion(string, mid + 1, high, key);

  else 
        return mid;
}




int main()
{
  char string[20][20], key[20];
  int n,result;
  
  printf("\nenter the number of elements : \n");
  scanf("%d", &n);
  
  accept(string, n);
  display(string, n);
  
  printf("\nenter the name you want to search : \n");
  scanf("%s", key);
  
  result = binary(string, n, key);
  
  if (result == -1)
    printf("\nrecord not found");
  
  else
  {
    printf("\nthrough non-recursive function : \n");
    printf("%s found at %d location\n", string[result], (result + 1));
  }
  
  result = binaryRecursion(string, 0, n-1, key);
  
  if (result == -1)
    printf("\nrecord not found");

  else
  {
    printf("\nthrough recursive function : \n");
    printf("%s found at %d location\n", string[result], (result + 1));
  }
}