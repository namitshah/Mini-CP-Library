#include<bits/stdc++.h>
using namespace std;
//This is the solution to the problem CF1611E1 (Escape the Mase - Easy)
void multi_source_bfs(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> &currents,
  vector<int> &distances, vector<vector<int>> &edges, vector<bool> &flags)
{
  while(currents.size())
  {
    auto current = currents.top();
    if(flags[current.second])
    {currents.pop(); continue;}
    flags[current.second] = true;
    distances[current.second] = current.first;
    currents.pop();
    for(int edge : edges[current.second])
    {currents.push({current.first + 1, edge});}
  }
}

void leaffinder(vector<vector<int>> &edges, vector<int> &leaves)
{
  int i = 0;
  for(auto edgeset : edges)
  {
    if(edgeset.size() <= 1)
    {leaves.push_back(i);}
    i++;
  }
}

void processor()
{
  int n, k; cin >> n >> k;
  int friends[k];
  vector<bool> flags(n);
  vector<int> distances(n);
  for(int i = 0; i < k; i++)
  {cin >> friends[i]; friends[i]--; flags[friends[i]] = true;}
  vector<vector<int>> edges(n);
  for(int i = 0; i < n - 1; i++)
  {
    int u, v; cin >> u >> v;
    u--; v--;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> currents;
  for(int friendd : friends)
  {
    for(int edge : edges[friendd])
    {currents.push({0, edge});}
  }
  multi_source_bfs(currents, distances, edges, flags);
  //Now from the first node (where vlad is):
  flags = vector<bool>(n); vector<int> distances1(n); flags[0] = true;
  for(auto edge : edges[0])
  {currents.push({0, edge});}
  bool flag = false;
  multi_source_bfs(currents, distances1, edges, flags);
  vector<int> leaves;
  leaffinder(edges, leaves);
  for(int leaf : leaves)
  {
    if(leaf == 0) continue;
    if(distances[leaf] > distances1[leaf])
    {flag = true; break;}
  }
  cout << (flag?"YES":"NO") << endl;
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int count, counter = 0;
  cin >> count;
  while(counter++ < count)
  {processor();}
  return 0;
}
//Programming isn't about what you know;
//it's about what you can figure out.
