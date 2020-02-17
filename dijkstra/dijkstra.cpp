#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef pair<int, int> par;

int distancia[15000];
int processado[15000];

vector<par> vizinhos[15000];

void bfs(int x)
{

  distancia[x] = 0;

  priority_queue<par, vector<par>, greater<par>> fila;
  fila.push(par(distancia[x], x));

  while (true)
  {

    int daVez = -1;

    while (!fila.empty())
    {

      int atual = fila.top().second;
      fila.pop();

      if (!processado[atual])
      {
        daVez = atual;
        break;
      }
    }

    if (daVez == -1)
      return;

    for (int i = 0; i < (int)vizinhos[daVez].size(); i++)
    {

      int dist = vizinhos[daVez][i].first;
      int atual = vizinhos[daVez][i].second;

      if (distancia[atual] > distancia[daVez] + dist)
      {

        distancia[atual] = distancia[daVez] + dist;
        fila.push(par(distancia[atual], atual));
      }
    }
  }
}

bool checkFileExistence(string filename) {
    ifstream f(filename);
    return f.is_open();
}

bool getFile(int argc, char *argv[], ifstream& file) {   
    
    if (argc <= 1) {
        cout << "Incorrect arguments." << endl;
        return false;
    } else if (!checkFileExistence(argv[1])) {
        cout << "File " << argv[1] << " not found." << endl;
        return false;
    }

    file.open(argv[1]);
    return true;
}

int main(int argc, char *argv[])
{

  int t = 1,i;

  int src,dest,weight,V,E;
  ifstream file;
    if(!getFile(argc, argv, file)) {
        exit(0);
    }

    file >> V;
    file >> E;

  for (i = 0; i <= V + 5; i++)
  {
    distancia[i] = INT_MAX;
    processado[i] = 0;
  }

  while(file >> src && file >> dest && file >> weight) {
    vizinhos[src].push_back(par(weight, dest));
    vizinhos[dest].push_back(par(weight, src));
  }
  
  file.close();

  bfs(1);
  
    cout << distancia[V] << endl;

  return 0;
}