#include <stdio.h>

void accept(int set[40], int size);
void display(int set[40], int size);
void intersection(int set1[40], int set2[40], int C[40], int size1, int size2);
void unionset(int set1[40], int set2[40], int C[40], int size1, int size2);
int difference(int set1[40], int set2[40], int C[40], int size1, int size2);
void symdifference(int set1[40], int set2[40], int C[40], int size1, int size2);
int main()
{

int ch,i,j,m,n;
int A[40], B[40], in[40], un[40], diff1[40],diff2[40],sydiff[40], size1, size2;
do
{
    printf("---------------------\n1.Accept sets\n2.Display Sets\n3.Union\n4.Intersection\n5.Difference\n6.Symmetric Difference\n9.Exit\n");
    scanf("%d", &ch);
    getchar();

    switch(ch)
    {
      case 1:
          printf("Enter number of elements in Set A\n");
          scanf("%d",&m);
          printf("Enter number of elements in Set B\n");
          scanf("%d",&n);
          accept(A,m);
          accept(B,n);
      break;

      case 2:
          printf("\n-------------------\nA : ");
          display(A,m);
          printf("\n");
          printf("B : ");
          display(B,n);
          printf("\n");
      break;

      case 3:
          printf("Union : ");
          unionset(A, B, un, m, n);
          printf("\n");
      break;

      case 4:
          printf("Intersection : ");
          intersection(A, B, in, m, n);
          printf("\n");
      break;

      case 5:
        printf("Difference A-B : ");
        size1 = difference(A, B, diff1, m, n);
        display(diff1, size1);
        printf("\n");
        printf("Difference B-A : ");
        size2 = difference(B, A, diff2, n, m);
        printf("\n");
        display(diff2,size2);
      break;

      case 6:
        size1 = difference(A, B, diff1, m, n);
        size2 = difference(B, A, diff2, n, m);
        printf("Symmetric Difference : ");
        symdifference(diff1, diff2, sydiff, size1, size2);
      break;
    }
  } 
  while(ch != 9);
}


void accept(int set[20], int size)
{
  int i;
  printf("Now enter the distinct elements of set\n");
  for (i = 0; i < size; i++) 
  {
    scanf("%d",&set[i]);
  }
}


void display(int set[20], int size)
{
  int i;
  printf(" {");
  for (i = 0; i < size - 1; i++) 
  {
    printf("%d,",set[i]);
  }
  printf("%d}\n",set[i]);
}


void intersection(int set1[20], int set2[20], int C[20], int size1, int size2)
{
  int l = 0,i,j;
  
  for(i = 0; i < size1; i++)
  {
    for(j = 0; j < size2; j++)
    {
      if(set1[i] == set2[j])
      {
        C[l++] = set1[i];
        break;
      } //end of condition
    }//end of inner for
  }//end of outer for
display(C,l);
}


void unionset(int set1[20], int set2[20], int C[20], int size1, int size2)
{
  int l = 0, i, j;
  
  for (i = 0; i < size1; i++)
  {
    C[l] = set1[i];
    l++;
}
//Finding B - A
for (i = 0; i < size2; i++)
{
  for (j = 0; j < size1; j++)
  {
    if (set2[i] == set1[j])
    {
      break;
    }
  }
  if (size1 == j)
    {
      C[l] = set2[i];
      l++;
    }
}
display(C,l);
}

int difference(int set1[20], int set2[20], int C[20], int size1, int size2)
{
  int l = 0,i,j,symSize;
  
  for(i = 0; i < size1; i++)// loop for A
  {
    for(j = 0; j < size2; j++)
    {
      if(set1[i] == set2[j])
      {
       break;
      } //end of condition
    }//end of inner for
    if  (j == size2)
    {
      C[l++] = set1[i];
    }//end of condition
  }//end of outer for  
  return l;
}
void symdifference(int set1[20], int set2[20], int sydiff[20], int size1, int size2)
{
  unionset(set1, set2, sydiff, size1, size2);
}