#include <iostream>
#include <string.h>

using namespace std;

class graph
{
  private:
    int n; // number of vertices
    char vname[10][10]; // representing each vertex with a name
    int arr[10][10]; // adjacency matrix
    int visit[10]; // To know if they are part of different group
    // visit = 0 if not visited
    // to complete the spanning tree, all edges should have equal visit;

  public:
    graph();
    void create();
    void display();
    int position(char s[10]);
    void kruskal();
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
  for (int i = 0; i < n; i++)
  {
    cout<<"\n";
    for (int j = 0; j < n; j++)
    {
      cout << "  " << arr[i][j];
    }
  }
}


void graph::kruskal()
{
  int x; // starting vertex of the edge to be chosen
  int y; // ending vertex of the edge to be chosen
  int i;
  int j;
  int min;
  int sum;

  i = 0;
  j = 0;

  sum = 0;

  int flag = 0; // flag means all visited or not. 0 means all not visited
  int group = 1;
  cout << "\nEdge\tEdge\tWeight\tgroup"; // order in which edges are selected to form mst

  while (flag == 0)// while all vertices are not visited
  {
    min = arr[i][j]; // first element as reference to find minimum weight
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        if (arr[i][j] < min)
        {
          x = i;
          y = j;
          min = arr[i][j];
        }
      }// inner for
    }//outer for

    if (visit[x] == 0 && visit[y] == 0) // both vertices of edge with minimum weight are not visited
    {
      visit[x] = visit[y] = group;
      group++;
      sum = sum + arr[x][y];
      arr[x][y] = 999; // to take care that they are not selected again
      arr[y][x] = 999;
      cout << "\n" << vname[x] << "\t" << vname[y] << "\t" << min << "\t" << group;
      // min indicates the current minimum weight of the edge that was selected
    }

    else if (visit[x] != 0 && visit[y] == 0) // x was visited but y wasn't
    {
      visit[y] = visit[x]; // y is a part of group now
      sum = sum + arr[x][y];
      arr[x][y] = 999;
      arr[y][x] = 999;
      cout << "\n" << vname[x] << "\t" << vname[y] << "\t" << min << "\t" << group;
    }

    else if (visit[x] == 0 && visit[y] != 0) // y was visited but x wasn't
    {
      visit[x] = visit[y]; // x is a part of group now
      sum = sum + arr[x][y];
      arr[x][y] = 999;
      arr[y][x] = 999;
      cout << "\n" << vname[x] << "\t" << vname[y] << "\t" << min << "\t" << group;
    }

    else if (visit[x] != visit[y]) 
    // both were visited but one is not part of the same group  
    {
      int temp = visit[y];
      sum = sum + arr[x][y];
      arr[x][y] = 999;
      arr[y][x] = 999;
      cout << "\n" << vname[x] << "\t" << vname[y] << "\t" << min << "\t" << group;
      for (int k = 0; k < n; k++)
      {
        if (visit[k] == temp)
          visit[k] = visit[x];
      }
    }

    int d = visit[0];
    flag = 1;
    for (int l = 0; l < n; l++)
    {
      if (visit[l] != d)
      {
        flag = 0;
        break;
      }
      else
      {
          continue;
      }
    }
  }//while
  cout<<"\nTotal weight of kruskal graph i: " << sum;
}

int main()
{
  graph g1;
  g1.create();
  g1.display();
  g1.kruskal();
}