#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int n, vector<vector<int>> &edges)
{
  vector<int> out;
  int odg[n + 1] = {};
  queue<int> candies;
  vector<vector<int>> inverse(n + 1);
  for(int i = 1; i <= n; i++)
  {
    odg[i] = edges[i].size();
    if(!odg[i])
    candies.push(i);
    for(auto edge : edges[i])
    inverse[edge].push_back(i);
  }
  while(candies.size())
  {
    auto node = candies.front();
    candies.pop();
    out.push_back(node);
    for(auto edge : inverse[node])
    {
      odg[edge]--;
      if(!odg[edge])
      candies.push(edge);
    }
  }
  if(out.size() < n)
  {vector<int> temp(1, -1); return temp;}
  reverse(out.begin(), out.end());
  return out;
}

int main()
{
  int n, m; cin >> n >> m;
  vector<vector<int>> edges(n + 1);
  for(int i = 0; i < m; i++)
  {
    int u, v; cin >> u >> v;
    edges[u].push_back(v);
  }
  //returns a single element '-1' if a cycle exists...
  auto out = topoSort(n, edges);
  for(int i = 0; i < n; i++)
  cout << out[i] << " ";
  cout << "\n";
  return 0;
}
