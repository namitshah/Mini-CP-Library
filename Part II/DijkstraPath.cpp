#include<bits/stdc++.h>
using namespace std;

//Traces the shortest path between 2 nodes.
//Be aware of the order of the edge (u,v may be represented as v,u)
void pathfinder(vector<pair<int, int>> &input, set<tuple<int, int, int>> &output, int index)
{
  if(input[index].first == -1) return;
  output.insert(make_tuple(input[index].second, input[index].first, index));
  return pathfinder(input, output, input[index].first);
}

//The Dijkstra Algorithm. Kind of like a swiss knife, in the sense that it is unnecessarily complicated,
//but still does everything sufficiently well. (Returns both the paths and the distances).
//This code is trash...
//But I am too lazy to write a new one so I'll just keep using this ig.
template<typename T>
pair<vector<int>, vector<pair<int, T>>> dijkstra_of_namit(int u, vector<vector<pair<T, int>>> &nodes)
{
  vector<int> output(nodes.size());
  vector<pair<int, T>> paths(nodes.size());
  for(int i = 0; i < nodes.size(); i++)
  {output[i] = -1;}
  bool flags[nodes.size()] = {};
  output[u] = 0; paths[u] = pair<int, T>(-1, -1); flags[u] = true;
  priority_queue<pair<T, pair<int, pair<int, T>>>, vector<pair<T, pair<int, pair<int, T>>>>, greater<pair<T, pair<int, pair<int, T>>>>> pq;
  vector<int> indexes(nodes.size());
  pq.push(pair<T, pair<int, pair<int, T>>>(0, pair<int, pair<int, T>>(u, pair<int, T>(-1, -1))));
  while(pq.size())
  {
    pair<T, pair<int, pair<int, T>>> currentp = pq.top();
    pair<T, int> current = pair<T, int>(currentp.first, currentp.second.first);
    if(!flags[current.second])
    {
      output[current.second] = current.first; flags[current.second] = true;
      paths[current.second].first = currentp.second.second.first;
      paths[current.second].second = currentp.second.second.second;
    }
    if(indexes[current.second] == nodes[current.second].size())
    {pq.pop();}
    else
    {
      int value = nodes[current.second][indexes[current.second]].first;
      //Index based vulnerability found here!
      pq.push(pair<T, pair<int, pair<int, T>>>(nodes[current.second][indexes[current.second]].first + current.first,
      pair<int, pair<int, T>>(nodes[current.second][indexes[current.second]].second, pair<int, T>(current.second, value))));
      indexes[current.second]++;
    }
  }
  return pair<vector<int>, vector<pair<int, T>>>(output, paths);
}

//A few basic demonstrations.
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
    pair<vector<int>, vector<pair<int, int>>> out = dijkstra_of_namit<int>(u, adjlist);
    for(int val : out.first)
    {cout << val << " ";}
    cout << endl;
    set<tuple<int, int, int>> output;
    pathfinder(out.second, output, n - 1);
    for(auto data : output)
    {cout << get<0>(data) << " " << get<1>(data) << " " << get<2>(data) << endl;}
  }
  return 0;
}
