/*Prims Algorithm*/
/*Input*/

#include <iostream>
#include <string.h>

using namespace std;

class graph
{
private:
  int n;
  char vname[10][10];
  int arr[10][10];
  int visit[10];

public:
  graph();
  void create();
  void display();
  int position(char s[10]);
  void prims();
};

graph::graph()
{
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
    {
      vname[i][j] = NULL;
      arr[i][j] = 999;
      visit[i] = 0;
    }
}

int graph::position(char s[10])
{
  for (int i = 0; i < n; i++)
    if (strcmp(vname[i], s) == 0)
      return i;
  return -1;
}
void graph::create()
{
  char vertex1[10], vertex2[10];
  int weight;
  char ans;
  cout << "Enter total vertex:";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cout << "Enter Vertex name:";
    cin >> vname[i];
  }
  cout << "Time to add weight";
  do
  {
    cout << "\nEnter Vertex1: ";
    cin >> vertex1;
    cout << "Enter Vertex2: ";
    cin >> vertex2;
    int i = position(vertex1);
    int j = position(vertex2);
    if (i != -1 && j != -1)
    {
      cout << "Enter Weight between " << vertex1 << " & " << vertex2 << ": ";
      cin >> weight;
      arr[i][j] = arr[j][i] = weight;
    }
    else
      cout << "Vertex is not present";
    cout << "\nDo you want to add more weight (Y/N):";
    cin >> ans;
  } while (ans == 'y' || ans == 'Y');
} //function

void graph::display()
{
  for (int i = 0; i < n; i++)
  {
    cout << "\n";
    for (int j = 0; j < n; j++)
    {
      cout << "  " << arr[i][j];
    }
  }
}

void graph::prims()
{
  int x, y, i, j, a, count, min, sum;
  char start[10];
  i = 0;
  j = 0;
  count = 1;
  sum = 0;
  cout << "\nEnter starting node: ";
  cin >> start;
  a = position(start);
  visit[a] = 1;
  while (count < n)
  {
    min = arr[i][j];
    for (i = 0; i < n; i++)
    {
      if (visit[i] == 1)
        for (j = 0; j < n; j++)
        {
          if (arr[i][j] < min && visit[j] == 0)
          {
            x = i;
            y = j;
            min = arr[i][j];
          }
        }
    }
    cout << "\nMinimum Weight is: " << min << " between " << vname[x] << " and " << vname[y];
    visit[y] = 1;
    sum = sum + arr[x][y];
    arr[x][y] = 999;
    arr[y][x] = 999;
    count++;
  }
  cout << "\nTotal weight of prims graph is: " << sum;
}

int main()
{
  graph g1;
  g1.create();
  g1.display();
  g1.prims();
}
