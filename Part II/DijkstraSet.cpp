#include<bits/stdc++.h>
using namespace std;

//The algorithm to be used most of the times.
//Returns a set of distances from a particular node.
vector<int> dijkstra_of_namit(int u, vector<vector<pair<int, int>>> &nodes)
{
  vector<int> output(nodes.size());
  for(int i = 0; i < nodes.size(); i++)
  {output[i] = -1;}
  bool flags[nodes.size()] = {};
  output[u] = 0; flags[u] = true;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> indexes(nodes.size());
  pq.push(pair<int, int>(0, u));
  while(pq.size())
  {
    pair<int, int> current = pq.top();
    if(!flags[current.second])
    {output[current.second] = current.first; flags[current.second] = true;}
    if(indexes[current.second] == nodes[current.second].size())
    {pq.pop();}
    else
    {
      //Be on the lookout for indexing based vulnerabilities.
      pq.push(pair<int, int>(nodes[current.second][indexes[current.second]].first + current.first,
      nodes[current.second][indexes[current.second]].second));
      indexes[current.second]++;
    }
  }
  return output;
}

//Basic demonstrations.
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
    int u; cin >> u;
    u--;
    vector<int> out = dijkstra_of_namit(u, adjlist);
    for(int val : out)
    {cout << val << " ";}
    cout << endl;
  }
  return 0;
}
