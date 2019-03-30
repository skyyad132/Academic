#include <stdio.h>
#include <stdlib.h>

typedef struct Polynomial
{
  int Coef;
  int Pow;
  struct Polynomial *Next;
}Polynomial;




Polynomial *Insert(Polynomial *Start, Polynomial *Node)
{
  Polynomial *Temp,*Rear;
  
  if (Start == NULL) //List Empty
  {
    Start = Node;
    Start -> Next = Start;
  }
  
  else
  {
    if (Node -> Pow > Start -> Pow) //Insert At Start
    {
      Rear = Start;
      do
      {
          Rear = Rear -> Next;
      }
      while (Rear -> Next != Start); //Traversal till last node
      
      Node -> Next = Start; //Attach new node to first node
      Start = Node;         //move start pointer to new first node
      Rear -> Next = Start; //Attach last node to newly created node
    }
    
    else
    {
      Temp = Start; //Point to Ist Node
      do
      {
        if (Node -> Pow >= Temp -> Pow)
        {
          break;
        }
        
        Rear = Temp; //previous node
        Temp = Temp -> Next; //Next node
      }
      while (Temp != Start);

    
      if (Node -> Pow == Temp -> Pow) //no linking of node if pow is same
          Temp -> Coef += Node -> Coef;
      
      else if (Temp == Start) //Insert at end
      {
        Rear -> Next = Node;
        Rear = Rear -> Next;
        Rear -> Next = Start;
      }
      
      else //Insert at Middle
      {
        Node -> Next = Temp;
        Rear -> Next = Node;
      }
    }
  }
return Start;
}




//Create a Node of Polynomial
Polynomial *GetNode()
{
  Polynomial *Node;
  Node = (Polynomial *)malloc(sizeof(Polynomial));
  Node -> Next = NULL;
  return Node;
}
//Create Polynomial Circular Linked List




Polynomial *Create()
{
  Polynomial *Start = NULL, *Node;
  char ch = 'y';

  do
  {
    Node = GetNode();
    printf("\nEnter the Coef,Pow");
    scanf("%d%d", &Node -> Coef, &Node -> Pow);
    
    Start = Insert(Start,Node);
    
    printf("\nMore...(y/n)");
    scanf(" %c",&ch);
  }
  while(ch == 'y');
  
  return Start;
}




void Display( Polynomial *Start)
{
  Polynomial *Temp = Start;
  //Display Start Node
  
  printf("\n %d", Start -> Coef);
  
  if (Temp -> Pow < 0)//Power of X < 0
        printf("(1/x%d)", Start -> Pow);
  else//Power of X > 0
        printf("x^%d", Start -> Pow);
  
  
  Temp = Temp -> Next;

  while (Temp != Start)
  {
    if (Temp -> Coef < 0)
        printf(" - %d", Temp -> Coef);
    else
        printf(" + %d", Temp -> Coef);

    if (Temp -> Pow < 0)//Power of X < 0
        printf("/(x^%d)", -(Temp -> Pow));
    else//Power of X > 0
        printf("x^%d", Temp -> Pow);
  
    Temp = Temp -> Next;
  }
printf(" = 0\n");
}




struct Polynomial *Multiplication(struct Polynomial *Poly1, struct Polynomial *Poly2)
{
  struct Polynomial *Temp1 = Poly1, *Temp2 = Poly2, *Node, *Start = NULL;
  do
  {
    do
    {
      Node = GetNode();
      Node -> Pow = Temp1 -> Pow + Temp2 -> Pow;
      Node -> Coef = Temp1 -> Coef*Temp2 -> Coef;
      
      Start = Insert(Start, Node);
      Temp2 = Temp2 -> Next;
    } 
    while(Temp2 != Poly2);
    Temp1=Temp1->Next;
  }
  while (Temp1 != Poly1);
  
  return Start;
}




Polynomial *Addition(Polynomial *Poly1, Polynomial *Poly2)
{
  Polynomial *Temp1, *Temp2, *Temp, *Start = NULL, *Node;
  Temp1 = Poly1; 
  Temp2 = Poly2;
  do
  {
    Node = GetNode();
    Node -> Coef = Temp1 -> Coef;
    Node -> Pow = Temp1 -> Pow;
    Start = Insert(Start, Node);
    Temp1=Temp1->Next;
  } 
  while (Temp1 != Poly1);
  
  do
  {
    Node = GetNode();
    Node -> Coef = Temp2 -> Coef;
    Node -> Pow = Temp2 -> Pow;
    
    Start=Insert(Start,Node);
    
    Temp2 = Temp2 -> Next;
  }
  while (Temp2 != Poly2);
  return Start;
}




float Evaluation(Polynomial *Poly)
{
  Polynomial *Temp = Poly;
  int PowerX, i;
  float Sum = 0, Xvalue, spam = 1;

  printf("Enter value of X");
  scanf("%f",&Xvalue);
  do
  {
    spam = 1;
    if (Temp -> Pow < 0)
        PowerX = -(Temp -> Pow);
    else
        PowerX = Temp -> Pow;
    
    for (i = 0; i < PowerX; i++)
        spam = spam*Xvalue;   //to find the value of variable term for example x^2 or x^3 
    
    if (Temp -> Pow < 0)
        Sum = Sum + (float)((Temp -> Coef)/spam);
    else
        Sum = Sum + (Temp -> Coef)*spam;
    //term pointed by this temp is evaluated now

    Temp = Temp -> Next;  //moving the pointer to the next term 
  }
  while (Temp != Poly);
  return Sum;
}




int main()
{
  int Choice;
  Polynomial *Poly1,*Poly2,*Result;
  char ch = 'y';
  while (ch == 'y')
  {
    printf("\nENTER THE CHOICE");
    printf("\n1-ADD,\n2-MULLT\n3-EVAL\n4-EXIT");
    printf("\nENTER THE CHOICE:");
    scanf("%d",&Choice);

    switch(Choice)
    {
        case 1:
            printf("\nFirst Poly:");
            Poly1 = Create();
            Display(Poly1);
            printf("\nSecond Poly:");
            Poly2 = Create();
            Display(Poly2);
            
            Result=Addition(Poly1,Poly2);
            printf("\nTHE ADDITION IS :");
            Display(Result);
        break;
        
        case 2:
            printf("\nFirst Poly:");
            Poly1 = Create();
            Display(Poly1);
            printf("\nSecond Poly:");
            Poly2 = Create();
            Display(Poly2);
        
            Result = Multiplication(Poly1,Poly2);
            printf("\nTHE MULTIPLTCATION IS:");
            Display(Result);
        break;
        
        
        case 3:
            printf("\nPoly:");
            Poly1=Create();
            Display(Poly1);
            printf("Evaluation : %f",Evaluation(Poly1));
        break;
    }//switch case
    
    printf("\n Continue (Y/N) :");
    scanf(" %c",&ch);
  }//end of while loop
}//main function