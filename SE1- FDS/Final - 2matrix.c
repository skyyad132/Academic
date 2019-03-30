#include <stdio.h>


void accept(int m[10][10], int r, int c);
void display(int m[10][10], int r, int c);
void addition(int mOne[10][10], int mTwo[10][10], int mA[10][10], int r, int c);
void multiplication(int mOne[10][10], int mTwo[10][10], int mA[10][10], int r, int c);
void transpose(int m[10][10], int t[10][10], int r, int c);
int saddlePoint(int row1, int col1, int a[10][10]);


int main()
{
    int ch, m1[10][10], m2[10][10], m3[10][10], m4[10][10], tr[10][10], row, col, i, j;
    do
    {
      printf("----------------\n1.Addition\n2.Multiplication\n3.Transpose\n4.Saddle Point\n9.Exit\n");
      scanf("%d", &ch);
      printf("Give row and column size\n");
      scanf("%d%d", &row, &col);
      
      switch(ch)
          {
        case 1:
            printf("\nGive matrix one");
            accept(m1, row, col);
            printf("\nGive matrix two");
            accept(m2, row, col);
            printf("\nmatrix one\n");
            display(m1, row, col);
            printf("matrix two\n");
            display(m2, row, col);
            printf("Addition\n");
            addition(m1, m2, m3, row, col);
            display(m3, row, col);
        break;
        
        case 2:
            printf("\nGive matrix one");
            accept(m1, row, col);
            printf("\nGive matrix two");
            accept(m2, row, col);
            printf("\nmatrix one\n");
            display(m1, row, col);
            printf("matrix two\n");
            display(m2, row, col);
            printf("Multiplication\n");
            multiplication(m1, m2, m4, row, col);
            display(m4, row, col);
        break;
        
        case 3:
            printf("\nGive matrix :");
            accept(m1, row, col);
            display(m1, row, col);
            printf("Transpose of matrix is\n");
            transpose(m1, tr, row, col);
            display(tr, row, col);
        break;
        
        case 4:
            printf("\nGive matrix :");
            accept(m1, row, col);
            saddlePoint(row, col, m1);
        break;
    }
    }
    while(ch != 9);
    }//end of main


void accept(int m[10][10], int r, int c)
{
  int i,j;
  
  for(i = 0; i < r ; i++)
  {
    for(j = 0; j < c; j++)
    {
      printf("\nM[%d][%d] : ", i + 1, j + 1);
      scanf("%d",&m[i][j]);
    }
  }//outer for
  }


void display(int m[10][10], int r, int c)
{
  int i,j;
  
  for(i = 0; i < r ; i++)
  {
    printf("|");
    for(j = 0; j < c; j++)
    {
      printf(" %d ",m[i][j]);
    }//inner for
    printf("|\n");
  }//outer for
}


void addition(int mOne[10][10], int mTwo[10][10], int mA[10][10], int r, int c)
{
  int i,j;
  
  for(i = 0; i < r; i++)
  {
    for(j = 0; j < c; j++)
    {
      mA[i][j] = mOne[i][j] + mTwo[i][j];
    }//end of inner for
  }//end of outer for
}//end of function


void multiplication(int mOne[10][10], int mTwo[10][10], int mM[10][10], int r, int c)
{
  int i, j, k;
  for(i = 0; i < r; i++)
  {
    for(j = 0; j < c; j++)
    {
      mM[i][j] = 0;  //initialize all to zero before proceding further
      for(k = 0; k < c; k++) // could have used k < r also because r and c should be equal
      {
        mM[i][j] = mM[i][j] + mOne[i][k]*mTwo[k][j];
      }
    }
  }//end of outer for
}//End of function of multiplication


void transpose(int m[10][10], int t[10][10], int r, int c)
{
    int i, j;
    for(i = 0; i < r; i++)
    {
      for(j = 0; j < c; j++)
      {
        t[i][j] = m[j][i];
      }
    }
}

/*To determine whether a matrix has saddle point or not, we have to first find large element from each row and store it in one dimensional array. Find small element from each column and store it in another array. Then find smallest element from the largest elements of the rows and the largest element from the smallest elements from the columns and compare them if they are equal then matrix has saddle point else matrix has no saddle point*/
int saddlePoint(int m, int n, int a[10][10])
{
  int i, j, amin[10], amax[10], max, min;

  for (i = 0; i < m; i++)
  {
    amin[i] = a[i][0];
    for (j = 1; j < n; j++)
    {
      if (amin[i] > a[i][j])
      {
        amin[i] = a[i][j];
      }
    }
  }

  for (i = 0; i < n; i++)
  {
    amax[i] = a[0][i];
    for (j = 1; j < m; j++)
    {
      if (amax[i] < a[j][i])
      {
        amax[i] = a[j][i];
      }
    }
  }

  max = amin[0];
  for (i = 1; i < m; i++)
  {
    if (max < amin[i])
    {
      max = amin[i];
    }
  }

  min = amax[0];
  for (i = 0; i < n; i++)
  {
    if (min > amax[i])
    {
      min = amax[i];
    }
  }

  if (max == min)
  {
    printf("Saddle point is : %d", max);
  }
  else
  {
    printf("Saddle point does not exist\n");
  }
}