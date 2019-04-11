/*Dijkstra Algorithm*/
/*Input*/

#include <iostream>
#include <string.h>
using namespace std;

class graph
{
  char Vnames[10][10]; // 10 vertex name strings each with size of 10 characters long
  int i, j, nodes, cost[10][10], flag[10];

public:
  graph();
  int Position(char S[10]);
  void creat_graph();
  void display();
  void Dijkstra();
};


graph::graph() // default constructor
{
  nodes = 0;
  for (i = 0; i < 10; i++)
  {
    flag[i] = 0;
  }
  // cost matrix initial fillingss
  for (i = 0; i < 10; i++)
    for (j = 0; j < 10; j++)
    {
      if (i == j)
        cost[i][j] = 0;
      else
        cost[i][j] = 999; // some random high number since we can't represent infinity programatically
    }
}


void graph::creat_graph()
{
  char ans, Start[10], End[10];
  int wt, i, j;

  cout << "Enter number of nodes : ";
  cin >> nodes;
  cout << "\nEnter vertex names : \n";
 
  for (i = 0; i < nodes; i++)
  {
    cin >> Vnames[i];
    flag[i] = 0;
  }

  cout << "Time to add Weights between vertices";
  do
  {
    cout << "\n\nEnter First Vertex : ";
    cin >> Start;
    cout << "Enter Second vertex : ";
    cin >> End;
    cout << "Enter weight";
    cin >> wt;
    i = Position(Start);
    j = Position(End);
    cost[j][i] = cost[i][j] = wt;
    cout << "\nDo you want to add more(Y/N):  ";
    cin >> ans;
  } while (ans == 'y' || ans == 'Y');
} // end of create function



void graph::display()
{
  int i, j;
  for (i = 0; i < nodes; i++)
  {
    cout << "\n";
    for (j = 0; j < nodes; j++)
      cout << "\t" << cost[i][j];
  }
}




int graph::Position(char S[10])
{
  int i;
  for (i = 0; i < 10; i++)
    if (strcmp(Vnames[i], S) == 0)
      break;
  return i;
}





void graph::Dijkstra()
{
  int x;
  int dis[10] = {0};
  int visit[10] = {0};
  int flag[10] = {0};
  int i, j, v, sor, min, mnode, k;
  char Start[10];

  cout << "\nEnter Source: ";
  cin >> Start;
  sor = Position(Start);
  flag[sor] = 1; //init.
  dis[sor] = 0;

  for (v = 0; v < nodes; v++) // initial distance matrix
  {
    dis[v] = cost[sor][v];
  }
  visit[0] = sor;

  i = 0;
  cout << "\n";
  for (x = 0; x <= i; x++)
    cout << "  " << visit[x];
  for (x = i + 1; x < nodes; x++)
    cout << "  -";
  cout << "  : ";
  for (x = 0; x < nodes; x++)
    cout << "  " << dis[x];

  /*main loop         */
  for (i = 1; i < nodes; i++)
  {
    min = 999;

    for (k = 0; k < nodes; k++)
    {
      if (flag[k] == 0 && dis[k] < min) //find min. distance
      {
        min = dis[k];
        mnode = k;
      }
    }
    flag[mnode] = 1;
    visit[i] = mnode;
    for (j = 0; j < nodes; j++)
    {
      if (flag[j] == 0 && cost[mnode][j] != 999)
      {
        if (dis[j] > dis[mnode] + cost[mnode][j])
          dis[j] = dis[mnode] + cost[mnode][j];
      }
    }

    cout << "\n";
    for (x = 0; x <= i; x++)
      cout << "  " << visit[x];
    for (x = i + 1; x < nodes; x++)
      cout << "  -";
    cout << "  : ";
    for (x = 0; x < nodes; x++)
      cout << "  " << dis[x];
  }
}




int main()
{
  graph obj;
  obj.creat_graph();
  obj.display();
  obj.Dijkstra();
}