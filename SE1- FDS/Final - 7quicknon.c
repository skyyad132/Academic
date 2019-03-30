#include<stdio.h>
void sort( int [],int ,int );
int part(int [],int,int);

 int main()
{
 int a[30],n,i;
printf("\n enter the total no. of elements");
scanf("%d",&n);
printf("\n enter the data");
for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
sort(a,0,n-1);
printf("\n sorted list is");
for(i=0;i<n;i++)
 {
  printf(" %d",a[i]);
 }
}




void sort( int a[30],int l,int u)
{
  int data[50],top=-1;
  int j;
 
 while(l<u)
 {
  j=part(a,l,u);
  data[++top]=j+1;
  data[++top]=u;
 u=j-1;
   }
while(top>-1)
{
  u=data[top--];
  l=data[top--];
 
 while(l<u)
 {
  j=part(a,l,u);
  data[++top]=j+1;
  data[++top]=u;
 u=j-1;
 }  }
}




int part(int a[30],int l,int u)
{
  int v,i,j,temp;
v=a[l];
i=l;
j=u+1;
 do
   {
    do
       i++;
       
     while(a[i]<v && i<=u);
       do
     {  j--;}
        while(v<a[j]);
          
      if(i<j)
         {
          temp=a[i];
          a[i]=a[j];
           a[j]=temp;
        }
 }while(i<j);
a[l]=a[j];
a[j]=v;
return j;
}