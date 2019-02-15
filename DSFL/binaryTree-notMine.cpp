#include<iostream>
#include<stdio.h>
#include<ctype.h>
using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
 };
 node *root;
 
 class tree
 {
   public:
   
   tree()
   {
     root=NULL;
   }
    node *create();
    void insert(int);
    void preorder(node*);
    void inorder(node*);
    void postorder(node*); 
    node *copy(node*);
    int isempty();
    void dfs();
  };
  
node* tree::create()
{
  
  node*temp;
  int val;
  char dir,ans;
  
  do
  {
   node *nnode=new node;
  cout<<"enter value";
  cin>>val;
  nnode->data=val;

        if(root==NULL)
         root=nnode;
         else
         {
             cout<<"enter direction(l/r)";
            cin>>dir;

           temp=root;
           
         
           
            if(dir=='l'||dir=='L')
            {
              if(temp->left==NULL)
              {
                temp->left=nnode;
               }
               else
                 temp=temp->left;
              }
               else if(dir=='r' || dir=='R')
               {
                 if(temp->right==NULL)
               {
               temp->right=nnode;

              }
               else
              temp=temp->right;
             } 
             }
             
             
             cout<<"want to continue(y/n)";
             cin>>ans;
           } 
           while(ans=='Y'|| ans=='y');
           return root;
       } 
       
       void tree::insert(int n)
       {
         node*temp;
         node*nnode=new node;
         int val;
         char dir;
         if(root==NULL)
         root=nnode;
         else
         {
           temp=root;
           
            if(dir=='l'||dir=='L')
            {
              if(temp->left==NULL)
              {
                temp->left=nnode;
                //nnode->data=val;
               }
               else
                 temp=temp->left;
              }
            else if(dir=='r' || dir=='R')
            {
           
            if(temp->right==NULL)
            {
               temp->right=nnode;
              // nnode->data=val;
              }
              else
              temp=temp->right;
             } 
           }
           }
       void tree::preorder(node *temp)                                           
       {
          if(temp!=NULL)
          {
            cout<<temp->data;
            preorder(temp->left);
            preorder(temp->right);
           }
         }
         
         void tree::inorder(node *temp)                                           
       {
          if(temp!=NULL)
          {
            
            inorder(temp->left);
            cout<<temp->data;
            inorder(temp->right);
           }
         }
         
          void tree::postorder(node *temp)                                           
       {
          if(temp!=NULL)
          {
            
            postorder(temp->left);
            postorder(temp->right);
            cout<<temp->data;
           }
         }
         node* tree::copy(node *temp)
         {
            node*temp1;
            temp1->data=temp->data;
            temp1->left=copy(temp->left);
            temp1->right=copy(temp->right);
            return temp1;
         }
         /*int tree:: isempty()
         {
           if(front==NULL)
           return 0;
           return 1;
         }  
         void tree::dfs()
         {
           node *stk[20];
           node *front;
           int top;
           
           if(isempty())
           {
             cout<<"empty tree";
            } */
           
       int main()
       {
         tree b;
         int ch,val,n;
         node *Root=NULL,*Root1=NULL;
         cout<<"1.insert\n2.preorder display\n3.inorder\n4.postorder\n5.copy of tree\n6.dfs";
         cout<<"\nenter choice";
         cin>>ch;
         Root=b.create();
         do
         {
         
         switch(ch)
         {
           case 1:cout<<"enter value";
                  cin>>n;
                  b.insert(n);
                  break;
                  
           case 2:
                   cout<<"preorder:";       
                   b.preorder(Root);
                   break;
           case 3:cout<<"inorder:";
                  b.inorder(Root);
                  break;
           case 4:cout<<"postorder:";
                  b.postorder(Root);
                  break;
           case 5:cout<<"copy of tree";       
                   Root1=b.copy(Root);
                   b.preorder(Root1);
                   
                   
          }
          }while(ch>5);
         }          
