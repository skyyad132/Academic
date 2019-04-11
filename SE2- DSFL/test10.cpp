#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

class graph
{
private:
  int n;              // number of vertices
  char vname[10][10]; // representing each vertex with a name
  int arr[10][10];    // adjacency matrix
  int visit[10];      // To know if they are part of different group
  // visit = 0 if not visited
  // to complete the spanning tree, all edges should have equal visit;

public:
  graph();
  void create();
  void display();
  int position(char s[10]);
  void prim();
};


graph::graph()
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      arr[i][j] = 999;
      vname[i][j] = NULL;
    }
    visit[i] = 0;
  }
}


int graph::position(char s[10])
{
  for (int i = 0; i < n; i++)
  {
    if (strcmp(vname[i], s) == 0)
      return i;
  }
  return -1; // not found
}


void graph::create()
{
  char vertex1[10], vertex2[10];
  int weight;
  char ch;
  cout << "Enter total vertex : ";
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cout << "Enter vertex name : ";
    cin >> vname[i];
  }

  cout << "Time to add weight : ";
  do
  {
    cout << "Enter vertex 1 : ";
    cin >> vertex1;
    cout << "Enter vertex 2: ";
    cin >> vertex2;
    int i = position(vertex1);
    int j = position(vertex2);
    if (i != -1 && j != -1)
    {
      cout << "Enter weight between them : ";
      cin >> weight;
      arr[i][j] = arr[j][i] = weight;
    }
    else
    {
      cout << "\nVertex not present\n";
    }

    cout << "Do you want to continue? : ";
    cin >> ch;

  } while (ch == 'y' || ch == 'Y');
}


void graph::display()
{
  cout << left;
  cout << setw(10) << " ";
  for (int i = 0; i < n; i++) 
  {
    cout<<setw(10)<<vname[i];
  }
  for (int i = 0; i < n; i++)
  {
    cout << "\n";
    cout << setw(10) << vname[i];
    for (int j = 0; j < n; j++)
    {
      cout << setw(10) << arr[i][j];
    }
  }
}


void graph::prim()
{
  int x;
  int y;
  int i;
  int j;
  int a;
  int count;
  int min;
  int sum;
  char start[10];
  i = 0;
  j = 0;
  count = 1;
  sum = 0;
  cout << "\nEnter starting node";
  cin >> start;

  a = position(start);

  visit[a] = 1;

  while (count < n)
  {
    min = arr[i][j];
    for (i = 0; i < n; i++)
    {
      if (visit[i] == 1)
      {
        for (j = 0; j < n; j++)
        {
          if (arr[i][j] < min && visit[j] == 0)
          {
            x = i;
            y = j;
            min = arr[i][j];
          }
        }
      }// if
    }// outer for

    cout << "Minimum weight is : " << min << " between " << vname[x] << " & " << vname[y];
    cout<<"\n";
    visit[y] = 1;
    sum = sum + arr[x][y];
    arr[x][y] = 999;
    arr[y][x] = 999;
    count++;
  }// while
  cout << "\nTotal weight of prims graph is: " << sum;
}


int main()
{
  graph g1;
  g1.create();
  g1.display();
  g1.prim();
}