#include<bits/stdc++.h>
using namespace std;
//An Algorithm for calculating the shortest paths for all pairs of a dense graph.
//The Time Complexity is O(N^3).
void FloydWarshall(vector<vector<int>> &adj)
{
  int n = adj.size();
  for(int k = 0; k < n; k++)
  {
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);}
    }
  }
}

int main()
{
  int n; cin >> n;
  vector<vector<int>> adj(n);
  for(int i = 0; i < n; i++)
  {
    adj[i] = vector<int>(n);
    for(int j = 0; j < n; j++)
    {cin >> adj[i][j];}
  }
  FloydWarshall(adj);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {cout << adj[i][j] << " ";}
    cout << endl;
  }
  return 0;
}
