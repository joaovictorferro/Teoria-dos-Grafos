#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef pair<int, int> pii;

int n, m;
vector<pii> graph[1000], mst[1000];

int prim(int node)
{
  bool visited[n];
  memset(visited, false, sizeof(visited));

  visited[node] = true;
  priority_queue<pair<int, pair<int, int>>> pq;

  for (auto v : graph[node])
    pq.push({-v.second, {v.first, node}});

  int mstCost = 0;

  while (!pq.empty())
  {
    int u = pq.top().second.first;
    int prev = pq.top().second.second;
    int c = -pq.top().first;

    pq.pop();

    if (visited[u])
      continue;

    mst[u].push_back({prev, c});
    mst[prev].push_back({u, c});
    mstCost += c;
    visited[u] = true;

    for (auto v : graph[u])
      pq.push({-v.second, {v.first, u}});
  }
  return mstCost;
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

int main(int argc, char *argv[]){

  int src,dest,weight;
  
  ifstream file;
    if(!getFile(argc, argv, file)) {
        exit(0);
    }

    file >> n;
    file >> m;

    while(file >> src && file >> dest && file >> weight) {
      graph[src].push_back({dest, weight});
      graph[dest].push_back({src, weight});
    }
    file.close();
  int mstCost = prim(0);

  cout << mstCost;

  return 0;
}