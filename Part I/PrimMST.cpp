#include<bits/stdc++.h>
using namespace std;

//An implementation of Prim's algorithm for constructing an MST.
//Very similar to dijkstra in its working.
set<tuple<int, int, int>> prim_of_namit(set<tuple<int, int, int>> edges, int n)
{
  set<tuple<int, int, int>> output;
  vector<vector<tuple<int, int, int>>> elements(n);
  for(auto edge : edges)
  {
    elements[get<1>(edge)].push_back(edge);
    elements[get<2>(edge)].push_back(edge);
  }
  set<tuple<int, int, int>> input;
  for(auto edge : elements[0])
  {input.insert(edge);}

  bool flags[n] = {true};

  while(input.size())
  {
    auto edge = *input.begin();
    int w, u, v;
    w = get<0>(edge);
    u = get<1>(edge);
    v = get<2>(edge);
    if(!flags[u] || !flags[v])
    {
      output.insert(edge);
      if(!flags[v]) u = v;
      for(auto edge : elements[u])
      {input.insert(edge);}
    }
    input.erase(edge);
    flags[u] = flags[v] = true;
  }
  return output;
}

int main()
{
  int n, e; cin >> n >> e;
  set<tuple<int, int, int>> edges;
  for(int i = 0; i < e; i++)
  {
    int u, v, w; cin >> u >> v >> w;
    edges.insert(make_tuple(w, u - 1, v - 1));
  }
  edges = prim_of_namit(edges, n);
  cout << "The Formed MST is:" << endl;
  int sum = 0;
  for(auto edge : edges)
  {
    int w, u, v;
    w = get<0>(edge);
    u = get<1>(edge);
    v = get<2>(edge);
    sum += w;
    cout << u + 1 << " " << v + 1 << " " << w << endl;
  }
  cout << "The Total Cost: " << sum << endl;
  return 0;
}
