#include<bits/stdc++.h>
using namespace std;

//This is a basic dijkstra algorithm which only finds the path between 2 nodes.
//You should usually use the DijkstraSet/DijkstraPath instead.
int dijkstra_of_namit(int u, int v, vector<vector<pair<int, int>>> &nodes)
{
  int output = -1;
  priority_queue<int, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> indexes(nodes.size());
  pq.push(pair<int, int>(0, u));
  while(pq.size())
  {
    pair<int, int> current = pq.top();
    if(current.second == v)
    {
      output = (output == -1 || output > current.first?current.first:output);
      pq.pop();
      continue;
    }
    if(indexes[current.second] == nodes[current.second].size())
    {pq.pop();}
    else
    {
      pq.push(pair<int, int>(nodes[current.second][indexes[current.second]].first + current.first,
      nodes[current.second][indexes[current.second]].second));
      indexes[current.second]++;
    }
  }
  return output;
}

int main()
{
  int n, m; cin >> n >> m;
  vector<vector<pair<int, int>>> adjlist(n);
  for(int i = 0; i < m; i++)
  {
    int u, v, weight; cin >> u >> v >> weight;
    u--; v--;
    adjlist[u].push_back(pair<int, int>(weight, v));
    adjlist[v].push_back(pair<int, int>(weight, u));
  }

  int q; cin >> q;
  for(int i = 0; i < q; i++)
  {
    int u, v; cin >> u >> v;
    u--; v--;
    cout << dijkstra_of_namit(u, v, adjlist) << endl;
  }
  return 0;
}
