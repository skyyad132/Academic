#include<iostream>
#include<string.h>
using namespace std;
class queue1
{
private :
    struct node
    {
        char name[20];
        int pri;
        node*next;
    };
    node*front;
public :
    queue1()
    {
        front=NULL;
    }
    void enqueue(char [],int);
    void dequeue();
    void display();
    int isempty()
    {
        if(front==NULL)
            return 1;
        return 0;
    }
};
void queue1::enqueue(char n[20],int x)
{
    node*nnode = new node,*temp,*prev;
    strcpy(nnode->name,n);
    nnode->pri=x;
    nnode->next=NULL;
    if(isempty())
        front=nnode;
    else
    {
        temp=front;
        while(temp!=NULL && temp->pri>=x)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp==front)
        {
            nnode->next=front;
            front=nnode;
        }
        else
        {
            prev->next=nnode;
            nnode->next=temp;
        }
    }
}

void queue1::dequeue()
{
    node*temp=front;
    front=front->next;
    int x=temp->pri;
    switch(x)
    {
    case 1 :
        cout<<"\nGENERAL CHECKUP\n";
        break;
    case 2 :
        cout<<"\nNON-SERIOUS PATIENT\n";
        break;
    case 3 :
        cout<<"\nSERIOUS PATIENT\n";
        break;
    }
    if(temp->pri>3)
        cout<<"Unknown Patient";
    else
            cout<<"Patient "<<temp->name<<" has been treated ";
    delete temp;
    if(temp->next==NULL)
        cout<<"\nThe list is empty\n";
}
void queue1::display()
{
    node*temp=front;
    cout<<"\nName"<<"\tPriority\n";
    while(temp!=NULL)
    {
        cout<<"\n"<<temp->name<<"\t"<<temp->pri;
        temp=temp->next;
    }
}

main()
{
    queue1 q;
    int p,ch;
    char i;
    char n[20];
        do
            {
                cout<<"Enter the choice\n";
                cout<<"1:Enqueue\n2:Dequeue\n3:Quit\n";
                cin>>ch;
                switch(ch)
                {
                    case 1 :
                    cout<<"Enter the name :";
                    cin>>n;
                    cout<<"\nEnter the Priority(1:GENERAL CHECK ; 2:NON-SERIOUS ; 3:SERIOUS )";
                    cin>>p;
                    q.enqueue(n,p);
                    q.display();
                    break;
                    case 2 :
                    q.dequeue();
                    q.display();
                    break;
                }
            cout<<"\ndo u want to conti\n";
            cin>>i;
        }while(i=='y'||i=='Y');

}
