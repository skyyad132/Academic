#include <iostream>

using namespace std;

template <class t> 
class matrix
{
  t mat[10][10];
  int row,col;
  
  public:
    matrix(int r,int c)  //parameterized constructer
    {
      row = r;
      col = c;
    }
    
    void accept();
    void display();
    matrix add(matrix);
    matrix sub(matrix);
    matrix mul(matrix);
    matrix transpose();
};


template <class t> 
void matrix<t>::accept()
{
  int i, j;
  cout<<"\nenter the matrix\n";
  for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
    {
      cin>>mat[i][j];
    }
  }
}


template <class t> 
void matrix<t>::display()
{
  int i,j;
  cout<<"\nmatrix:-";
  for (i = 0; i < row; i++)
  {
    cout<<"\n";
    for (j = 0; j < col; j++)
    {
      cout<<"  "<<mat[i][j];
    }
  }
}


template <class t> 
matrix<t> matrix<t>::add(matrix<t> b)
{
  int i,j;
  matrix<t> c(row,col);
  for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
    {
      c.mat[i][j] = mat[i][j] + b.mat[i][j];
    }
  }
return c;
}


template <class t> 
matrix<t> matrix<t>::sub(matrix<t> b)
{
int i,j;
matrix<t> c(row,col);
for (i=0;i<row;i++)
{
for (j=0;j<col;j++)
{
c.mat[i][j]=mat[i][j]-b.mat[i][j];
}
}
return c;
}


template <class t> matrix<t> matrix<t>::mul(matrix<t> b)
{
int i,j,k,c1=col;
matrix<t> c(row,col);
for (i=0;i<row;i++)
{
for (j=0;j<col;j++)
{
c.mat[i][j]=0;
for(k=0;k<c1;k++)
c.mat[i][j]=c.mat[i][j]+mat[i][j]*b.mat[i][j];
}
}
return c;
}


template <class t>
matrix<t> matrix<t>::transpose()
{
int i,j;
matrix<t> c(row,col);
for (i=0;i<row;i++)
{
for (j=0;j<col;j++)
{
c.mat[i][j]=mat[j][i];
}
}
return c;
}


int main()
{
int r1, c1, r2, c2, choice1, choice2, choice;
cout<<"\nenter the no. of rows and columns of matrix 1:-";
cin>>r1>>c1;
cout<<"\nenter the no. of rows and columns of matrix 2:-";
cin>>r2>>c2;


do
{  
  cout<<"\n1.integer\n2.float\n\n0.exit"; 
  cin>>choice; 

  switch(choice)
  {     
    case 1:
    {    
      matrix<int> A(r1,c1),B(r2,c2),ans(r1,c1);
      //matrix<float> A(r1,c1),B(r2,c2),ans(r1,c1);
      A.accept();
      B.accept();
      //A.display();
      //B.display();
      do
      { 
        cout<<"\n1.addition\n2.subtraction\n3.multiplication A*B\n4.multiplication B*A\n5.transpose of matrix 1\n6.transpose of matrix 2\n\n0.exit";
        cin>>choice1;
        switch(choice1)
        {
          case 1:
            if ( (r1 == r2) && (c1 == c2) )
            {
              ans = A.add(B);
              ans.display();
            }
            else
              cout<<"\n invalid entry";
            break;
            
          case 2:
             if((r1==r2)&&(c1==c2))
            {
              ans=A.sub(B);
              ans.display();
              }
              else
              cout<<"\n invalid entry";
              break;
          
          case 3:
              if(c1==r2)
              {
              ans=A.mul(B);
              ans.display();
              }
              else
              cout<<"\n invalid entry";
              break;
          case 4:
             if(c2==r1)
              {
              ans=B.mul(A);
              ans.display();
              }
             else
              cout<<"\n invalid entry";
              break;
          
          case 5:
              ans = A.transpose();
              ans.display();
              break;
          
          case 6:
              ans = B.transpose();
              ans.display();
              break;
              }  
              }while(choice1<7&&choice1>0);
      }
              break;
      case 2: 
              { 
              //matrix<int> A(r1,c1),B(r2,c2),ans(r1,c1);
              matrix<float> A(r1,c1),B(r2,c2),ans(r1,c1);
              A.accept();
              B.accept();
              //A.display();
              //B.display();
          
           do
              {   
              cout<<"\n1.addition\n2.subtraction\n3.multiplication\n4.multiplication B*A\n5.transpose of matrix 1\n6.transpose of matrix 2\n\n0.exit";
              cin>>choice1;
              switch(choice1)
              {
              case 1:
              if((r1==r2)&&(c1==c2))
              {
              ans=A.add(B);
              ans.display();
              }
              else
              cout<<"\n invalid entry";
              break;
              case 2:
              if((r1==r2)&&(c1==c2))
              {
              ans=A.sub(B);
              ans.display();
              }
              else
              cout<<"\n invalid entry";
              break;
              case 3:
              if(c1==r2)
              {
              ans=A.mul(B);
              ans.display();
              }
              else
              cout<<"\n invalid entry";
              break;
              case 4:
              if(c2==r1)
              {
              ans=B.mul(A);
              ans.display();
              }
              else
              cout<<"\n invalid entry";
              break;
              case 5:
              ans=A.transpose();
              ans.display();
              break;
              case 6:
              ans=B.transpose();
              ans.display();
              break;
              }  
              }while(choice1<7&&choice1>0);
                }
    }
    }while(choice<3&&choice>0);     
    return 0;
}
